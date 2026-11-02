14057a0e0 4889542410             mov qword ptr [rsp + 0x10], rdx
14057a0e5 48894c2408             mov qword ptr [rsp + 8], rcx
14057a0ea 4881ec78010000         sub rsp, 0x178
14057a0f1 488b05c8701801         mov rax, qword ptr [rip + 0x11870c8]
14057a0f8 4833c4                 xor rax, rsp
14057a0fb 4889842460010000       mov qword ptr [rsp + 0x160], rax
14057a103 41b810000000           mov r8d, 0x10
14057a109 488d942420010000       lea rdx, [rsp + 0x120]
14057a111 488b842488010000       mov rax, qword ptr [rsp + 0x188]
14057a119 8b4834                 mov ecx, dword ptr [rax + 0x34]
14057a11c e8cf020000             call 0x14057a3f0
14057a121 488b842488010000       mov rax, qword ptr [rsp + 0x188]
14057a129 0fb7403e               movzx eax, word ptr [rax + 0x3e]
14057a12d 41b810000000           mov r8d, 0x10
14057a133 488d942440010000       lea rdx, [rsp + 0x140]
14057a13b 8bc8                   mov ecx, eax
14057a13d e85e020000             call 0x14057a3a0
14057a142 488b842488010000       mov rax, qword ptr [rsp + 0x188]
14057a14a 0fb7403c               movzx eax, word ptr [rax + 0x3c]
14057a14e 41b810000000           mov r8d, 0x10
14057a154 488d942450010000       lea rdx, [rsp + 0x150]
14057a15c 8bc8                   mov ecx, eax
14057a15e e83d020000             call 0x14057a3a0
14057a163 41b810000000           mov r8d, 0x10
14057a169 488d942430010000       lea rdx, [rsp + 0x130]
14057a171 488b842488010000       mov rax, qword ptr [rsp + 0x188]
14057a179 8b4838                 mov ecx, dword ptr [rax + 0x38]
14057a17c e86f020000             call 0x14057a3f0
14057a181 90                     nop 
14057a182 488b842480010000       mov rax, qword ptr [rsp + 0x180]
14057a18a 4883c078               add rax, 0x78
14057a18e 4889442470             mov qword ptr [rsp + 0x70], rax
14057a193 488d8424e0000000       lea rax, [rsp + 0xe0]
14057a19b 4889442440             mov qword ptr [rsp + 0x40], rax
14057a1a0 488d842420010000       lea rax, [rsp + 0x120]
14057a1a8 4889442438             mov qword ptr [rsp + 0x38], rax
14057a1ad 488b442438             mov rax, qword ptr [rsp + 0x38]
14057a1b2 488bd0                 mov rdx, rax
14057a1b5 488b4c2440             mov rcx, qword ptr [rsp + 0x40]
14057a1ba e8517fb5ff             call 0x1400d2110
14057a1bf 90                     nop 
14057a1c0 488d842400010000       lea rax, [rsp + 0x100]
14057a1c8 4889442450             mov qword ptr [rsp + 0x50], rax
14057a1cd 488d842430010000       lea rax, [rsp + 0x130]
14057a1d5 4889442448             mov qword ptr [rsp + 0x48], rax
14057a1da 488b442448             mov rax, qword ptr [rsp + 0x48]
14057a1df 488bd0                 mov rdx, rax
14057a1e2 488b4c2450             mov rcx, qword ptr [rsp + 0x50]
14057a1e7 e8247fb5ff             call 0x1400d2110
14057a1ec 90                     nop 
14057a1ed 488d8424e0000000       lea rax, [rsp + 0xe0]
14057a1f5 4889442458             mov qword ptr [rsp + 0x58], rax
14057a1fa 488b442458             mov rax, qword ptr [rsp + 0x58]
14057a1ff 4889442460             mov qword ptr [rsp + 0x60], rax
14057a204 488b442460             mov rax, qword ptr [rsp + 0x60]
14057a209 4889442468             mov qword ptr [rsp + 0x68], rax
14057a20e 4c8b442468             mov r8, qword ptr [rsp + 0x68]
14057a213 488d542430             lea rdx, [rsp + 0x30]
14057a218 488b4c2470             mov rcx, qword ptr [rsp + 0x70]
14057a21d e85e140000             call 0x14057b680
14057a222 90                     nop 
14057a223 488d842400010000       lea rax, [rsp + 0x100]
14057a22b 488bc8                 mov rcx, rax
14057a22e e8ddc2b5ff             call 0x1400d6510
14057a233 90                     nop 
14057a234 488d8424e0000000       lea rax, [rsp + 0xe0]
14057a23c 488bc8                 mov rcx, rax
14057a23f e8ccc2b5ff             call 0x1400d6510
14057a244 90                     nop 
14057a245 488b842480010000       mov rax, qword ptr [rsp + 0x180]
14057a24d 4883c078               add rax, 0x78
14057a251 4889442478             mov qword ptr [rsp + 0x78], rax
14057a256 488b442478             mov rax, qword ptr [rsp + 0x78]
14057a25b 4889842480000000       mov qword ptr [rsp + 0x80], rax
14057a263 488b842480000000       mov rax, qword ptr [rsp + 0x80]
14057a26b 4889842488000000       mov qword ptr [rsp + 0x88], rax
14057a273 488b842488000000       mov rax, qword ptr [rsp + 0x88]
14057a27b 4889842490000000       mov qword ptr [rsp + 0x90], rax
14057a283 488b842490000000       mov rax, qword ptr [rsp + 0x90]
14057a28b 488b00                 mov rax, qword ptr [rax]
14057a28e 4889842498000000       mov qword ptr [rsp + 0x98], rax
14057a296 488b842498000000       mov rax, qword ptr [rsp + 0x98]
14057a29e 48898424a0000000       mov qword ptr [rsp + 0xa0], rax
14057a2a6 488d8424a0000000       lea rax, [rsp + 0xa0]
14057a2ae 48898424a8000000       mov qword ptr [rsp + 0xa8], rax
14057a2b6 488b8424a8000000       mov rax, qword ptr [rsp + 0xa8]
14057a2be 488b00                 mov rax, qword ptr [rax]
14057a2c1 4839442430             cmp qword ptr [rsp + 0x30], rax
14057a2c6 750a                   jne 0x14057a2d2
14057a2c8 c744242401000000       mov dword ptr [rsp + 0x24], 1
14057a2d0 eb08                   jmp 0x14057a2da
14057a2d2 c744242400000000       mov dword ptr [rsp + 0x24], 0
14057a2da 0fb6442424             movzx eax, byte ptr [rsp + 0x24]
14057a2df 88442420               mov byte ptr [rsp + 0x20], al
14057a2e3 0fb6442420             movzx eax, byte ptr [rsp + 0x20]
14057a2e8 0fb6c0                 movzx eax, al
14057a2eb 85c0                   test eax, eax
14057a2ed 750a                   jne 0x14057a2f9
14057a2ef c744242801000000       mov dword ptr [rsp + 0x28], 1
14057a2f7 eb08                   jmp 0x14057a301
14057a2f9 c744242800000000       mov dword ptr [rsp + 0x28], 0
14057a301 0fb6442428             movzx eax, byte ptr [rsp + 0x28]
14057a306 88442421               mov byte ptr [rsp + 0x21], al
14057a30a 0fb6442421             movzx eax, byte ptr [rsp + 0x21]
14057a30f 0fb6c0                 movzx eax, al
14057a312 85c0                   test eax, eax
14057a314 745e                   je 0x14057a374
14057a316 488b442430             mov rax, qword ptr [rsp + 0x30]
14057a31b 4883c020               add rax, 0x20
14057a31f 48898424b0000000       mov qword ptr [rsp + 0xb0], rax
14057a327 488b8424b0000000       mov rax, qword ptr [rsp + 0xb0]
14057a32f 48898424b8000000       mov qword ptr [rsp + 0xb8], rax
14057a337 488b8424b8000000       mov rax, qword ptr [rsp + 0xb8]
14057a33f 48898424c0000000       mov qword ptr [rsp + 0xc0], rax
14057a347 488b8424c0000000       mov rax, qword ptr [rsp + 0xc0]
14057a34f 48898424c8000000       mov qword ptr [rsp + 0xc8], rax
14057a357 488b8424c8000000       mov rax, qword ptr [rsp + 0xc8]
14057a35f 48898424d0000000       mov qword ptr [rsp + 0xd0], rax
14057a367 488b8424d0000000       mov rax, qword ptr [rsp + 0xd0]
14057a36f 8b4040                 mov eax, dword ptr [rax + 0x40]
14057a372 eb02                   jmp 0x14057a376
14057a374 33c0                   xor eax, eax
14057a376 488b8c2460010000       mov rcx, qword ptr [rsp + 0x160]
14057a37e 4833cc                 xor rcx, rsp
14057a381 e87a20b000             call 0x14107c400
14057a386 4881c478010000         add rsp, 0x178
14057a38d c3                     ret 