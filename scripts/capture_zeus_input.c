/* Read-only, non-exclusive IOHID input capture for 3670:0804 only.
 * No SetReport, output report, feature request, or firmware command is used.
 * Build: clang scripts/capture_zeus_input.c -framework IOKit -framework CoreFoundation -o work/patch-toolchain/capture_zeus_input
 * Usage: capture_zeus_input new-output.jsonl seconds
 */
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hid/IOHIDManager.h>
#include <IOKit/hid/IOHIDKeys.h>
#include <fcntl.h>
#include <inttypes.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static FILE *out;
static unsigned long count;
static uint64_t first_ns;
static volatile sig_atomic_t stop_requested;
static void request_stop(int signal_number) { (void)signal_number; stop_requested=1; }
static uint64_t now_ns(void) {
    struct timespec t; clock_gettime(CLOCK_MONOTONIC, &t);
    return (uint64_t)t.tv_sec * 1000000000ull + t.tv_nsec;
}
static void input(void *context, IOReturn result, void *sender,
                  IOHIDReportType type, uint32_t report_id,
                  uint8_t *report, CFIndex length) {
    (void)context; (void)sender;
    fprintf(out, "{\"elapsed_ns\":%" PRIu64 ",\"result\":%d,\"type\":%u,\"report_id\":%u,\"length\":%ld,\"hex\":\"",
            now_ns()-first_ns, result, type, report_id, (long)length);
    for (CFIndex i=0; i<length; i++) fprintf(out, "%02x", report[i]);
    fputs("\"}\n", out); fflush(out); count++;
}
int main(int argc, char **argv) {
    if (argc != 3) { fprintf(stderr,"usage: %s NEW_OUTPUT.jsonl SECONDS\n",argv[0]); return 2; }
    char *end; double seconds=strtod(argv[2], &end);
    if (*end || seconds<1 || seconds>3600) return 2;
    int fd=open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0600);
    if(fd<0) { perror("output"); return 1; }
    out=fdopen(fd,"w");
    IOHIDManagerRef manager=IOHIDManagerCreate(kCFAllocatorDefault,kIOHIDOptionsTypeNone);
    CFMutableDictionaryRef match=CFDictionaryCreateMutable(kCFAllocatorDefault,0,&kCFTypeDictionaryKeyCallBacks,&kCFTypeDictionaryValueCallBacks);
    int vid=0x3670,pid=0x0804;
    CFNumberRef v=CFNumberCreate(0,kCFNumberIntType,&vid),p=CFNumberCreate(0,kCFNumberIntType,&pid);
    CFDictionarySetValue(match,CFSTR(kIOHIDVendorIDKey),v);
    CFDictionarySetValue(match,CFSTR(kIOHIDProductIDKey),p);
    IOHIDManagerSetDeviceMatching(manager,match);
    CFRelease(v);CFRelease(p);CFRelease(match);
    IOHIDManagerScheduleWithRunLoop(manager,CFRunLoopGetCurrent(),kCFRunLoopDefaultMode);
    IOReturn rc=IOHIDManagerOpen(manager,kIOHIDOptionsTypeNone);
    if(rc!=kIOReturnSuccess) { fprintf(stderr,"IOHIDManagerOpen: 0x%x\n",rc); fclose(out);CFRelease(manager);return 1; }
    CFSetRef devices=IOHIDManagerCopyDevices(manager);
    if(!devices || CFSetGetCount(devices)!=1) { fprintf(stderr,"Expected exactly one Zeus device\n"); if(devices)CFRelease(devices);IOHIDManagerClose(manager,0);CFRelease(manager);fclose(out);return 1; }
    IOHIDDeviceRef device; CFSetGetValues(devices,(const void **)&device);
    uint8_t report[1024];
    IOHIDDeviceRegisterInputReportCallback(device,report,sizeof(report),input,NULL);
    first_ns=now_ns();
    signal(SIGINT,request_stop);signal(SIGTERM,request_stop);
    fprintf(out,"{\"event\":\"start\",\"vid\":13936,\"pid\":2052,\"seconds\":%.0f,\"exclusive\":false,\"device_writes\":false,\"start_unix_seconds\":%lld,\"start_monotonic_ns\":%" PRIu64 "}\n",seconds,(long long)time(NULL),first_ns);fflush(out);
    printf("Capturing incoming Zeus reports for %.0f seconds; no device commands.\n",seconds);fflush(stdout);
    double deadline=CFAbsoluteTimeGetCurrent()+seconds;
    while(!stop_requested && CFAbsoluteTimeGetCurrent()<deadline) CFRunLoopRunInMode(kCFRunLoopDefaultMode,0.1,false);
    IOHIDDeviceRegisterInputReportCallback(device,report,sizeof(report),NULL,NULL);
    IOHIDManagerUnscheduleFromRunLoop(manager,CFRunLoopGetCurrent(),kCFRunLoopDefaultMode);
    IOHIDManagerClose(manager,kIOHIDOptionsTypeNone);
    fprintf(out,"{\"event\":\"end\",\"reports\":%lu,\"stopped_early\":%s,\"elapsed_ns\":%" PRIu64 "}\n",count,stop_requested?"true":"false",now_ns()-first_ns);fclose(out);
    CFRelease(devices);CFRelease(manager);
    printf("Saved %lu reports to %s\n",count,argv[1]);
    return 0;
}
