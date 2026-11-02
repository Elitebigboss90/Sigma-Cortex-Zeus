/* One bounded F1 GET_FEATURE, matching the stock updater's status reader.
 * No SET_REPORT, interrupt OUT, update-entry, reset, erase or unlock operation.
 * Admission requires the exact boot-mode HID descriptor observed on this unit.
 * clang scripts/read_sigma_boot_status.c -framework IOKit -framework CoreFoundation -o work/tools/read_sigma_boot_status
 * Usage: read_sigma_boot_status NEW_OUTPUT.json
 */
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hid/IOHIDManager.h>
#include <IOKit/hid/IOHIDKeys.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static const uint8_t expected_descriptor[] = {
    0x05,0x01,0x09,0x04,0xa1,0x01,0x85,0x01,0x75,0x08,0x15,0x00,
    0x26,0xff,0x00,0x35,0x00,0x46,0xff,0x00,0xa1,0x00,0x09,0x33,
    0x09,0x34,0x95,0x02,0x81,0x02,0xc0,0xa1,0x00,0x05,0x09,0x19,
    0x01,0x29,0x28,0x15,0x00,0x25,0x01,0x75,0x01,0x95,0x28,0x81,
    0x02,0xc0,0xa1,0x02,0x06,0x00,0xff,0x85,0xf2,0x75,0x08,0x95,
    0x40,0x09,0xf2,0x91,0x02,0x85,0xf1,0x75,0x08,0x95,0x20,0x09,
    0xf1,0xb1,0x02,0xc0,0xc0
};

static int number(IOHIDDeviceRef device, CFStringRef key) {
    CFTypeRef value=IOHIDDeviceGetProperty(device,key);
    int result=-1;
    if (value && CFGetTypeID(value)==CFNumberGetTypeID())
        CFNumberGetValue((CFNumberRef)value,kCFNumberIntType,&result);
    return result;
}

int main(int argc,char **argv) {
    if(argc!=2) { fprintf(stderr,"usage: %s NEW_OUTPUT.json\n",argv[0]); return 2; }
    int fd=open(argv[1],O_WRONLY|O_CREAT|O_EXCL,0600);
    if(fd<0) { perror("new output"); return 1; }
    FILE *out=fdopen(fd,"w");
    if(!out) { close(fd); return 1; }
    const char *error=NULL;
    int exit_code=1,reads=0;
    IOHIDManagerRef manager=IOHIDManagerCreate(kCFAllocatorDefault,kIOHIDOptionsTypeNone);
    CFSetRef devices=NULL;
    IOReturn open_rc=kIOReturnError,read_rc=kIOReturnError;
    uint8_t report[33]={0xf1};
    CFIndex length=sizeof(report);
    if(!manager) { error="manager_create_failed"; goto done; }
    CFMutableDictionaryRef match=CFDictionaryCreateMutable(kCFAllocatorDefault,0,
        &kCFTypeDictionaryKeyCallBacks,&kCFTypeDictionaryValueCallBacks);
    int vid=0x046d,pid=0xc260;
    CFNumberRef v=CFNumberCreate(NULL,kCFNumberIntType,&vid);
    CFNumberRef p=CFNumberCreate(NULL,kCFNumberIntType,&pid);
    CFDictionarySetValue(match,CFSTR(kIOHIDVendorIDKey),v);
    CFDictionarySetValue(match,CFSTR(kIOHIDProductIDKey),p);
    IOHIDManagerSetDeviceMatching(manager,match);
    CFRelease(v);CFRelease(p);CFRelease(match);
    open_rc=IOHIDManagerOpen(manager,kIOHIDOptionsTypeNone);
    if(open_rc!=kIOReturnSuccess) { error="manager_open_failed"; goto done; }
    devices=IOHIDManagerCopyDevices(manager);
    if(!devices || CFSetGetCount(devices)!=1) { error="expected_exactly_one_device"; goto done; }
    IOHIDDeviceRef device;
    CFSetGetValues(devices,(const void **)&device);
    CFTypeRef descriptor=IOHIDDeviceGetProperty(device,CFSTR(kIOHIDReportDescriptorKey));
    CFTypeRef transport=IOHIDDeviceGetProperty(device,CFSTR(kIOHIDTransportKey));
    if(number(device,CFSTR(kIOHIDVendorIDKey))!=vid ||
       number(device,CFSTR(kIOHIDProductIDKey))!=pid ||
       number(device,CFSTR(kIOHIDVersionNumberKey))!=0x0400 ||
       number(device,CFSTR(kIOHIDMaxFeatureReportSizeKey))!=33 ||
       !transport || !CFEqual(transport,CFSTR("USB")) ||
       !descriptor || CFGetTypeID(descriptor)!=CFDataGetTypeID() ||
       CFDataGetLength((CFDataRef)descriptor)!=sizeof(expected_descriptor) ||
       memcmp(CFDataGetBytePtr((CFDataRef)descriptor),expected_descriptor,sizeof(expected_descriptor))) {
        error="device_or_descriptor_mismatch"; goto done;
    }
    reads=1;
    read_rc=IOHIDDeviceGetReport(device,kIOHIDReportTypeFeature,0xf1,report,&length);
    if(read_rc!=kIOReturnSuccess) { error="get_feature_failed"; goto done; }
    if(length<0 || length>(CFIndex)sizeof(report)) { error="invalid_returned_length"; goto done; }
    exit_code=0;
done:
    fprintf(out,"{\n  \"operation\": \"single_F1_GET_FEATURE\",\n  \"unix_seconds\": %lld,\n",(long long)time(NULL));
    fprintf(out,"  \"vid\": 1133,\n  \"pid\": 49760,\n  \"requested_length\": 33,\n");
    fprintf(out,"  \"exclusive\": false,\n  \"get_feature_calls\": %d,\n  \"set_or_output_report_calls\": 0,\n",reads);
    fprintf(out,"  \"open_result\": \"0x%08x\",\n  \"get_result\": \"0x%08x\",\n",(unsigned)open_rc,(unsigned)read_rc);
    fprintf(out,"  \"reported_length\": %ld,\n  \"response_hex\": ",(long)length);
    if(!exit_code) {
        fputc('"',out);
        for(CFIndex i=0;i<length;i++) fprintf(out,"%02x",report[i]);
        fputs("\",\n",out);
    } else fputs("null,\n",out);
    fprintf(out,"  \"error\": ");
    if(error) fprintf(out,"\"%s\"",error); else fputs("null",out);
    fputs("\n}\n",out); fclose(out);
    if(devices)CFRelease(devices);
    if(manager) { if(open_rc==kIOReturnSuccess)IOHIDManagerClose(manager,kIOHIDOptionsTypeNone); CFRelease(manager); }
    if(error)fprintf(stderr,"%s (open=0x%08x get=0x%08x)\n",error,(unsigned)open_rc,(unsigned)read_rc);
    else puts("Read one boot-mode F1 status report; no SET or output reports sent.");
    return exit_code;
}
