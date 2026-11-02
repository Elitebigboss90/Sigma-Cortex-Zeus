140b7fd10 4489442418             mov dword ptr [rsp + 0x18], r8d
140b7fd15 4889542410             mov qword ptr [rsp + 0x10], rdx
140b7fd1a 48894c2408             mov qword ptr [rsp + 8], rcx
140b7fd1f 4883ec48               sub rsp, 0x48
140b7fd23 488b059614b800         mov rax, qword ptr [rip + 0xb81496]
140b7fd2a 4833c4                 xor rax, rsp
140b7fd2d 4889442438             mov qword ptr [rsp + 0x38], rax
140b7fd32 c744242400000000       mov dword ptr [rsp + 0x24], 0
140b7fd3a c744242010000000       mov dword ptr [rsp + 0x20], 0x10
140b7fd42 eb14                   jmp 0x140b7fd58
140b7fd44 8b442424               mov eax, dword ptr [rsp + 0x24]
140b7fd48 ffc0                   inc eax
140b7fd4a 89442424               mov dword ptr [rsp + 0x24], eax
140b7fd4e 8b442420               mov eax, dword ptr [rsp + 0x20]
140b7fd52 ffc0                   inc eax
140b7fd54 89442420               mov dword ptr [rsp + 0x20], eax
140b7fd58 8b442460               mov eax, dword ptr [rsp + 0x60]
140b7fd5c 39442424               cmp dword ptr [rsp + 0x24], eax
140b7fd60 0f83df000000           jae 0x140b7fe45
140b7fd66 837c242010             cmp dword ptr [rsp + 0x20], 0x10
140b7fd6b 0f85aa000000           jne 0x140b7fe1b
140b7fd71 488b442450             mov rax, qword ptr [rsp + 0x50]
140b7fd76 4805f0000000           add rax, 0xf0
140b7fd7c 41b810000000           mov r8d, 0x10
140b7fd82 488bd0                 mov rdx, rax
140b7fd85 488d4c2428             lea rcx, [rsp + 0x28]
140b7fd8a e820e44f00             call 0x14107e1af
140b7fd8f 488b442450             mov rax, qword ptr [rsp + 0x50]
140b7fd94 488bd0                 mov rdx, rax
140b7fd97 488d4c2428             lea rcx, [rsp + 0x28]
140b7fd9c e87f080000             call 0x140b80620
140b7fda1 90                     nop 
140b7fda2 c74424200f000000       mov dword ptr [rsp + 0x20], 0xf
140b7fdaa eb0a                   jmp 0x140b7fdb6
140b7fdac 8b442420               mov eax, dword ptr [rsp + 0x20]
140b7fdb0 ffc8                   dec eax
140b7fdb2 89442420               mov dword ptr [rsp + 0x20], eax
140b7fdb6 837c242000             cmp dword ptr [rsp + 0x20], 0
140b7fdbb 7c56                   jl 0x140b7fe13
140b7fdbd 4863442420             movsxd rax, dword ptr [rsp + 0x20]
140b7fdc2 488b4c2450             mov rcx, qword ptr [rsp + 0x50]
140b7fdc7 0fb68401f0000000       movzx eax, byte ptr [rcx + rax + 0xf0]
140b7fdcf 3dff000000             cmp eax, 0xff
140b7fdd4 7514                   jne 0x140b7fdea
140b7fdd6 4863442420             movsxd rax, dword ptr [rsp + 0x20]
140b7fddb 488b4c2450             mov rcx, qword ptr [rsp + 0x50]
140b7fde0 c68401f000000000       mov byte ptr [rcx + rax + 0xf0], 0
140b7fde8 ebc2                   jmp 0x140b7fdac
140b7fdea 4863442420             movsxd rax, dword ptr [rsp + 0x20]
140b7fdef 488b4c2450             mov rcx, qword ptr [rsp + 0x50]
140b7fdf4 0fb68401f0000000       movzx eax, byte ptr [rcx + rax + 0xf0]
140b7fdfc ffc0                   inc eax
140b7fdfe 48634c2420             movsxd rcx, dword ptr [rsp + 0x20]
140b7fe03 488b542450             mov rdx, qword ptr [rsp + 0x50]
140b7fe08 88840af0000000         mov byte ptr [rdx + rcx + 0xf0], al
140b7fe0f eb02                   jmp 0x140b7fe13
140b7fe11 eb99                   jmp 0x140b7fdac
140b7fe13 c744242000000000       mov dword ptr [rsp + 0x20], 0
140b7fe1b 8b442424               mov eax, dword ptr [rsp + 0x24]
140b7fe1f 488b4c2458             mov rcx, qword ptr [rsp + 0x58]
140b7fe24 0fb60401               movzx eax, byte ptr [rcx + rax]
140b7fe28 48634c2420             movsxd rcx, dword ptr [rsp + 0x20]
140b7fe2d 0fb64c0c28             movzx ecx, byte ptr [rsp + rcx + 0x28]
140b7fe32 33c1                   xor eax, ecx
140b7fe34 8b4c2424               mov ecx, dword ptr [rsp + 0x24]
140b7fe38 488b542458             mov rdx, qword ptr [rsp + 0x58]
140b7fe3d 88040a                 mov byte ptr [rdx + rcx], al
140b7fe40 e9fffeffff             jmp 0x140b7fd44
140b7fe45 488b4c2438             mov rcx, qword ptr [rsp + 0x38]
140b7fe4a 4833cc                 xor rcx, rsp
140b7fe4d e8aec54f00             call 0x14107c400
140b7fe52 4883c448               add rsp, 0x48
140b7fe56 c3                     ret 