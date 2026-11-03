// Normal report build: three native hubs; no diagnostic report fields.
// ROUTINE construct
push {r4, lr}
bl ORIGINAL_CONSTRUCT
ldr r4, =0x20005604
mov r0, r4
movs r1, #0
movs r2, #12
clear_hubs:
str r1, [r0], #4
subs r2, #1
bne clear_hubs
mov r0, r4
ldr r1, =0x20004488
bl 0x0802bf94
add.w r0, r4, #24
ldr r1, =0x20004488
bl 0x0802bf94
pop {r4, pc}
.balign 4
.ltorg

// ROUTINE hub_init
// Only our two owned objects use bytes 21/22 for parent/physical port.
ldr r12, =0x20005604
cmp r0, r12
blo hub_init_original
add r12, r12, #24
cmp r0, r12
bhi hub_init_original
strb r1, [r0, #21]
strb r2, [r0, #22]
hub_init_original:
b.w 0x0802bc64
.balign 4
.ltorg

// ROUTINE cleanup
push {r4, r5, r6, r7, lr}
sub sp, #4
ldr r0, =0x20004488
bl 0x0802ade0
mov r7, r0
ldr r5, =0x20004500
movs r4, #16
cleanup_loop:
ldr r6, [r5], #4
cbz r6, cleanup_next
mov r0, r6
ldr r3, [r6]
ldr r3, [r3, #16]
blx r3
cbz r0, cleanup_next
mov r1, r0
mov r0, r7
ldr r3, [r7]
ldr r3, [r3]
blx r3
cbnz r0, cleanup_next
mov r0, r6
ldr r3, [r6]
ldr r3, [r3, #8]
blx r3
cleanup_next:
subs r4, #1
bne cleanup_loop
add sp, #4
pop {r4, r5, r6, r7, pc}
.balign 4
.ltorg

// ROUTINE port_event
push {r4, r5, r6, r7, lr}
sub sp, #4
mov r4, r0
mov r5, r1
mov r6, r2
cbz r6, port_original_call
ldr r0, [r6]
ldr r1, =0x00010100
cmp r0, r1
bne port_original_call
ldrb r0, [r4, #14]
and r0, r0, #7
str r0, [sp]
ldr r7, =0x20005604
port_find_hub:
ldrb r0, [r7, #21]
ldr r1, [sp]
cmp r0, r1
bne port_next_hub
ldrb r0, [r7, #22]
cmp r0, r5
bne port_next_hub
ldrb r1, [r7, #14]
cbz r1, port_next_hub
ldr r0, [r4, #4]
bl 0x0802ad40
port_next_hub:
adds r7, #24
ldr r0, =0x20005634
cmp r7, r0
blo port_find_hub
bl CLEANUP_HOOK
port_original_call:
mov r0, r4
mov r1, r5
mov r2, r6
bl port_original
add sp, #4
pop {r4, r5, r6, r7, pc}
port_original:
push {r4, r5, r7, lr}
sub sp, #24
b.w 0x0802baf4
.balign 4
.ltorg

// ROUTINE input
cmp r3, #64
it eq
moveq r3, #23
b.w ORIGINAL_INPUT
.balign 4
.ltorg
