/* Experimental Sigma 1.1.8 USB input adapter. Never writes wheel configuration.
 * Absolute bindings apply ONLY to decoded image SHA-256
 * 6fdef1664030ea9daf965a3b8c0d75e747fd04f3d3572641999bfcc785bb4035.
 * ARMv7-M integer-only AAPCS code; no assumed FPU ABI or C runtime dependencies.
 */
#include <stdint.h>
#include <stddef.h>
#include "../zeus_profile.h"

#define FN(type, address) ((type)(uintptr_t)(address))
#define REG8(address) (*(volatile uint8_t *)(uintptr_t)(address))
#define REG32(address) (*(volatile uint32_t *)(uintptr_t)(address))
#define HOST ((void *)(uintptr_t)0x20004488u)
#define OUTPUT ((volatile uint8_t *)(uintptr_t)0x20004608u)

struct zeus_state {
    uint8_t hid[0x78];
    uint32_t last_tick;
    uint32_t accepted;
    uint32_t ignored;
    uint8_t report[23];
    uint8_t active;
};
_Static_assert(sizeof(struct zeus_state)<=256, "reserved heap slice exceeded");
#define Z ((volatile struct zeus_state *)(uintptr_t)0x20005550u)

typedef void (*void_fn)(void);
typedef void *(*ctor_fn)(void *,void *);
typedef uint8_t (*init_fn)(void *,uint8_t,uint8_t,uint8_t);
typedef uint32_t (*release_fn)(void *);
typedef uint8_t (*poll_fn)(void *);

static uint16_t load16(const uint8_t *p) { return (uint16_t)p[0]|((uint16_t)p[1]<<8); }
static int identity(void *object) {
    const uint8_t *p=(const uint8_t *)object;
    return load16(p+0x70)==0x0804u && load16(p+0x72)==0x3670u;
}
static void clear_controls(void) {
    if(Z->active) { Z->active=0; REG8(0x20000040u)=1; }
    for(unsigned i=0;i<23;i++) Z->report[i]=0;
}
uint32_t zeus_match(void *object,uint16_t vid,uint16_t pid) {
    (void)object; return vid==0x3670u && pid==0x0804u;
}
uint32_t zeus_endpoint(void *object,uint8_t interface_number,uint8_t protocol) {
    (void)protocol;
    /* Supplied and live Zeus descriptors expose interface zero. */
    return identity(object) && interface_number==0;
}
uint32_t zeus_on_init(void *object) {
    (void)object; clear_controls(); Z->last_tick=REG32(0x20002104u); return 0;
}
uint32_t zeus_release(void *object) {
    clear_controls();
    return FN(release_fn,0x08028e51u)(object);
}
uint8_t zeus_init(void *object,uint8_t parent,uint8_t port,uint8_t lowspeed) {
    uint8_t before=((uint8_t *)object)[0x0c];
    uint8_t result=FN(init_fn,0x080289adu)(object,parent,port,lowspeed);
    if(before==0 && (result!=0 || !identity(object))) {
        if(((uint8_t *)object)[0x0c]!=0) zeus_release(object);
        return result ? result : 0xd1u;
    }
    return result;
}
void zeus_input(void *object,void *same_object,uint8_t has_ids,uint8_t length,const uint8_t *report) {
    (void)same_object; (void)has_ids;
    if(!identity(object) || !report || length!=23 || report[0]!=1) { Z->ignored++; return; }
    uint8_t changed=!Z->active;
    for(unsigned i=0;i<23;i++) { changed|=Z->report[i]!=report[i]; Z->report[i]=report[i]; }
    Z->last_tick=REG32(0x20002104u); Z->active=1; Z->accepted++;
    if(changed) REG8(0x20000040u)=1;
}
uint8_t zeus_poll(void *object) {
    uint8_t result=FN(poll_fn,0x08028fb1u)(object);
    if(Z->active && (uint32_t)(REG32(0x20002104u)-Z->last_tick)>ZEUS_TIMEOUT_TICKS) clear_controls();
    return result;
}
static int pressed(unsigned usage) {
    if(usage==0 || usage>120) return 0;
    usage--; return (Z->report[3+usage/8]>>(usage%8))&1;
}
/* Exact generic vtable shape, including secondary-subobject thunk at +0x4c. */
__attribute__((used)) const uintptr_t zeus_vtable[20] = {
    (uintptr_t)zeus_init,0x08029c6du,(uintptr_t)zeus_release,(uintptr_t)zeus_poll,
    0x08028471u,0x08029c51u,(uintptr_t)zeus_match,0x08029c35u,
    0x08029c5du,0x080288b1u,0x08028925u,(uintptr_t)zeus_on_init,
    0x08028efdu,0x08028e7du,0x08028f3du,(uintptr_t)zeus_endpoint,
    (uintptr_t)zeus_input,0xfffffffcu,0,(uintptr_t)0x0802c3e1u
};
void zeus_construct_hook(void) {
    /* Reached by the original final tail branch. Preserve its LR and call
       the last original constructor; host and five original device drivers
       have all been initialized when this call returns. */
    FN(void_fn,0x0802c4f1u)();
    for(unsigned i=0;i<sizeof(*Z);i++) ((volatile uint8_t *)Z)[i]=0;
    FN(ctor_fn,0x0802910du)((void *)Z,HOST);
    *(volatile uintptr_t *)&Z->hid[0]=(uintptr_t)&zeus_vtable[0];
    *(volatile uintptr_t *)&Z->hid[4]=(uintptr_t)&zeus_vtable[19];
}
void zeus_merge_hook(void) {
    FN(void_fn,0x080460c1u)();
    if(!Z->active) return;
    uint32_t bits=0;
    for(unsigned i=0;i<14;i++) if(pressed(zeus_button_usages[i])) bits|=1u<<(4+i);
    for(unsigned i=0;i<2;i++) if(pressed(zeus_center_usages[i])) bits|=1u<<(14+i);
    /* The first four bits of byte5 are the hat. Preserve base buttons and
       unrelated vendor bits, and OR independently held wheel buttons. */
    OUTPUT[5]|=(uint8_t)bits;
    OUTPUT[6]|=(uint8_t)(bits>>8);
    OUTPUT[7]|=(uint8_t)(bits>>16);
    int up=pressed(zeus_hat_usages[0])|pressed(zeus_hat_secondary[0]);
    int right=pressed(zeus_hat_usages[1])|pressed(zeus_hat_secondary[1]);
    int down=pressed(zeus_hat_usages[2])|pressed(zeus_hat_secondary[2]);
    int left=pressed(zeus_hat_usages[3])|pressed(zeus_hat_secondary[3]);
    int x=right-left,y=down-up;
    if(x || y) {
        uint8_t hat= y<0 ? (x<0?7:(x>0?1:0)) : (y>0?(x<0?5:(x>0?3:4)):(x<0?6:2));
        OUTPUT[5]=(OUTPUT[5]&0xf0u)|hat;
    }
#if ZEUS_MAP_AXES
    /* Same Rx/Ry usages as the Zeus descriptor, scaled 0..127 to0..255.
       Steering and separate pedal vendor fields are deliberately untouched. */
    for(unsigned i=0;i<2;i++) {
        unsigned value=Z->report[1+i]; if(value>127) value=127;
        OUTPUT[8+i]=(uint8_t)((value<<1)|(value>>6));
    }
#endif
}
