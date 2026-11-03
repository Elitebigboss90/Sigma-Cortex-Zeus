// Add two native hub instances for Xtend's measured two-hub branch.
// Preserve dev3 controls and 23/64-byte input handling.
// Vendor bytes 56..63 alternate binding/input and USB discovery pages.
// ROUTINE construct
push {r4, lr}
bl ORIGINAL_CONSTRUCT
ldr r0, =0x200055ec
movs r1, #0
movs r2, #18
construct_clear:
str r1, [r0], #4
subs r2, #1
bne construct_clear
subs r0, #72
movs r1, #255
strb r1, [r0]
strb r1, [r0, #16]
ldr r4, =0x20005604
mov r0, r4
ldr r1, =0x20004488
bl 0x0802bf94
add.w r0, r4, #24
ldr r1, =0x20004488
bl 0x0802bf94
pop {r4, pc}
.balign 4
.ltorg

// ROUTINE task
push {r4, lr}
bl 0x0802affc
ldr r0, =0x200055ec
ldr r1, =0x20002104
ldr r1, [r1]
ldr r2, [r0, #4]
subs r2, r1, r2
cmp r2, #100
blo task_done
str r1, [r0, #4]
ldrb r2, [r0, #8]
adds r2, #1
strb r2, [r0, #8]
ldr r0, =0x20000040
movs r1, #1
strb r1, [r0]
task_done:
pop {r4, pc}
.balign 4
.ltorg

// ROUTINE init
push {r4, lr}
bl ORIGINAL_INIT
ldr r1, =0x200055ec
strb r0, [r1]
pop {r4, pc}
.balign 4
.ltorg

// ROUTINE merge
push {r4, lr}
bl ORIGINAL_MERGE
ldr r0, =0x20005550
add.w r4, r0, #156
ldr r1, =0x20004640
movs r2, #90
strb r2, [r1]
ldrb r2, [r4, #8]
and r2, r2, #15
orr r2, r2, #128
strb r2, [r1, #1]
tst r2, #1
bne discovery_page
ldrb r2, [r0, #12]
strb r2, [r1, #2]
ldrb r2, [r0, #57]
strb r2, [r1, #3]
ldrb r2, [r4]
strb r2, [r1, #4]
ldrb r2, [r4, #2]
strb r2, [r1, #5]
ldrb r2, [r0, #124]
strb r2, [r1, #6]
ldrb r2, [r0, #128]
strb r2, [r1, #7]
b merge_done
discovery_page:
ldr r2, =0x20002742
ldrb r2, [r2]
strb r2, [r1, #2]
ldrb r2, [r4, #38]
strb r2, [r1, #3]
ldrb r2, [r4, #62]
strb r2, [r1, #4]
ldrb r2, [r4, #68]
strb r2, [r1, #5]
ldrb r2, [r4, #16]
strb r2, [r1, #6]
ldr r2, =0x20004518
ldr r2, [r2]
cmp r2, r0
ite eq
moveq r2, #1
movne r2, #0
ldr r3, =0x20004520
ldr r3, [r3]
adds r4, #48
cmp r3, r4
it eq
orreq r2, r2, #2
strb r2, [r1, #7]
merge_done:
pop {r4, pc}
.balign 4
.ltorg

// ROUTINE input
strb r3, [r0, #158]
cmp r3, #64
it eq
moveq r3, #23
b.w ORIGINAL_INPUT
.balign 4
.ltorg

// ROUTINE descriptor
push {r4, lr}
bl descriptor_original
ldr r1, =0x200055fc
strb r0, [r1]
pop {r4, pc}
descriptor_original:
push {r7, lr}
sub sp, #48
b.w 0x0802aa3c
.balign 4
.ltorg
