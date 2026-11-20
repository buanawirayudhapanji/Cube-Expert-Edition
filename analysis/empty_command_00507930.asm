
CubeSuite/CubeSuite.exe:     file format pei-i386


Disassembly of section .text:

00507930 <.text+0x106930>:
  507930:	55                   	push   ebp
  507931:	8b ec                	mov    ebp,esp
  507933:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  507936:	66 a1 d0 6a 75 00    	mov    ax,ds:0x756ad0
  50793c:	66 89 01             	mov    WORD PTR [ecx],ax
  50793f:	8a 45 0c             	mov    al,BYTE PTR [ebp+0xc]
  507942:	88 41 02             	mov    BYTE PTR [ecx+0x2],al
  507945:	33 c0                	xor    eax,eax
  507947:	66 89 41 03          	mov    WORD PTR [ecx+0x3],ax
  50794b:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  50794e:	0f b6 45 0a          	movzx  eax,BYTE PTR [ebp+0xa]
  507952:	88 41 05             	mov    BYTE PTR [ecx+0x5],al
  507955:	b8 07 00 00 00       	mov    eax,0x7
  50795a:	c6 41 06 ff          	mov    BYTE PTR [ecx+0x6],0xff
  50795e:	5d                   	pop    ebp
  50795f:	c2 08 00             	ret    0x8
