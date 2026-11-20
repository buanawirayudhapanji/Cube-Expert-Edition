
CubeSuite/CubeSuite.exe:     file format pei-i386


Disassembly of section .text:

005068b0 <.text+0x1058b0>:
  5068b0:	55                   	push   ebp
  5068b1:	8b ec                	mov    ebp,esp
  5068b3:	83 ec 3c             	sub    esp,0x3c
  5068b6:	a1 24 9b 75 00       	mov    eax,ds:0x759b24
  5068bb:	33 c5                	xor    eax,ebp
  5068bd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5068c0:	53                   	push   ebx
  5068c1:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  5068c4:	56                   	push   esi
  5068c5:	57                   	push   edi
  5068c6:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5068c9:	8b f1                	mov    esi,ecx
  5068cb:	6a 11                	push   0x11
  5068cd:	e8 0e 15 00 00       	call   0x507de0
  5068d2:	84 c0                	test   al,al
  5068d4:	0f 84 92 00 00 00    	je     0x50696c
  5068da:	6a 00                	push   0x0
  5068dc:	ff 75 10             	push   DWORD PTR [ebp+0x10]
  5068df:	8d 45 c4             	lea    eax,[ebp-0x3c]
  5068e2:	8b ce                	mov    ecx,esi
  5068e4:	50                   	push   eax
  5068e5:	6a 22                	push   0x22
  5068e7:	8d 45 c8             	lea    eax,[ebp-0x38]
  5068ea:	50                   	push   eax
  5068eb:	6a 11                	push   0x11
  5068ed:	e8 ae 11 00 00       	call   0x507aa0
  5068f2:	84 c0                	test   al,al
  5068f4:	74 76                	je     0x50696c
  5068f6:	83 7f 14 10          	cmp    DWORD PTR [edi+0x14],0x10
  5068fa:	8b c7                	mov    eax,edi
  5068fc:	72 02                	jb     0x506900
  5068fe:	8b 07                	mov    eax,DWORD PTR [edi]
  506900:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  506907:	33 f6                	xor    esi,esi
  506909:	c6 00 00             	mov    BYTE PTR [eax],0x0
  50690c:	0f 1f 40 00          	nop    DWORD PTR [eax+0x0]
  506910:	0f b6 44 35 ce       	movzx  eax,BYTE PTR [ebp+esi*1-0x32]
  506915:	8b cf                	mov    ecx,edi
  506917:	50                   	push   eax
  506918:	e8 83 07 00 00       	call   0x5070a0
  50691d:	46                   	inc    esi
  50691e:	83 fe 10             	cmp    esi,0x10
  506921:	7c ed                	jl     0x506910
  506923:	83 7b 14 10          	cmp    DWORD PTR [ebx+0x14],0x10
  506927:	8b c3                	mov    eax,ebx
  506929:	72 02                	jb     0x50692d
  50692b:	8b 03                	mov    eax,DWORD PTR [ebx]
  50692d:	c7 43 10 00 00 00 00 	mov    DWORD PTR [ebx+0x10],0x0
  506934:	be 08 00 00 00       	mov    esi,0x8
  506939:	c6 00 00             	mov    BYTE PTR [eax],0x0
  50693c:	0f 1f 40 00          	nop    DWORD PTR [eax+0x0]
  506940:	8a 44 35 ce          	mov    al,BYTE PTR [ebp+esi*1-0x32]
  506944:	8b cb                	mov    ecx,ebx
  506946:	04 30                	add    al,0x30
  506948:	0f b6 c0             	movzx  eax,al
  50694b:	50                   	push   eax
  50694c:	e8 4f 07 00 00       	call   0x5070a0
  506951:	46                   	inc    esi
  506952:	83 fe 13             	cmp    esi,0x13
  506955:	7c e9                	jl     0x506940
  506957:	5f                   	pop    edi
  506958:	5e                   	pop    esi
  506959:	b0 01                	mov    al,0x1
  50695b:	5b                   	pop    ebx
  50695c:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  50695f:	33 cd                	xor    ecx,ebp
  506961:	e8 60 2c 01 00       	call   0x5195c6
  506966:	8b e5                	mov    esp,ebp
  506968:	5d                   	pop    ebp
  506969:	c2 0c 00             	ret    0xc
  50696c:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  50696f:	32 c0                	xor    al,al
  506971:	5f                   	pop    edi
  506972:	5e                   	pop    esi
  506973:	33 cd                	xor    ecx,ebp
  506975:	5b                   	pop    ebx
  506976:	e8 4b 2c 01 00       	call   0x5195c6
  50697b:	8b e5                	mov    esp,ebp
  50697d:	5d                   	pop    ebp
  50697e:	c2 0c 00             	ret    0xc
