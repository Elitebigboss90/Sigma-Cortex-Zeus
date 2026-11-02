#!/usr/bin/env python3
"""Publish only the two pinned ZIPs; preserve a receipt readable over Git SSH."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import urllib.error
import urllib.parse
import urllib.request
import zipfile

ROOT = Path(__file__).resolve().parents[2]
CONFIG = json.loads((ROOT / '.github/releases/dev3.json').read_text())
REPO = CONFIG['repository']
API = f'https://api.github.com/repos/{REPO}'


class SafeRedirect(urllib.request.HTTPRedirectHandler):
    def redirect_request(self, req, fp, code, msg, headers, newurl):
        if urllib.parse.urlsplit(newurl).scheme != 'https':
            raise RuntimeError('Non-HTTPS download redirect refused')
        result = super().redirect_request(req, fp, code, msg, headers, newurl)
        if urllib.parse.urlsplit(req.full_url).netloc != urllib.parse.urlsplit(newurl).netloc:
            result.remove_header('Authorization')
        return result


def request(url, method='GET', payload=None, raw=False):
    host = urllib.parse.urlsplit(url).netloc
    assert host in ('api.github.com', 'uploads.github.com')
    headers = {'Authorization': 'Bearer ' + os.environ['GH_TOKEN'],
               'Accept': 'application/octet-stream' if raw else 'application/vnd.github+json',
               'User-Agent': 'sigma-cortex-verified-release',
               'X-GitHub-Api-Version': '2022-11-28'}
    if isinstance(payload, bytes):
        body = payload
        headers['Content-Type'] = 'application/zip'
    elif payload is not None:
        body = json.dumps(payload).encode()
        headers['Content-Type'] = 'application/json'
    else:
        body = None
    req = urllib.request.Request(url, method=method, headers=headers, data=body)
    with urllib.request.build_opener(SafeRedirect()).open(req, timeout=120) as response:
        data = response.read()
    return data if raw else json.loads(data)


def verify_local():
    for asset in CONFIG['assets']:
        path = ROOT / asset['path']
        assert hashlib.sha256(path.read_bytes()).hexdigest() == asset['sha256'], path
        with zipfile.ZipFile(path) as archive:
            assert archive.testzip() is None, path
            assert hashlib.sha256(archive.read(asset['updater_member'])).hexdigest() == asset['updater_sha256'], path
    print('Both ZIPs and their updater members match pinned SHA-256 hashes.', flush=True)


def receipt_branch(receipt):
    # A separate, single-file branch makes the outcome verifiable through the
    # existing SSH Git access; it does not modify main or expose any token.
    tree = request(API + '/git/trees', 'POST', {'tree': [{
        'path': 'receipt.json', 'mode': '100644', 'type': 'blob',
        'content': json.dumps(receipt, indent=2) + '\n'}]})
    commit = request(API + '/git/commits', 'POST', {
        'message': 'Record dev3 release asset verification', 'tree': tree['sha'], 'parents': []})
    branch = 'release-status/' + os.environ['GITHUB_RUN_ID'] + '-' + os.environ['GITHUB_RUN_ATTEMPT']
    request(API + '/git/refs', 'POST', {'ref': 'refs/heads/' + branch, 'sha': commit['sha']})
    print('Release verification receipt: ' + branch, flush=True)


def publish():
    tag = CONFIG['tag']
    try:
        release = request(API + '/releases/tags/' + urllib.parse.quote(tag, safe=''))
        assert release['prerelease'], 'Existing non-prerelease will not be changed'
    except urllib.error.HTTPError as error:
        if error.code != 404:
            raise
        release = request(API + '/releases', 'POST', {
            'tag_name': tag, 'target_commitish': os.environ['GITHUB_SHA'],
            'name': CONFIG['title'], 'body': (ROOT / '.github/releases/dev3-notes.md').read_text(),
            'draft': True, 'prerelease': True, 'make_latest': 'false'})
    existing = {item['name']: item for item in release['assets']}
    verified = []
    for spec in CONFIG['assets']:
        path = ROOT / spec['path']
        asset = existing.get(path.name)
        if asset is None:
            assert release['draft'], 'Refusing to add assets to an already published release'
            upload_url = release['upload_url'].split('{', 1)[0]
            asset = request(upload_url + '?' + urllib.parse.urlencode({'name': path.name}),
                            'POST', path.read_bytes())
        assert asset['state'] == 'uploaded' and asset['size'] == path.stat().st_size
        downloaded = request(asset['url'], raw=True)
        actual = hashlib.sha256(downloaded).hexdigest()
        assert actual == spec['sha256'], 'Remote asset mismatch: ' + path.name
        verified.append({'name': path.name, 'size': len(downloaded), 'sha256': actual,
                         'browser_download_url': asset['browser_download_url']})
    assert len(existing.keys() - {Path(s['path']).name for s in CONFIG['assets']}) == 0, 'Unexpected existing assets'
    if release['draft']:
        release = request(release['url'], 'PATCH', {'draft': False, 'prerelease': True, 'make_latest': 'false'})
    # Draft asset URLs can contain GitHub's temporary untagged identifier.
    # Refresh after publication so the receipt contains stable download URLs.
    release = request(release['url'])
    assert release['draft'] is False and release['prerelease'] is True
    published = {item['name']: item for item in release['assets']}
    for item in verified:
        item['browser_download_url'] = published[item['name']]['browser_download_url']
        assert urllib.parse.urlsplit(item['browser_download_url']).path == (
            f'/{REPO}/releases/download/{tag}/' + item['name'])
    return {'status': 'published-and-download-verified', 'release_url': release['html_url'],
            'tag': tag, 'prerelease': True, 'assets': verified}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--check-only', action='store_true')
    args = parser.parse_args()
    verify_local()
    if args.check_only:
        return
    assert os.environ.get('GITHUB_ACTIONS') == 'true'
    assert os.environ.get('GITHUB_REPOSITORY') == REPO
    receipt = {'source_commit': os.environ['GITHUB_SHA'],
               'workflow_url': f'https://github.com/{REPO}/actions/runs/' + os.environ['GITHUB_RUN_ID']}
    try:
        receipt.update(publish())
    except Exception as error:
        receipt.update({'status': 'failed', 'error_type': type(error).__name__,
                        'error': str(error) if not isinstance(error, urllib.error.HTTPError)
                        else 'GitHub API HTTP ' + str(error.code)})
        receipt_branch(receipt)
        raise
    receipt_branch(receipt)
    print(json.dumps(receipt, indent=2))


if __name__ == '__main__':
    main()
