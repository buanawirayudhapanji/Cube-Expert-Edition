
CubeSuite/CubeSuite.exe:     file format pei-i386


Disassembly of section .text:

00507aa0 <.text+0x106aa0>:
  507aa0:	55                   	push   ebp
  507aa1:	8b ec                	mov    ebp,esp
  507aa3:	51                   	push   ecx
  507aa4:	53                   	push   ebx
  507aa5:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  507aa8:	8b c1                	mov    eax,ecx
  507aaa:	56                   	push   esi
  507aab:	8b 75 0c             	mov    esi,DWORD PTR [ebp+0xc]
  507aae:	57                   	push   edi
  507aaf:	ff 75 18             	push   DWORD PTR [ebp+0x18]
  507ab2:	8b 7d 14             	mov    edi,DWORD PTR [ebp+0x14]
  507ab5:	57                   	push   edi
  507ab6:	53                   	push   ebx
  507ab7:	56                   	push   esi
  507ab8:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  507abb:	e8 00 05 00 00       	call   0x507fc0
  507ac0:	84 c0                	test   al,al
  507ac2:	74 1a                	je     0x507ade
  507ac4:	39 1f                	cmp    DWORD PTR [edi],ebx
  507ac6:	75 16                	jne    0x507ade
  507ac8:	0f b6 46 02          	movzx  eax,BYTE PTR [esi+0x2]
  507acc:	3b 45 08             	cmp    eax,DWORD PTR [ebp+0x8]
  507acf:	74 18                	je     0x507ae9
  507ad1:	68 10 36 59 00       	push   0x593610
  507ad6:	e8 45 f1 f7 ff       	call   0x486c20
  507adb:	83 c4 04             	add    esp,0x4
  507ade:	5f                   	pop    edi
  507adf:	5e                   	pop    esi
  507ae0:	32 c0                	xor    al,al
  507ae2:	5b                   	pop    ebx
  507ae3:	8b e5                	mov    esp,ebp
  507ae5:	5d                   	pop    ebp
  507ae6:	c2 18 00             	ret    0x18
  507ae9:	66 8b 46 03          	mov    ax,WORD PTR [esi+0x3]
  507aed:	c7 45 18 00 00 00 00 	mov    DWORD PTR [ebp+0x18],0x0
  507af4:	66 89 45 18          	mov    WORD PTR [ebp+0x18],ax
  507af8:	8a 46 05             	mov    al,BYTE PTR [esi+0x5]
  507afb:	88 45 1a             	mov    BYTE PTR [ebp+0x1a],al
  507afe:	8b 4d 18             	mov    ecx,DWORD PTR [ebp+0x18]
  507b01:	0f b6 44 31 06       	movzx  eax,BYTE PTR [ecx+esi*1+0x6]
  507b06:	50                   	push   eax
  507b07:	51                   	push   ecx
  507b08:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  507b0b:	8d 46 06             	lea    eax,[esi+0x6]
  507b0e:	50                   	push   eax
  507b0f:	e8 5c fe ff ff       	call   0x507970
  507b14:	84 c0                	test   al,al
  507b16:	74 c6                	je     0x507ade
  507b18:	5f                   	pop    edi
  507b19:	5e                   	pop    esi
  507b1a:	b0 01                	mov    al,0x1
  507b1c:	5b                   	pop    ebx
  507b1d:	8b e5                	mov    esp,ebp
  507b1f:	5d                   	pop    ebp
  507b20:	c2 18 00             	ret    0x18
