140b7fc80 4c89442418             mov qword ptr [rsp + 0x18], r8
140b7fc85 4889542410             mov qword ptr [rsp + 0x10], rdx
140b7fc8a 48894c2408             mov qword ptr [rsp + 8], rcx
140b7fc8f 4883ec28               sub rsp, 0x28
140b7fc93 488b442430             mov rax, qword ptr [rsp + 0x30]
140b7fc98 488b542438             mov rdx, qword ptr [rsp + 0x38]
140b7fc9d 488bc8                 mov rcx, rax
140b7fca0 e82b0a0000             call 0x140b806d0
140b7fca5 488b442430             mov rax, qword ptr [rsp + 0x30]
140b7fcaa 4805f0000000           add rax, 0xf0
140b7fcb0 41b810000000           mov r8d, 0x10
140b7fcb6 488b542440             mov rdx, qword ptr [rsp + 0x40]
140b7fcbb 488bc8                 mov rcx, rax
140b7fcbe e8ece44f00             call 0x14107e1af
140b7fcc3 90                     nop 
140b7fcc4 4883c428               add rsp, 0x28
140b7fcc8 c3                     ret 