#!/usr/bin/env python3
"""Test narrow PRNG hypotheses against a clearly labelled vector-table assumption.

This does not establish that the input is Cortex-M or recover plaintext. Offsets
0x1c..0x2b would be reserved zero vectors only IF this is a Cortex-M image at 0.
"""
import json, struct
from pathlib import Path

src=Path('work/sigma/1.1.5/resources/resource_TEXTFILE_IDR_APP_FILE_1033.bin')
raw=src.read_bytes()
words=struct.unpack_from('<4I',raw,0x1c)
mask=0xffffffff
matches=[]
for directions in [('l','r','l'),('r','l','r')]:
    for a in range(1,32):
        for b in range(1,32):
            for c in range(1,32):
                def step(x):
                    for d,n in zip(directions,(a,b,c)):
                        x=(x ^ (x<<n if d=='l' else x>>n)) & mask
                    return x
                if all(step(x)==y for x,y in zip(words,words[1:])):
                    matches.append([directions,a,b,c])
out={'assumption':'If payload offset zero holds a Cortex-M vector table, words at 0x1c..0x2b are zero plaintext; not established',
     'source':str(src),'assumed_keystream_words':[hex(x) for x in words],
     'xorshift32_3stage_matches':matches,
     'lcg32_impossible_reason':'First difference is even (0x0525ff8a), second odd (0x23018f4b); no constant multiplicative LCG modulo 2^32 can produce this sequence.'}
Path('work/sigma/prng-hypotheses.json').write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps(out,indent=2))
