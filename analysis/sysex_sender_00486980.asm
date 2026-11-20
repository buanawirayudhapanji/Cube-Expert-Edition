
CubeSuite/CubeSuite.exe:     file format pei-i386


Disassembly of section .text:

00486980 <.text+0x85980>:
  486980:	55                   	push   ebp
  486981:	8b ec                	mov    ebp,esp
  486983:	6a ff                	push   0xffffffff
  486985:	68 20 c7 51 00       	push   0x51c720
  48698a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  486990:	50                   	push   eax
  486991:	83 ec 10             	sub    esp,0x10
  486994:	53                   	push   ebx
  486995:	56                   	push   esi
  486996:	57                   	push   edi
  486997:	a1 24 9b 75 00       	mov    eax,ds:0x759b24
  48699c:	33 c5                	xor    eax,ebp
  48699e:	50                   	push   eax
  48699f:	8d 45 f4             	lea    eax,[ebp-0xc]
  4869a2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4869a8:	89 65 f0             	mov    DWORD PTR [ebp-0x10],esp
  4869ab:	8b d9                	mov    ebx,ecx
  4869ad:	89 5d ec             	mov    DWORD PTR [ebp-0x14],ebx
  4869b0:	8b 8b 18 c8 00 00    	mov    ecx,DWORD PTR [ebx+0xc818]
  4869b6:	85 c9                	test   ecx,ecx
  4869b8:	0f 84 f7 00 00 00    	je     0x486ab5
  4869be:	8b 01                	mov    eax,DWORD PTR [ecx]
  4869c0:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  4869c3:	ff d0                	call   eax
  4869c5:	84 c0                	test   al,al
  4869c7:	0f 84 e8 00 00 00    	je     0x486ab5
  4869cd:	c6 03 f0             	mov    BYTE PTR [ebx],0xf0
  4869d0:	8d 73 01             	lea    esi,[ebx+0x1]
  4869d3:	83 bb 14 c8 00 00 00 	cmp    DWORD PTR [ebx+0xc814],0x0
  4869da:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4869e1:	0f 84 9d 00 00 00    	je     0x486a84
  4869e7:	33 c0                	xor    eax,eax
  4869e9:	33 ff                	xor    edi,edi
  4869eb:	33 db                	xor    ebx,ebx
  4869ed:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4869f0:	39 45 0c             	cmp    DWORD PTR [ebp+0xc],eax
  4869f3:	76 60                	jbe    0x486a55
  4869f5:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4869f8:	0f b6 04 08          	movzx  eax,BYTE PTR [eax+ecx*1]
  4869fc:	8b cf                	mov    ecx,edi
  4869fe:	d3 e0                	shl    eax,cl
  486a00:	83 c7 08             	add    edi,0x8
  486a03:	0b d8                	or     ebx,eax
  486a05:	83 ff 07             	cmp    edi,0x7
  486a08:	7c 35                	jl     0x486a3f
  486a0a:	b8 25 49 92 24       	mov    eax,0x24924925
  486a0f:	8b cf                	mov    ecx,edi
  486a11:	f7 e7                	mul    edi
  486a13:	2b ca                	sub    ecx,edx
  486a15:	d1 e9                	shr    ecx,1
  486a17:	03 ca                	add    ecx,edx
  486a19:	c1 e9 02             	shr    ecx,0x2
  486a1c:	8d 04 cd 00 00 00 00 	lea    eax,[ecx*8+0x0]
  486a23:	2b c1                	sub    eax,ecx
  486a25:	f7 d8                	neg    eax
  486a27:	03 f8                	add    edi,eax
  486a29:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [eax+0x0]
  486a30:	8a c3                	mov    al,bl
  486a32:	c1 eb 07             	shr    ebx,0x7
  486a35:	24 7f                	and    al,0x7f
  486a37:	88 06                	mov    BYTE PTR [esi],al
  486a39:	46                   	inc    esi
  486a3a:	83 e9 01             	sub    ecx,0x1
  486a3d:	75 f1                	jne    0x486a30
  486a3f:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  486a42:	40                   	inc    eax
  486a43:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  486a46:	3b 45 0c             	cmp    eax,DWORD PTR [ebp+0xc]
  486a49:	72 aa                	jb     0x4869f5
  486a4b:	85 ff                	test   edi,edi
  486a4d:	74 06                	je     0x486a55
  486a4f:	80 e3 7f             	and    bl,0x7f
  486a52:	88 1e                	mov    BYTE PTR [esi],bl
  486a54:	46                   	inc    esi
  486a55:	8b 5d ec             	mov    ebx,DWORD PTR [ebp-0x14]
  486a58:	c6 06 f7             	mov    BYTE PTR [esi],0xf7
  486a5b:	46                   	inc    esi
  486a5c:	8b 83 18 c8 00 00    	mov    eax,DWORD PTR [ebx+0xc818]
  486a62:	2b f3                	sub    esi,ebx
  486a64:	56                   	push   esi
  486a65:	53                   	push   ebx
  486a66:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  486a69:	8b 01                	mov    eax,DWORD PTR [ecx]
  486a6b:	ff 50 20             	call   DWORD PTR [eax+0x20]
  486a6e:	b0 01                	mov    al,0x1
  486a70:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  486a73:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  486a7a:	59                   	pop    ecx
  486a7b:	5f                   	pop    edi
  486a7c:	5e                   	pop    esi
  486a7d:	5b                   	pop    ebx
  486a7e:	8b e5                	mov    esp,ebp
  486a80:	5d                   	pop    ebp
  486a81:	c2 08 00             	ret    0x8
  486a84:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  486a87:	57                   	push   edi
  486a88:	ff 75 08             	push   DWORD PTR [ebp+0x8]
  486a8b:	56                   	push   esi
  486a8c:	e8 0f 3b 09 00       	call   0x51a5a0
  486a91:	83 c4 0c             	add    esp,0xc
  486a94:	03 f7                	add    esi,edi
  486a96:	eb c0                	jmp    0x486a58
  486a98:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  486a9b:	8b 01                	mov    eax,DWORD PTR [ecx]
  486a9d:	ff 50 10             	call   DWORD PTR [eax+0x10]
  486aa0:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  486aa3:	50                   	push   eax
  486aa4:	8d 89 20 c8 00 00    	lea    ecx,[ecx+0xc820]
  486aaa:	e8 01 f7 ff ff       	call   0x4861b0
  486aaf:	b8 b5 6a 48 00       	mov    eax,0x486ab5
  486ab4:	c3                   	ret
  486ab5:	32 c0                	xor    al,al
  486ab7:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  486aba:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  486ac1:	59                   	pop    ecx
  486ac2:	5f                   	pop    edi
  486ac3:	5e                   	pop    esi
  486ac4:	5b                   	pop    ebx
  486ac5:	8b e5                	mov    esp,ebp
  486ac7:	5d                   	pop    ebp
  486ac8:	c2 08 00             	ret    0x8
