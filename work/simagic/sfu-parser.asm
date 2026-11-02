1405784a0 4889542410             mov qword ptr [rsp + 0x10], rdx
1405784a5 48894c2408             mov qword ptr [rsp + 8], rcx
1405784aa 56                     push rsi
1405784ab 57                     push rdi
1405784ac 4881ec48040000         sub rsp, 0x448
1405784b3 488b05068d1801         mov rax, qword ptr [rip + 0x1188d06]
1405784ba 4833c4                 xor rax, rsp
1405784bd 4889842430040000       mov qword ptr [rsp + 0x430], rax
1405784c5 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405784cd 4883c030               add rax, 0x30
1405784d1 488bd0                 mov rdx, rax
1405784d4 488b8c2468040000       mov rcx, qword ptr [rsp + 0x468]
1405784dc e8dfbac7ff             call 0x1401f3fc0
1405784e1 85c0                   test eax, eax
1405784e3 0f84a1000000           je 0x14057858a
1405784e9 488b8c2468040000       mov rcx, qword ptr [rsp + 0x468]
1405784f1 e87ae7b5ff             call 0x1400d6c70
1405784f6 4889842470010000       mov qword ptr [rsp + 0x170], rax
1405784fe 488d05db07dd00         lea rax, [rip + 0xdd07db]
140578505 4889842478010000       mov qword ptr [rsp + 0x178], rax
14057850d c784248001000078000000 mov dword ptr [rsp + 0x180], 0x78
140578518 488d053108dd00         lea rax, [rip + 0xdd0831]
14057851f 4889842488010000       mov qword ptr [rsp + 0x188], rax
140578527 488d8424f8010000       lea rax, [rsp + 0x1f8]
14057852f 488d8c2478010000       lea rcx, [rsp + 0x178]
140578537 488bf8                 mov rdi, rax
14057853a 488bf1                 mov rsi, rcx
14057853d b918000000             mov ecx, 0x18
140578542 f3a4                   rep movsb byte ptr [rdi], byte ptr [rsi]
140578544 488d842410020000       lea rax, [rsp + 0x210]
14057854c 488d8c24f8010000       lea rcx, [rsp + 0x1f8]
140578554 488bf8                 mov rdi, rax
140578557 488bf1                 mov rsi, rcx
14057855a b918000000             mov ecx, 0x18
14057855f f3a4                   rep movsb byte ptr [rdi], byte ptr [rsi]
140578561 4c8b8c2470010000       mov r9, qword ptr [rsp + 0x170]
140578569 4c8d055807dd00         lea r8, [rip + 0xdd0758]
140578570 488d942410020000       lea rdx, [rsp + 0x210]
140578578 b904000000             mov ecx, 4
14057857d e87e30c5ff             call 0x1401cb600
140578582 90                     nop 
140578583 32c0                   xor al, al
140578585 e9510a0000             jmp 0x140578fdb
14057858a 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578592 4883c050               add rax, 0x50
140578596 488b942468040000       mov rdx, qword ptr [rsp + 0x468]
14057859e 488bc8                 mov rcx, rax
1405785a1 e82a28b6ff             call 0x1400dadd0
1405785a6 90                     nop 
1405785a7 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405785af 488b4040               mov rax, qword ptr [rax + 0x40]
1405785b3 4889442478             mov qword ptr [rsp + 0x78], rax
1405785b8 488b442478             mov rax, qword ptr [rsp + 0x78]
1405785bd 4883f840               cmp rax, 0x40
1405785c1 7367                   jae 0x14057862a
1405785c3 488d05b607dd00         lea rax, [rip + 0xdd07b6]
1405785ca 4889842490010000       mov qword ptr [rsp + 0x190], rax
1405785d2 c784249801000080000000 mov dword ptr [rsp + 0x198], 0x80
1405785dd 488d050c08dd00         lea rax, [rip + 0xdd080c]
1405785e4 48898424a0010000       mov qword ptr [rsp + 0x1a0], rax
1405785ec 488d842430020000       lea rax, [rsp + 0x230]
1405785f4 488d8c2490010000       lea rcx, [rsp + 0x190]
1405785fc 488bf8                 mov rdi, rax
1405785ff 488bf1                 mov rsi, rcx
140578602 b918000000             mov ecx, 0x18
140578607 f3a4                   rep movsb byte ptr [rdi], byte ptr [rsi]
140578609 4c8d055007dd00         lea r8, [rip + 0xdd0750]
140578610 488d942430020000       lea rdx, [rsp + 0x230]
140578618 b904000000             mov ecx, 4
14057861d e8de2fc5ff             call 0x1401cb600
140578622 90                     nop 
140578623 32c0                   xor al, al
140578625 e9b1090000             jmp 0x140578fdb
14057862a 41b840000000           mov r8d, 0x40
140578630 33d2                   xor edx, edx
140578632 488d8c2490020000       lea rcx, [rsp + 0x290]
14057863a e87c5bb000             call 0x14107e1bb
14057863f 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578647 4883c030               add rax, 0x30
14057864b 488bc8                 mov rcx, rax
14057864e e81de6b5ff             call 0x1400d6c70
140578653 41b840000000           mov r8d, 0x40
140578659 488bd0                 mov rdx, rax
14057865c 488d8c2490020000       lea rcx, [rsp + 0x290]
140578664 e8465bb000             call 0x14107e1af
140578669 b801000000             mov eax, 1
14057866e 486bc00d               imul rax, rax, 0xd
140578672 c684049002000000       mov byte ptr [rsp + rax + 0x290], 0
14057867a b801000000             mov eax, 1
14057867f 486bc00f               imul rax, rax, 0xf
140578683 c68404a002000000       mov byte ptr [rsp + rax + 0x2a0], 0
14057868b b801000000             mov eax, 1
140578690 486bc00f               imul rax, rax, 0xf
140578694 c68404b002000000       mov byte ptr [rsp + rax + 0x2b0], 0
14057869c 41b80d000000           mov r8d, 0xd
1405786a2 488d155707dd00         lea rdx, [rip + 0xdd0757]
1405786a9 488d8c2490020000       lea rcx, [rsp + 0x290]
1405786b1 ff1501acd100           call qword ptr [rip + 0xd1ac01]
1405786b7 85c0                   test eax, eax
1405786b9 7467                   je 0x140578722
1405786bb 488d056e07dd00         lea rax, [rip + 0xdd076e]
1405786c2 48898424a8010000       mov qword ptr [rsp + 0x1a8], rax
1405786ca c78424b00100008f000000 mov dword ptr [rsp + 0x1b0], 0x8f
1405786d5 488d05c407dd00         lea rax, [rip + 0xdd07c4]
1405786dc 48898424b8010000       mov qword ptr [rsp + 0x1b8], rax
1405786e4 488d842450020000       lea rax, [rsp + 0x250]
1405786ec 488d8c24a8010000       lea rcx, [rsp + 0x1a8]
1405786f4 488bf8                 mov rdi, rax
1405786f7 488bf1                 mov rsi, rcx
1405786fa b918000000             mov ecx, 0x18
1405786ff f3a4                   rep movsb byte ptr [rdi], byte ptr [rsi]
140578701 4c8d050807dd00         lea r8, [rip + 0xdd0708]
140578708 488d942450020000       lea rdx, [rsp + 0x250]
140578710 b904000000             mov ecx, 4
140578715 e8e62ec5ff             call 0x1401cb600
14057871a 90                     nop 
14057871b 32c0                   xor al, al
14057871d e9b9080000             jmp 0x140578fdb
140578722 488b842460040000       mov rax, qword ptr [rsp + 0x460]
14057872a 488b4040               mov rax, qword ptr [rax + 0x40]
14057872e 4889842480000000       mov qword ptr [rsp + 0x80], rax
140578736 48638424c0020000       movsxd rax, dword ptr [rsp + 0x2c0]
14057873e 488b8c2480000000       mov rcx, qword ptr [rsp + 0x80]
140578746 4883e940               sub rcx, 0x40
14057874a 483bc1                 cmp rax, rcx
14057874d 7607                   jbe 0x140578756
14057874f 32c0                   xor al, al
140578751 e985080000             jmp 0x140578fdb
140578756 488b842460040000       mov rax, qword ptr [rsp + 0x460]
14057875e 488b4040               mov rax, qword ptr [rax + 0x40]
140578762 4889842488000000       mov qword ptr [rsp + 0x88], rax
14057876a 488b842488000000       mov rax, qword ptr [rsp + 0x88]
140578772 488b8c2460040000       mov rcx, qword ptr [rsp + 0x460]
14057877a 894120                 mov dword ptr [rcx + 0x20], eax
14057877d 0fb784249e020000       movzx eax, word ptr [rsp + 0x29e]
140578785 8944242c               mov dword ptr [rsp + 0x2c], eax
140578789 837c242c00             cmp dword ptr [rsp + 0x2c], 0
14057878e 7409                   je 0x140578799
140578790 837c242c40             cmp dword ptr [rsp + 0x2c], 0x40
140578795 7424                   je 0x1405787bb
140578797 eb42                   jmp 0x1405787db
140578799 488d942490020000       lea rdx, [rsp + 0x290]
1405787a1 488b8c2460040000       mov rcx, qword ptr [rsp + 0x460]
1405787a9 e812130000             call 0x140579ac0
1405787ae 488b8c2460040000       mov rcx, qword ptr [rsp + 0x460]
1405787b6 894170                 mov dword ptr [rcx + 0x70], eax
1405787b9 eb20                   jmp 0x1405787db
1405787bb 488d942490020000       lea rdx, [rsp + 0x290]
1405787c3 488b8c2460040000       mov rcx, qword ptr [rsp + 0x460]
1405787cb e810190000             call 0x14057a0e0
1405787d0 488b8c2460040000       mov rcx, qword ptr [rsp + 0x460]
1405787d8 894170                 mov dword ptr [rcx + 0x70], eax
1405787db 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405787e3 83787000               cmp dword ptr [rax + 0x70], 0
1405787e7 7567                   jne 0x140578850
1405787e9 488d05e006dd00         lea rax, [rip + 0xdd06e0]
1405787f0 48898424c0010000       mov qword ptr [rsp + 0x1c0], rax
1405787f8 c78424c8010000a5000000 mov dword ptr [rsp + 0x1c8], 0xa5
140578803 488d053607dd00         lea rax, [rip + 0xdd0736]
14057880a 48898424d0010000       mov qword ptr [rsp + 0x1d0], rax
140578812 488d842470020000       lea rax, [rsp + 0x270]
14057881a 488d8c24c0010000       lea rcx, [rsp + 0x1c0]
140578822 488bf8                 mov rdi, rax
140578825 488bf1                 mov rsi, rcx
140578828 b918000000             mov ecx, 0x18
14057882d f3a4                   rep movsb byte ptr [rdi], byte ptr [rsi]
14057882f 4c8d057a06dd00         lea r8, [rip + 0xdd067a]
140578836 488d942470020000       lea rdx, [rsp + 0x270]
14057883e b904000000             mov ecx, 4
140578843 e8b82dc5ff             call 0x1401cb600
140578848 90                     nop 
140578849 32c0                   xor al, al
14057884b e98b070000             jmp 0x140578fdb
140578850 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578858 c7402440000000         mov dword ptr [rax + 0x24], 0x40
14057885f c644242001             mov byte ptr [rsp + 0x20], 1
140578864 488b842460040000       mov rax, qword ptr [rsp + 0x460]
14057886c 83787018               cmp dword ptr [rax + 0x70], 0x18
140578870 0f849a010000           je 0x140578a10
140578876 488b842460040000       mov rax, qword ptr [rsp + 0x460]
14057887e 83787019               cmp dword ptr [rax + 0x70], 0x19
140578882 0f8488010000           je 0x140578a10
140578888 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578890 8378701a               cmp dword ptr [rax + 0x70], 0x1a
140578894 0f8476010000           je 0x140578a10
14057889a 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405788a2 8378701b               cmp dword ptr [rax + 0x70], 0x1b
1405788a6 0f8464010000           je 0x140578a10
1405788ac 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405788b4 8378701c               cmp dword ptr [rax + 0x70], 0x1c
1405788b8 0f8452010000           je 0x140578a10
1405788be 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405788c6 83787020               cmp dword ptr [rax + 0x70], 0x20
1405788ca 0f8440010000           je 0x140578a10
1405788d0 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405788d8 83787021               cmp dword ptr [rax + 0x70], 0x21
1405788dc 0f842e010000           je 0x140578a10
1405788e2 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405788ea 83787025               cmp dword ptr [rax + 0x70], 0x25
1405788ee 0f841c010000           je 0x140578a10
1405788f4 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405788fc 83787026               cmp dword ptr [rax + 0x70], 0x26
140578900 0f840a010000           je 0x140578a10
140578906 488b842460040000       mov rax, qword ptr [rsp + 0x460]
14057890e 83787027               cmp dword ptr [rax + 0x70], 0x27
140578912 0f84f8000000           je 0x140578a10
140578918 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578920 8378700e               cmp dword ptr [rax + 0x70], 0xe
140578924 0f84e6000000           je 0x140578a10
14057892a 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578932 83787022               cmp dword ptr [rax + 0x70], 0x22
140578936 0f84d4000000           je 0x140578a10
14057893c 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578944 83787028               cmp dword ptr [rax + 0x70], 0x28
140578948 0f84c2000000           je 0x140578a10
14057894e 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578956 8378702e               cmp dword ptr [rax + 0x70], 0x2e
14057895a 0f84b0000000           je 0x140578a10
140578960 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578968 8378702a               cmp dword ptr [rax + 0x70], 0x2a
14057896c 0f849e000000           je 0x140578a10
140578972 488b842460040000       mov rax, qword ptr [rsp + 0x460]
14057897a 8378702b               cmp dword ptr [rax + 0x70], 0x2b
14057897e 0f848c000000           je 0x140578a10
140578984 488b842460040000       mov rax, qword ptr [rsp + 0x460]
14057898c 8378702c               cmp dword ptr [rax + 0x70], 0x2c
140578990 747e                   je 0x140578a10
140578992 488b842460040000       mov rax, qword ptr [rsp + 0x460]
14057899a 8378702d               cmp dword ptr [rax + 0x70], 0x2d
14057899e 7470                   je 0x140578a10
1405789a0 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405789a8 83787029               cmp dword ptr [rax + 0x70], 0x29
1405789ac 7462                   je 0x140578a10
1405789ae 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405789b6 8378702f               cmp dword ptr [rax + 0x70], 0x2f
1405789ba 7454                   je 0x140578a10
1405789bc 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405789c4 83787030               cmp dword ptr [rax + 0x70], 0x30
1405789c8 7446                   je 0x140578a10
1405789ca 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405789d2 83787032               cmp dword ptr [rax + 0x70], 0x32
1405789d6 7438                   je 0x140578a10
1405789d8 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405789e0 8378701f               cmp dword ptr [rax + 0x70], 0x1f
1405789e4 742a                   je 0x140578a10
1405789e6 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405789ee 8378701e               cmp dword ptr [rax + 0x70], 0x1e
1405789f2 741c                   je 0x140578a10
1405789f4 488b842460040000       mov rax, qword ptr [rsp + 0x460]
1405789fc 8378701d               cmp dword ptr [rax + 0x70], 0x1d
140578a00 740e                   je 0x140578a10
140578a02 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578a0a 83787031               cmp dword ptr [rax + 0x70], 0x31
140578a0e 7505                   jne 0x140578a15
140578a10 c644242000             mov byte ptr [rsp + 0x20], 0
140578a15 0fb6442420             movzx eax, byte ptr [rsp + 0x20]
140578a1a 85c0                   test eax, eax
140578a1c 0f84b7050000           je 0x140578fd9
140578a22 c68424f003000020       mov byte ptr [rsp + 0x3f0], 0x20
140578a2a c68424f103000037       mov byte ptr [rsp + 0x3f1], 0x37
140578a32 c68424f2030000df       mov byte ptr [rsp + 0x3f2], 0xdf
140578a3a c68424f303000028       mov byte ptr [rsp + 0x3f3], 0x28
140578a42 c68424f403000088       mov byte ptr [rsp + 0x3f4], 0x88
140578a4a c68424f5030000ab       mov byte ptr [rsp + 0x3f5], 0xab
140578a52 c68424f603000045       mov byte ptr [rsp + 0x3f6], 0x45
140578a5a c68424f7030000f7       mov byte ptr [rsp + 0x3f7], 0xf7
140578a62 c68424f803000084       mov byte ptr [rsp + 0x3f8], 0x84
140578a6a c68424f903000011       mov byte ptr [rsp + 0x3f9], 0x11
140578a72 c68424fa03000078       mov byte ptr [rsp + 0x3fa], 0x78
140578a7a c68424fb030000e2       mov byte ptr [rsp + 0x3fb], 0xe2
140578a82 c68424fc0300005d       mov byte ptr [rsp + 0x3fc], 0x5d
140578a8a c68424fd03000025       mov byte ptr [rsp + 0x3fd], 0x25
140578a92 c68424fe03000099       mov byte ptr [rsp + 0x3fe], 0x99
140578a9a c68424ff0300008c       mov byte ptr [rsp + 0x3ff], 0x8c
140578aa2 c684240004000099       mov byte ptr [rsp + 0x400], 0x99
140578aaa c6842401040000aa       mov byte ptr [rsp + 0x401], 0xaa
140578ab2 c684240204000034       mov byte ptr [rsp + 0x402], 0x34
140578aba c684240304000077       mov byte ptr [rsp + 0x403], 0x77
140578ac2 c684240404000043       mov byte ptr [rsp + 0x404], 0x43
140578aca c684240504000083       mov byte ptr [rsp + 0x405], 0x83
140578ad2 c6842406040000ee       mov byte ptr [rsp + 0x406], 0xee
140578ada c684240704000092       mov byte ptr [rsp + 0x407], 0x92
140578ae2 c684240804000022       mov byte ptr [rsp + 0x408], 0x22
140578aea c684240904000034       mov byte ptr [rsp + 0x409], 0x34
140578af2 c684240a04000012       mov byte ptr [rsp + 0x40a], 0x12
140578afa c684240b04000098       mov byte ptr [rsp + 0x40b], 0x98
140578b02 c684240c04000033       mov byte ptr [rsp + 0x40c], 0x33
140578b0a c684240d04000083       mov byte ptr [rsp + 0x40d], 0x83
140578b12 c684240e04000032       mov byte ptr [rsp + 0x40e], 0x32
140578b1a c684240f04000084       mov byte ptr [rsp + 0x40f], 0x84
140578b22 c68424d003000034       mov byte ptr [rsp + 0x3d0], 0x34
140578b2a c68424d103000034       mov byte ptr [rsp + 0x3d1], 0x34
140578b32 c68424d203000013       mov byte ptr [rsp + 0x3d2], 0x13
140578b3a c68424d303000099       mov byte ptr [rsp + 0x3d3], 0x99
140578b42 c68424d403000012       mov byte ptr [rsp + 0x3d4], 0x12
140578b4a c68424d503000035       mov byte ptr [rsp + 0x3d5], 0x35
140578b52 c68424d6030000dd       mov byte ptr [rsp + 0x3d6], 0xdd
140578b5a c68424d7030000f3       mov byte ptr [rsp + 0x3d7], 0xf3
140578b62 c68424d803000039       mov byte ptr [rsp + 0x3d8], 0x39
140578b6a c68424d903000038       mov byte ptr [rsp + 0x3d9], 0x38
140578b72 c68424da03000099       mov byte ptr [rsp + 0x3da], 0x99
140578b7a c68424db030000a1       mov byte ptr [rsp + 0x3db], 0xa1
140578b82 c68424dc030000aa       mov byte ptr [rsp + 0x3dc], 0xaa
140578b8a c68424dd03000084       mov byte ptr [rsp + 0x3dd], 0x84
140578b92 c68424de03000032       mov byte ptr [rsp + 0x3de], 0x32
140578b9a c68424df03000099       mov byte ptr [rsp + 0x3df], 0x99
140578ba2 c68424e003000067       mov byte ptr [rsp + 0x3e0], 0x67
140578baa c68424e103000083       mov byte ptr [rsp + 0x3e1], 0x83
140578bb2 c68424e2030000e1       mov byte ptr [rsp + 0x3e2], 0xe1
140578bba c68424e303000077       mov byte ptr [rsp + 0x3e3], 0x77
140578bc2 c68424e403000024       mov byte ptr [rsp + 0x3e4], 0x24
140578bca c68424e503000099       mov byte ptr [rsp + 0x3e5], 0x99
140578bd2 c68424e6030000ae       mov byte ptr [rsp + 0x3e6], 0xae
140578bda c68424e703000011       mov byte ptr [rsp + 0x3e7], 0x11
140578be2 c68424e803000098       mov byte ptr [rsp + 0x3e8], 0x98
140578bea c68424e903000034       mov byte ptr [rsp + 0x3e9], 0x34
140578bf2 c68424ea03000083       mov byte ptr [rsp + 0x3ea], 0x83
140578bfa c68424eb030000f6       mov byte ptr [rsp + 0x3eb], 0xf6
140578c02 c68424ec03000070       mov byte ptr [rsp + 0x3ec], 0x70
140578c0a c68424ed0300005d       mov byte ptr [rsp + 0x3ed], 0x5d
140578c12 c68424ee03000045       mov byte ptr [rsp + 0x3ee], 0x45
140578c1a c68424ef03000077       mov byte ptr [rsp + 0x3ef], 0x77
140578c22 488d842410040000       lea rax, [rsp + 0x410]
140578c2a 488bf8                 mov rdi, rax
140578c2d 33c0                   xor eax, eax
140578c2f b920000000             mov ecx, 0x20
140578c34 f3aa                   rep stosb byte ptr [rdi], al
140578c36 4c8d8424d0030000       lea r8, [rsp + 0x3d0]
140578c3e 488d9424f0030000       lea rdx, [rsp + 0x3f0]
140578c46 488d8c24d0020000       lea rcx, [rsp + 0x2d0]
140578c4e e82d706000             call 0x140b7fc80
140578c53 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578c5b 488b4040               mov rax, qword ptr [rax + 0x40]
140578c5f 4889842490000000       mov qword ptr [rsp + 0x90], rax
140578c67 488b842490000000       mov rax, qword ptr [rsp + 0x90]
140578c6f 4883e840               sub rax, 0x40
140578c73 89442434               mov dword ptr [rsp + 0x34], eax
140578c77 488d442428             lea rax, [rsp + 0x28]
140578c7c 4889842498000000       mov qword ptr [rsp + 0x98], rax
140578c84 488b842498000000       mov rax, qword ptr [rsp + 0x98]
140578c8c 48898424d8000000       mov qword ptr [rsp + 0xd8], rax
140578c94 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578c9c 4883c030               add rax, 0x30
140578ca0 48898424a0000000       mov qword ptr [rsp + 0xa0], rax
140578ca8 488d9424f0010000       lea rdx, [rsp + 0x1f0]
140578cb0 488b8c24a0000000       mov rcx, qword ptr [rsp + 0xa0]
140578cb8 e8e335b9ff             call 0x14010c2a0
140578cbd 488b00                 mov rax, qword ptr [rax]
140578cc0 48898424a8000000       mov qword ptr [rsp + 0xa8], rax
140578cc8 488b8424a8000000       mov rax, qword ptr [rsp + 0xa8]
140578cd0 48898424e0000000       mov qword ptr [rsp + 0xe0], rax
140578cd8 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578ce0 4883c030               add rax, 0x30
140578ce4 48898424b0000000       mov qword ptr [rsp + 0xb0], rax
140578cec 488d9424d8010000       lea rdx, [rsp + 0x1d8]
140578cf4 488b8c24b0000000       mov rcx, qword ptr [rsp + 0xb0]
140578cfc e88fe5b8ff             call 0x140107290
140578d01 48898424b8000000       mov qword ptr [rsp + 0xb8], rax
140578d09 488b8424b8000000       mov rax, qword ptr [rsp + 0xb8]
140578d11 488b00                 mov rax, qword ptr [rax]
140578d14 4889442438             mov qword ptr [rsp + 0x38], rax
140578d19 488b442438             mov rax, qword ptr [rsp + 0x38]
140578d1e 4883c040               add rax, 0x40
140578d22 4889442438             mov qword ptr [rsp + 0x38], rax
140578d27 488b442438             mov rax, qword ptr [rsp + 0x38]
140578d2c 48898424c0000000       mov qword ptr [rsp + 0xc0], rax
140578d34 488d8424c0000000       lea rax, [rsp + 0xc0]
140578d3c 48898424c8000000       mov qword ptr [rsp + 0xc8], rax
140578d44 488b8424c8000000       mov rax, qword ptr [rsp + 0xc8]
140578d4c 488b00                 mov rax, qword ptr [rax]
140578d4f 48898424d0000000       mov qword ptr [rsp + 0xd0], rax
140578d57 488b8424d0000000       mov rax, qword ptr [rsp + 0xd0]
140578d5f 48898424e8000000       mov qword ptr [rsp + 0xe8], rax
140578d67 4c8b8c24d8000000       mov r9, qword ptr [rsp + 0xd8]
140578d6f 4c8b8424e0000000       mov r8, qword ptr [rsp + 0xe0]
140578d77 488b9424e8000000       mov rdx, qword ptr [rsp + 0xe8]
140578d7f 488d4c2460             lea rcx, [rsp + 0x60]
140578d84 e8379fe0ff             call 0x140382cc0
140578d89 90                     nop 
140578d8a 33d2                   xor edx, edx
140578d8c 8b442434               mov eax, dword ptr [rsp + 0x34]
140578d90 b920000000             mov ecx, 0x20
140578d95 f7f1                   div ecx
140578d97 8bc2                   mov eax, edx
140578d99 89442430               mov dword ptr [rsp + 0x30], eax
140578d9d 837c243000             cmp dword ptr [rsp + 0x30], 0
140578da2 744c                   je 0x140578df0
140578da4 488d442460             lea rax, [rsp + 0x60]
140578da9 4889442440             mov qword ptr [rsp + 0x40], rax
140578dae 488b442440             mov rax, qword ptr [rsp + 0x40]
140578db3 488b4c2440             mov rcx, qword ptr [rsp + 0x40]
140578db8 488b09                 mov rcx, qword ptr [rcx]
140578dbb 488b4008               mov rax, qword ptr [rax + 8]
140578dbf 482bc1                 sub rax, rcx
140578dc2 48898424f0000000       mov qword ptr [rsp + 0xf0], rax
140578dca 4863442430             movsxd rax, dword ptr [rsp + 0x30]
140578dcf 488b8c24f0000000       mov rcx, qword ptr [rsp + 0xf0]
140578dd7 4803c8                 add rcx, rax
140578dda 488bc1                 mov rax, rcx
140578ddd 4c8d442429             lea r8, [rsp + 0x29]
140578de2 488bd0                 mov rdx, rax
140578de5 488d4c2460             lea rcx, [rsp + 0x60]
140578dea e80177dbff             call 0x1403304f0
140578def 90                     nop 
140578df0 c744242400000000       mov dword ptr [rsp + 0x24], 0
140578df8 eb0b                   jmp 0x140578e05
140578dfa 8b442424               mov eax, dword ptr [rsp + 0x24]
140578dfe 83c020                 add eax, 0x20
140578e01 89442424               mov dword ptr [rsp + 0x24], eax
140578e05 8b442434               mov eax, dword ptr [rsp + 0x34]
140578e09 39442424               cmp dword ptr [rsp + 0x24], eax
140578e0d 7359                   jae 0x140578e68
140578e0f 488b442460             mov rax, qword ptr [rsp + 0x60]
140578e14 48898424f8000000       mov qword ptr [rsp + 0xf8], rax
140578e1c 488b8424f8000000       mov rax, qword ptr [rsp + 0xf8]
140578e24 4889842400010000       mov qword ptr [rsp + 0x100], rax
140578e2c 488b842400010000       mov rax, qword ptr [rsp + 0x100]
140578e34 4889842408010000       mov qword ptr [rsp + 0x108], rax
140578e3c 4863442424             movsxd rax, dword ptr [rsp + 0x24]
140578e41 488b8c2408010000       mov rcx, qword ptr [rsp + 0x108]
140578e49 4803c8                 add rcx, rax
140578e4c 488bc1                 mov rax, rcx
140578e4f 41b820000000           mov r8d, 0x20
140578e55 488bd0                 mov rdx, rax
140578e58 488d8c24d0020000       lea rcx, [rsp + 0x2d0]
140578e60 e8ab6e6000             call 0x140b7fd10
140578e65 90                     nop 
140578e66 eb92                   jmp 0x140578dfa
140578e68 488d442460             lea rax, [rsp + 0x60]
140578e6d 4889442448             mov qword ptr [rsp + 0x48], rax
140578e72 488b442448             mov rax, qword ptr [rsp + 0x48]
140578e77 488b4c2448             mov rcx, qword ptr [rsp + 0x48]
140578e7c 488b09                 mov rcx, qword ptr [rcx]
140578e7f 488b4008               mov rax, qword ptr [rax + 8]
140578e83 482bc1                 sub rax, rcx
140578e86 4889842410010000       mov qword ptr [rsp + 0x110], rax
140578e8e 488b842410010000       mov rax, qword ptr [rsp + 0x110]
140578e96 488b8c2460040000       mov rcx, qword ptr [rsp + 0x460]
140578e9e 894120                 mov dword ptr [rcx + 0x20], eax
140578ea1 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578ea9 4883c030               add rax, 0x30
140578ead 33d2                   xor edx, edx
140578eaf 488bc8                 mov rcx, rax
140578eb2 e809c7b8ff             call 0x1401055c0
140578eb7 90                     nop 
140578eb8 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578ec0 4883c030               add rax, 0x30
140578ec4 4889842468010000       mov qword ptr [rsp + 0x168], rax
140578ecc 488d442460             lea rax, [rsp + 0x60]
140578ed1 4889442450             mov qword ptr [rsp + 0x50], rax
140578ed6 488b442450             mov rax, qword ptr [rsp + 0x50]
140578edb 4889842418010000       mov qword ptr [rsp + 0x118], rax
140578ee3 488b842418010000       mov rax, qword ptr [rsp + 0x118]
140578eeb 48898424e0010000       mov qword ptr [rsp + 0x1e0], rax
140578ef3 488b442450             mov rax, qword ptr [rsp + 0x50]
140578ef8 488b4008               mov rax, qword ptr [rax + 8]
140578efc 4889842420010000       mov qword ptr [rsp + 0x120], rax
140578f04 488b842420010000       mov rax, qword ptr [rsp + 0x120]
140578f0c 4889842428010000       mov qword ptr [rsp + 0x128], rax
140578f14 488d842428010000       lea rax, [rsp + 0x128]
140578f1c 4889842430010000       mov qword ptr [rsp + 0x130], rax
140578f24 488b842430010000       mov rax, qword ptr [rsp + 0x130]
140578f2c 488b00                 mov rax, qword ptr [rax]
140578f2f 4889842458010000       mov qword ptr [rsp + 0x158], rax
140578f37 488d442460             lea rax, [rsp + 0x60]
140578f3c 4889442458             mov qword ptr [rsp + 0x58], rax
140578f41 488b442458             mov rax, qword ptr [rsp + 0x58]
140578f46 4889842438010000       mov qword ptr [rsp + 0x138], rax
140578f4e 488b842438010000       mov rax, qword ptr [rsp + 0x138]
140578f56 48898424e8010000       mov qword ptr [rsp + 0x1e8], rax
140578f5e 488b442458             mov rax, qword ptr [rsp + 0x58]
140578f63 488b00                 mov rax, qword ptr [rax]
140578f66 4889842440010000       mov qword ptr [rsp + 0x140], rax
140578f6e 488b842440010000       mov rax, qword ptr [rsp + 0x140]
140578f76 4889842448010000       mov qword ptr [rsp + 0x148], rax
140578f7e 488d842448010000       lea rax, [rsp + 0x148]
140578f86 4889842450010000       mov qword ptr [rsp + 0x150], rax
140578f8e 488b842450010000       mov rax, qword ptr [rsp + 0x150]
140578f96 488b00                 mov rax, qword ptr [rax]
140578f99 4889842460010000       mov qword ptr [rsp + 0x160], rax
140578fa1 4c8b842458010000       mov r8, qword ptr [rsp + 0x158]
140578fa9 488b942460010000       mov rdx, qword ptr [rsp + 0x160]
140578fb1 488b8c2468010000       mov rcx, qword ptr [rsp + 0x168]
140578fb9 e802210000             call 0x14057b0c0
140578fbe 90                     nop 
140578fbf 488b842460040000       mov rax, qword ptr [rsp + 0x460]
140578fc7 c7402400000000         mov dword ptr [rax + 0x24], 0
140578fce 488d4c2460             lea rcx, [rsp + 0x60]
140578fd3 e8d830b6ff             call 0x1400dc0b0
140578fd8 90                     nop 
140578fd9 b001                   mov al, 1
140578fdb 488b8c2430040000       mov rcx, qword ptr [rsp + 0x430]
140578fe3 4833cc                 xor rcx, rsp
140578fe6 e81534b000             call 0x14107c400
140578feb 4881c448040000         add rsp, 0x448
140578ff2 5f                     pop rdi
140578ff3 5e                     pop rsi
140578ff4 c3                     ret 