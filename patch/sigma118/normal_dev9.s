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

// ROUTINE input
cmp r3, #64
it eq
moveq r3, #23
b.w ORIGINAL_INPUT
.balign 4
.ltorg
