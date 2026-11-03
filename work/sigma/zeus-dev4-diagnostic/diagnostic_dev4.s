// Windows-only diagnostic wrappers around unchanged dev3 routines.
// Each routine has its own literal pool. Build script replaces ORIGINAL_*
// tokens with hash-bound dev3 symbol addresses before assembly.
// Reports overwrite vendor bytes 56..63; this is not a PS5/game build.

// ROUTINE construct
push {r4, lr}
bl ORIGINAL_CONSTRUCT
ldr r0, =0x200055ec
movs r1, #0
str r1, [r0]
str r1, [r0, #4]
str r1, [r0, #8]
movs r1, #255
strb r1, [r0]
pop {r4, pc}
.balign 4
.ltorg

// ROUTINE task
push {r4, lr}
bl 0x0802affc
ldr r0, =0x20005550
ldr r1, =0x20002104
ldr r1, [r1]
ldr r2, [r0, #160]
subs r2, r1, r2
cmp r2, #100
blo task_done
str r1, [r0, #160]
ldrb r2, [r0, #164]
adds r2, #1
strb r2, [r0, #164]
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
ldr r1, =0x20005550
strb r0, [r1, #156]
ldrb r2, [r1, #157]
adds r2, #1
strb r2, [r1, #157]
pop {r4, pc}
.balign 4
.ltorg

// ROUTINE merge
push {r4, lr}
bl ORIGINAL_MERGE
ldr r0, =0x20005550
ldr r1, =0x20004640
movs r2, #90
strb r2, [r1]
ldrb r2, [r0, #164]
and r2, r2, #15
orr r2, r2, #64
strb r2, [r1, #1]
ldrb r2, [r0, #12]
strb r2, [r1, #2]
ldrb r2, [r0, #57]
strb r2, [r1, #3]
ldrb r2, [r0, #156]
strb r2, [r1, #4]
ldrb r2, [r0, #157]
strb r2, [r1, #5]
ldrb r2, [r0, #124]
strb r2, [r1, #6]
ldrb r2, [r0, #128]
strb r2, [r1, #7]
pop {r4, pc}
.balign 4
.ltorg
