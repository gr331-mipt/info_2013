
ells.dll:     формат файла pei-i386


Дизассемблирование раздела .text:

10001000 <.text>:
10001000:	55                   	push   %ebp		 			//начало какой-то функции
10001001:	8b ec                	mov    %esp,%ebp
10001003:	b8 01 00 00 00       	mov    $0x1,%eax
10001008:	5d                   	pop    %ebp
10001009:	c2 0c 00             	ret    $0xc	
				
1000100c:	55                   	push   %ebp
1000100d:	8b ec                	mov    %esp,%ebp
1000100f:	83 ec 10             	sub    $0x10,%esp
10001012:	8d 45 f0             	lea    -0x10(%ebp),%eax
10001015:	50                   	push   %eax
10001016:	ff 15 20 30 00 10    	call   *0x10003020
1000101c:	8b 4d f0             	mov    -0x10(%ebp),%ecx
1000101f:	89 4d f8             	mov    %ecx,-0x8(%ebp)
10001022:	8b 55 f4             	mov    -0xc(%ebp),%edx
10001025:	89 55 fc             	mov    %edx,-0x4(%ebp)
10001028:	8b 45 f8             	mov    -0x8(%ebp),%eax
1000102b:	8b 55 fc             	mov    -0x4(%ebp),%edx
1000102e:	8b e5                	mov    %ebp,%esp
10001030:	5d                   	pop    %ebp
10001031:	c3                   	ret    

10001032:	55                   	push   %ebp
10001033:	8b ec                	mov    %esp,%ebp
10001035:	83 ec 10             	sub    $0x10,%esp
10001038:	56                   	push   %esi
10001039:	57                   	push   %edi
1000103a:	e8 cd ff ff ff       	call   0x1000100c
1000103f:	8b f0                	mov    %eax,%esi
10001041:	8b fa                	mov    %edx,%edi
10001043:	dd 45 08             	fldl   0x8(%ebp)
10001046:	dc 0d 68 30 00 10    	fmull  0x10003068
1000104c:	dc 0d 10 40 00 10    	fmull  0x10004010
10001052:	e8 89 12 00 00       	call   0x100022e0
10001057:	99                   	cltd   
10001058:	03 f0                	add    %eax,%esi
1000105a:	13 fa                	adc    %edx,%edi
1000105c:	89 75 f8             	mov    %esi,-0x8(%ebp)
1000105f:	89 7d fc             	mov    %edi,-0x4(%ebp)
10001062:	e8 a5 ff ff ff       	call   0x1000100c
10001067:	89 45 f0             	mov    %eax,-0x10(%ebp)
1000106a:	89 55 f4             	mov    %edx,-0xc(%ebp)
1000106d:	8b 45 f4             	mov    -0xc(%ebp),%eax
10001070:	3b 45 fc             	cmp    -0x4(%ebp),%eax
10001073:	7f 15                	jg     0x1000108a
10001075:	7c 08                	jl     0x1000107f
10001077:	8b 4d f0             	mov    -0x10(%ebp),%ecx
1000107a:	3b 4d f8             	cmp    -0x8(%ebp),%ecx
1000107d:	73 0b                	jae    0x1000108a
1000107f:	83 3d 24 40 00 10 00 	cmpl   $0x0,0x10004024
10001086:	74 02                	je     0x1000108a
10001088:	eb d8                	jmp    0x10001062
1000108a:	5f                   	pop    %edi
1000108b:	5e                   	pop    %esi
1000108c:	8b e5                	mov    %ebp,%esp
1000108e:	5d                   	pop    %ebp
1000108f:	c3                   	ret    

10001090:	55                   	push   %ebp
10001091:	8b ec                	mov    %esp,%ebp
10001093:	83 ec 64             	sub    $0x64,%esp
10001096:	56                   	push   %esi
10001097:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
1000109b:	74 06                	je     0x100010a3
1000109d:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)
100010a1:	7f 05                	jg     0x100010a8
100010a3:	e9 d3 01 00 00       	jmp    0x1000127b
100010a8:	8a 45 08             	mov    0x8(%ebp),%al
100010ab:	88 45 e8             	mov    %al,-0x18(%ebp)
100010ae:	8b 4d 08             	mov    0x8(%ebp),%ecx
100010b1:	81 e1 ff ff 00 00    	and    $0xffff,%ecx
100010b7:	c1 f9 08             	sar    $0x8,%ecx
100010ba:	88 4d fc             	mov    %cl,-0x4(%ebp)
100010bd:	8b 55 08             	mov    0x8(%ebp),%edx
100010c0:	c1 ea 10             	shr    $0x10,%edx
100010c3:	88 55 f0             	mov    %dl,-0x10(%ebp)
100010c6:	8a 45 0c             	mov    0xc(%ebp),%al
100010c9:	88 45 e4             	mov    %al,-0x1c(%ebp)
100010cc:	8b 4d 0c             	mov    0xc(%ebp),%ecx
100010cf:	81 e1 ff ff 00 00    	and    $0xffff,%ecx
100010d5:	c1 f9 08             	sar    $0x8,%ecx
100010d8:	88 4d f8             	mov    %cl,-0x8(%ebp)
100010db:	8b 55 0c             	mov    0xc(%ebp),%edx
100010de:	c1 ea 10             	shr    $0x10,%edx
100010e1:	88 55 ec             	mov    %dl,-0x14(%ebp)
100010e4:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
100010eb:	eb 09                	jmp    0x100010f6
100010ed:	8b 45 f4             	mov    -0xc(%ebp),%eax
100010f0:	83 c0 01             	add    $0x1,%eax
100010f3:	89 45 f4             	mov    %eax,-0xc(%ebp)
100010f6:	8b 4d f4             	mov    -0xc(%ebp),%ecx
100010f9:	3b 4d 14             	cmp    0x14(%ebp),%ecx
100010fc:	0f 8d 79 01 00 00    	jge    0x1000127b
10001102:	8b 55 e8             	mov    -0x18(%ebp),%edx
10001105:	81 e2 ff 00 00 00    	and    $0xff,%edx
1000110b:	8b 45 e4             	mov    -0x1c(%ebp),%eax
1000110e:	25 ff 00 00 00       	and    $0xff,%eax
10001113:	03 d0                	add    %eax,%edx
10001115:	89 55 e0             	mov    %edx,-0x20(%ebp)
10001118:	db 45 e0             	fildl  -0x20(%ebp)
1000111b:	dc 35 80 30 00 10    	fdivl  0x10003080
10001121:	dd 5d d8             	fstpl  -0x28(%ebp)
10001124:	8b 4d e4             	mov    -0x1c(%ebp),%ecx
10001127:	81 e1 ff 00 00 00    	and    $0xff,%ecx
1000112d:	8b 55 e8             	mov    -0x18(%ebp),%edx
10001130:	81 e2 ff 00 00 00    	and    $0xff,%edx
10001136:	2b ca                	sub    %edx,%ecx
10001138:	89 4d d4             	mov    %ecx,-0x2c(%ebp)
1000113b:	db 45 d4             	fildl  -0x2c(%ebp)
1000113e:	dc 35 80 30 00 10    	fdivl  0x10003080
10001144:	dd 5d cc             	fstpl  -0x34(%ebp)
10001147:	db 45 f4             	fildl  -0xc(%ebp)
1000114a:	dc 0d 78 30 00 10    	fmull  0x10003078
10001150:	da 75 14             	fidivl 0x14(%ebp)
10001153:	83 ec 08             	sub    $0x8,%esp
10001156:	dd 1c 24             	fstpl  (%esp)
10001159:	e8 88 11 00 00       	call   0x100022e6
1000115e:	83 c4 08             	add    $0x8,%esp
10001161:	dc 4d cc             	fmull  -0x34(%ebp)
10001164:	dc 6d d8             	fsubrl -0x28(%ebp)
10001167:	dc 05 70 30 00 10    	faddl  0x10003070
1000116d:	e8 6e 11 00 00       	call   0x100022e0
10001172:	8b f0                	mov    %eax,%esi
10001174:	81 e6 ff 00 00 00    	and    $0xff,%esi
1000117a:	8b 45 fc             	mov    -0x4(%ebp),%eax
1000117d:	25 ff 00 00 00       	and    $0xff,%eax
10001182:	8b 4d f8             	mov    -0x8(%ebp),%ecx
10001185:	81 e1 ff 00 00 00    	and    $0xff,%ecx
1000118b:	03 c1                	add    %ecx,%eax
1000118d:	89 45 c8             	mov    %eax,-0x38(%ebp)
10001190:	db 45 c8             	fildl  -0x38(%ebp)
10001193:	dc 35 80 30 00 10    	fdivl  0x10003080
10001199:	dd 5d c0             	fstpl  -0x40(%ebp)
1000119c:	8b 55 f8             	mov    -0x8(%ebp),%edx
1000119f:	81 e2 ff 00 00 00    	and    $0xff,%edx
100011a5:	8b 45 fc             	mov    -0x4(%ebp),%eax
100011a8:	25 ff 00 00 00       	and    $0xff,%eax
100011ad:	2b d0                	sub    %eax,%edx
100011af:	89 55 bc             	mov    %edx,-0x44(%ebp)
100011b2:	db 45 bc             	fildl  -0x44(%ebp)
100011b5:	dc 35 80 30 00 10    	fdivl  0x10003080
100011bb:	dd 5d b4             	fstpl  -0x4c(%ebp)
100011be:	db 45 f4             	fildl  -0xc(%ebp)
100011c1:	dc 0d 78 30 00 10    	fmull  0x10003078
100011c7:	da 75 14             	fidivl 0x14(%ebp)
100011ca:	83 ec 08             	sub    $0x8,%esp
100011cd:	dd 1c 24             	fstpl  (%esp)
100011d0:	e8 11 11 00 00       	call   0x100022e6
100011d5:	83 c4 08             	add    $0x8,%esp
100011d8:	dc 4d b4             	fmull  -0x4c(%ebp)
100011db:	dc 6d c0             	fsubrl -0x40(%ebp)
100011de:	dc 05 70 30 00 10    	faddl  0x10003070
100011e4:	e8 f7 10 00 00       	call   0x100022e0
100011e9:	25 ff 00 00 00       	and    $0xff,%eax
100011ee:	c1 e0 08             	shl    $0x8,%eax
100011f1:	0b f0                	or     %eax,%esi
100011f3:	8b 4d f0             	mov    -0x10(%ebp),%ecx
100011f6:	81 e1 ff 00 00 00    	and    $0xff,%ecx
100011fc:	8b 55 ec             	mov    -0x14(%ebp),%edx
100011ff:	81 e2 ff 00 00 00    	and    $0xff,%edx
10001205:	03 ca                	add    %edx,%ecx
10001207:	89 4d b0             	mov    %ecx,-0x50(%ebp)
1000120a:	db 45 b0             	fildl  -0x50(%ebp)
1000120d:	dc 35 80 30 00 10    	fdivl  0x10003080
10001213:	dd 5d a8             	fstpl  -0x58(%ebp)
10001216:	8b 45 ec             	mov    -0x14(%ebp),%eax
10001219:	25 ff 00 00 00       	and    $0xff,%eax
1000121e:	8b 4d f0             	mov    -0x10(%ebp),%ecx
10001221:	81 e1 ff 00 00 00    	and    $0xff,%ecx
10001227:	2b c1                	sub    %ecx,%eax
10001229:	89 45 a4             	mov    %eax,-0x5c(%ebp)
1000122c:	db 45 a4             	fildl  -0x5c(%ebp)
1000122f:	dc 35 80 30 00 10    	fdivl  0x10003080
10001235:	dd 5d 9c             	fstpl  -0x64(%ebp)
10001238:	db 45 f4             	fildl  -0xc(%ebp)
1000123b:	dc 0d 78 30 00 10    	fmull  0x10003078
10001241:	da 75 14             	fidivl 0x14(%ebp)
10001244:	83 ec 08             	sub    $0x8,%esp
10001247:	dd 1c 24             	fstpl  (%esp)
1000124a:	e8 97 10 00 00       	call   0x100022e6
1000124f:	83 c4 08             	add    $0x8,%esp
10001252:	dc 4d 9c             	fmull  -0x64(%ebp)
10001255:	dc 6d a8             	fsubrl -0x58(%ebp)
10001258:	dc 05 70 30 00 10    	faddl  0x10003070
1000125e:	e8 7d 10 00 00       	call   0x100022e0
10001263:	25 ff 00 00 00       	and    $0xff,%eax
10001268:	c1 e0 10             	shl    $0x10,%eax
1000126b:	0b f0                	or     %eax,%esi
1000126d:	8b 55 f4             	mov    -0xc(%ebp),%edx
10001270:	8b 45 10             	mov    0x10(%ebp),%eax
10001273:	89 34 90             	mov    %esi,(%eax,%edx,4)
10001276:	e9 72 fe ff ff       	jmp    0x100010ed
1000127b:	5e                   	pop    %esi
1000127c:	8b e5                	mov    %ebp,%esp
1000127e:	5d                   	pop    %ebp
1000127f:	c3                   	ret    
10001280:	55                   	push   %ebp
10001281:	8b ec                	mov    %esp,%ebp
10001283:	83 ec 10             	sub    $0x10,%esp
10001286:	56                   	push   %esi
10001287:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
1000128b:	74 0e                	je     0x1000129b
1000128d:	83 7d 14 00          	cmpl   $0x0,0x14(%ebp)
10001291:	74 08                	je     0x1000129b
10001293:	8b 45 14             	mov    0x14(%ebp),%eax
10001296:	83 38 00             	cmpl   $0x0,(%eax)
10001299:	7f 05                	jg     0x100012a0
1000129b:	e9 fa 00 00 00       	jmp    0x1000139a
100012a0:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
100012a4:	7f 05                	jg     0x100012ab
100012a6:	e9 ef 00 00 00       	jmp    0x1000139a
100012ab:	83 7d 0c 01          	cmpl   $0x1,0xc(%ebp)
100012af:	75 31                	jne    0x100012e2
100012b1:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
100012b8:	eb 09                	jmp    0x100012c3
100012ba:	8b 4d f4             	mov    -0xc(%ebp),%ecx
100012bd:	83 c1 01             	add    $0x1,%ecx
100012c0:	89 4d f4             	mov    %ecx,-0xc(%ebp)
100012c3:	8b 55 14             	mov    0x14(%ebp),%edx
100012c6:	8b 45 f4             	mov    -0xc(%ebp),%eax
100012c9:	3b 02                	cmp    (%edx),%eax
100012cb:	7d 10                	jge    0x100012dd
100012cd:	8b 4d f4             	mov    -0xc(%ebp),%ecx
100012d0:	8b 55 10             	mov    0x10(%ebp),%edx
100012d3:	8b 45 08             	mov    0x8(%ebp),%eax
100012d6:	8b 00                	mov    (%eax),%eax
100012d8:	89 04 8a             	mov    %eax,(%edx,%ecx,4)
100012db:	eb dd                	jmp    0x100012ba
100012dd:	e9 b8 00 00 00       	jmp    0x1000139a
100012e2:	8b 4d 14             	mov    0x14(%ebp),%ecx
100012e5:	8b 01                	mov    (%ecx),%eax
100012e7:	99                   	cltd   
100012e8:	f7 7d 0c             	idivl  0xc(%ebp)
100012eb:	89 45 fc             	mov    %eax,-0x4(%ebp)
100012ee:	8b 55 fc             	mov    -0x4(%ebp),%edx
100012f1:	c1 e2 02             	shl    $0x2,%edx
100012f4:	52                   	push   %edx
100012f5:	ff 15 38 30 00 10    	call   *0x10003038
100012fb:	83 c4 04             	add    $0x4,%esp
100012fe:	89 45 f8             	mov    %eax,-0x8(%ebp)
10001301:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
10001308:	eb 09                	jmp    0x10001313
1000130a:	8b 45 f4             	mov    -0xc(%ebp),%eax
1000130d:	83 c0 01             	add    $0x1,%eax
10001310:	89 45 f4             	mov    %eax,-0xc(%ebp)
10001313:	8b 4d 0c             	mov    0xc(%ebp),%ecx
10001316:	83 e9 01             	sub    $0x1,%ecx
10001319:	39 4d f4             	cmp    %ecx,-0xc(%ebp)
1000131c:	7d 5e                	jge    0x1000137c
1000131e:	8b 55 fc             	mov    -0x4(%ebp),%edx
10001321:	52                   	push   %edx
10001322:	8b 45 f8             	mov    -0x8(%ebp),%eax
10001325:	50                   	push   %eax
10001326:	8b 4d f4             	mov    -0xc(%ebp),%ecx
10001329:	8b 55 08             	mov    0x8(%ebp),%edx
1000132c:	8b 44 8a 04          	mov    0x4(%edx,%ecx,4),%eax
10001330:	50                   	push   %eax
10001331:	8b 4d f4             	mov    -0xc(%ebp),%ecx
10001334:	8b 55 08             	mov    0x8(%ebp),%edx
10001337:	8b 04 8a             	mov    (%edx,%ecx,4),%eax
1000133a:	50                   	push   %eax
1000133b:	e8 50 fd ff ff       	call   0x10001090
10001340:	83 c4 10             	add    $0x10,%esp
10001343:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
1000134a:	eb 09                	jmp    0x10001355
1000134c:	8b 4d f0             	mov    -0x10(%ebp),%ecx
1000134f:	83 c1 01             	add    $0x1,%ecx
10001352:	89 4d f0             	mov    %ecx,-0x10(%ebp)
10001355:	8b 55 f0             	mov    -0x10(%ebp),%edx
10001358:	3b 55 fc             	cmp    -0x4(%ebp),%edx
1000135b:	7d 1d                	jge    0x1000137a
1000135d:	8b 45 f4             	mov    -0xc(%ebp),%eax
10001360:	0f af 45 fc          	imul   -0x4(%ebp),%eax
10001364:	8b 4d f0             	mov    -0x10(%ebp),%ecx
10001367:	03 c8                	add    %eax,%ecx
10001369:	8b 55 10             	mov    0x10(%ebp),%edx
1000136c:	8b 45 f0             	mov    -0x10(%ebp),%eax
1000136f:	8b 75 f8             	mov    -0x8(%ebp),%esi
10001372:	8b 04 86             	mov    (%esi,%eax,4),%eax
10001375:	89 04 8a             	mov    %eax,(%edx,%ecx,4)
10001378:	eb d2                	jmp    0x1000134c
1000137a:	eb 8e                	jmp    0x1000130a
1000137c:	8b 4d f8             	mov    -0x8(%ebp),%ecx
1000137f:	51                   	push   %ecx
10001380:	ff 15 34 30 00 10    	call   *0x10003034
10001386:	83 c4 04             	add    $0x4,%esp
10001389:	8b 55 0c             	mov    0xc(%ebp),%edx
1000138c:	83 ea 01             	sub    $0x1,%edx
1000138f:	8b 45 fc             	mov    -0x4(%ebp),%eax
10001392:	0f af c2             	imul   %edx,%eax
10001395:	8b 4d 14             	mov    0x14(%ebp),%ecx
10001398:	89 01                	mov    %eax,(%ecx)
1000139a:	5e                   	pop    %esi
1000139b:	8b e5                	mov    %ebp,%esp
1000139d:	5d                   	pop    %ebp
1000139e:	c3                   	ret    

1000139f:	55                   	push   %ebp
100013a0:	8b ec                	mov    %esp,%ebp
100013a2:	83 ec 08             	sub    $0x8,%esp
100013a5:	8b 45 10             	mov    0x10(%ebp),%eax
100013a8:	2b 45 14             	sub    0x14(%ebp),%eax
100013ab:	89 45 f8             	mov    %eax,-0x8(%ebp)
100013ae:	eb 09                	jmp    0x100013b9
100013b0:	8b 4d f8             	mov    -0x8(%ebp),%ecx
100013b3:	83 c1 01             	add    $0x1,%ecx
100013b6:	89 4d f8             	mov    %ecx,-0x8(%ebp)
100013b9:	8b 55 10             	mov    0x10(%ebp),%edx
100013bc:	03 55 14             	add    0x14(%ebp),%edx
100013bf:	39 55 f8             	cmp    %edx,-0x8(%ebp)
100013c2:	7f 72                	jg     0x10001436
100013c4:	8b 45 0c             	mov    0xc(%ebp),%eax
100013c7:	2b 45 14             	sub    0x14(%ebp),%eax
100013ca:	89 45 fc             	mov    %eax,-0x4(%ebp)
100013cd:	eb 09                	jmp    0x100013d8
100013cf:	8b 4d fc             	mov    -0x4(%ebp),%ecx
100013d2:	83 c1 01             	add    $0x1,%ecx
100013d5:	89 4d fc             	mov    %ecx,-0x4(%ebp)
100013d8:	8b 55 0c             	mov    0xc(%ebp),%edx
100013db:	03 55 14             	add    0x14(%ebp),%edx
100013de:	39 55 fc             	cmp    %edx,-0x4(%ebp)
100013e1:	7f 4e                	jg     0x10001431
100013e3:	8b 45 fc             	mov    -0x4(%ebp),%eax
100013e6:	2b 45 0c             	sub    0xc(%ebp),%eax
100013e9:	8b 4d fc             	mov    -0x4(%ebp),%ecx
100013ec:	2b 4d 0c             	sub    0xc(%ebp),%ecx
100013ef:	0f af c1             	imul   %ecx,%eax
100013f2:	8b 55 f8             	mov    -0x8(%ebp),%edx
100013f5:	2b 55 10             	sub    0x10(%ebp),%edx
100013f8:	8b 4d f8             	mov    -0x8(%ebp),%ecx
100013fb:	2b 4d 10             	sub    0x10(%ebp),%ecx
100013fe:	0f af d1             	imul   %ecx,%edx
10001401:	03 c2                	add    %edx,%eax
10001403:	8b 55 14             	mov    0x14(%ebp),%edx
10001406:	0f af 55 14          	imul   0x14(%ebp),%edx
1000140a:	3b c2                	cmp    %edx,%eax
1000140c:	7f 21                	jg     0x1000142f
1000140e:	ff 15 3c 30 00 10    	call   *0x1000303c
10001414:	99                   	cltd   
10001415:	b9 a0 86 01 00       	mov    $0x186a0,%ecx
1000141a:	f7 f9                	idiv   %ecx
1000141c:	52                   	push   %edx
1000141d:	8b 55 f8             	mov    -0x8(%ebp),%edx
10001420:	52                   	push   %edx
10001421:	8b 45 fc             	mov    -0x4(%ebp),%eax
10001424:	50                   	push   %eax
10001425:	8b 4d 08             	mov    0x8(%ebp),%ecx
10001428:	51                   	push   %ecx
10001429:	ff 15 14 30 00 10    	call   *0x10003014
1000142f:	eb 9e                	jmp    0x100013cf
10001431:	e9 7a ff ff ff       	jmp    0x100013b0
10001436:	8b e5                	mov    %ebp,%esp
10001438:	5d                   	pop    %ebp
10001439:	c3                   	ret    

1000143a:	55                   	push   %ebp
1000143b:	8b ec                	mov    %esp,%ebp
1000143d:	83 ec 08             	sub    $0x8,%esp
10001440:	56                   	push   %esi
10001441:	68 ff 00 ff 00       	push   $0xff00ff
10001446:	8b 45 14             	mov    0x14(%ebp),%eax
10001449:	99                   	cltd   
1000144a:	b9 0d 00 00 00       	mov    $0xd,%ecx
1000144f:	f7 f9                	idiv   %ecx
10001451:	50                   	push   %eax
10001452:	6a 00                	push   $0x0
10001454:	ff 15 0c 30 00 10    	call   *0x1000300c
1000145a:	89 45 f8             	mov    %eax,-0x8(%ebp)
1000145d:	8b 55 f8             	mov    -0x8(%ebp),%edx
10001460:	52                   	push   %edx
10001461:	8b 45 08             	mov    0x8(%ebp),%eax
10001464:	50                   	push   %eax
10001465:	ff 15 10 30 00 10    	call   *0x10003010
1000146b:	89 45 fc             	mov    %eax,-0x4(%ebp)
1000146e:	8b 4d 10             	mov    0x10(%ebp),%ecx
10001471:	2b 4d 14             	sub    0x14(%ebp),%ecx
10001474:	8b 45 14             	mov    0x14(%ebp),%eax
10001477:	99                   	cltd   
10001478:	be 07 00 00 00       	mov    $0x7,%esi
1000147d:	f7 fe                	idiv   %esi
1000147f:	03 c8                	add    %eax,%ecx
10001481:	51                   	push   %ecx
10001482:	8b 55 0c             	mov    0xc(%ebp),%edx
10001485:	52                   	push   %edx
10001486:	8b 4d 10             	mov    0x10(%ebp),%ecx
10001489:	2b 4d 14             	sub    0x14(%ebp),%ecx
1000148c:	8b 45 14             	mov    0x14(%ebp),%eax
1000148f:	99                   	cltd   
10001490:	be 07 00 00 00       	mov    $0x7,%esi
10001495:	f7 fe                	idiv   %esi
10001497:	03 c8                	add    %eax,%ecx
10001499:	51                   	push   %ecx
1000149a:	8b 55 0c             	mov    0xc(%ebp),%edx
1000149d:	52                   	push   %edx
1000149e:	8b 4d 10             	mov    0x10(%ebp),%ecx
100014a1:	03 4d 14             	add    0x14(%ebp),%ecx
100014a4:	8b 45 14             	mov    0x14(%ebp),%eax
100014a7:	99                   	cltd   
100014a8:	be 07 00 00 00       	mov    $0x7,%esi
100014ad:	f7 fe                	idiv   %esi
100014af:	2b c8                	sub    %eax,%ecx
100014b1:	51                   	push   %ecx
100014b2:	8b 4d 0c             	mov    0xc(%ebp),%ecx
100014b5:	03 4d 14             	add    0x14(%ebp),%ecx
100014b8:	8b 45 14             	mov    0x14(%ebp),%eax
100014bb:	99                   	cltd   
100014bc:	be 07 00 00 00       	mov    $0x7,%esi
100014c1:	f7 fe                	idiv   %esi
100014c3:	2b c8                	sub    %eax,%ecx
100014c5:	51                   	push   %ecx
100014c6:	8b 4d 10             	mov    0x10(%ebp),%ecx
100014c9:	2b 4d 14             	sub    0x14(%ebp),%ecx
100014cc:	8b 45 14             	mov    0x14(%ebp),%eax
100014cf:	99                   	cltd   
100014d0:	be 07 00 00 00       	mov    $0x7,%esi
100014d5:	f7 fe                	idiv   %esi
100014d7:	03 c8                	add    %eax,%ecx
100014d9:	51                   	push   %ecx
100014da:	8b 4d 0c             	mov    0xc(%ebp),%ecx
100014dd:	2b 4d 14             	sub    0x14(%ebp),%ecx
100014e0:	8b 45 14             	mov    0x14(%ebp),%eax
100014e3:	99                   	cltd   
100014e4:	be 07 00 00 00       	mov    $0x7,%esi
100014e9:	f7 fe                	idiv   %esi
100014eb:	03 c8                	add    %eax,%ecx
100014ed:	51                   	push   %ecx
100014ee:	8b 55 08             	mov    0x8(%ebp),%edx
100014f1:	52                   	push   %edx
100014f2:	ff 15 18 30 00 10    	call   *0x10003018
100014f8:	8b 45 fc             	mov    -0x4(%ebp),%eax
100014fb:	50                   	push   %eax
100014fc:	8b 4d 08             	mov    0x8(%ebp),%ecx
100014ff:	51                   	push   %ecx
10001500:	ff 15 10 30 00 10    	call   *0x10003010
10001506:	8b 55 f8             	mov    -0x8(%ebp),%edx
10001509:	52                   	push   %edx
1000150a:	ff 15 00 30 00 10    	call   *0x10003000
10001510:	5e                   	pop    %esi
10001511:	8b e5                	mov    %ebp,%esp
10001513:	5d                   	pop    %ebp
10001514:	c3                   	ret    

10001515:	55                   	push   %ebp
10001516:	8b ec                	mov    %esp,%ebp
10001518:	83 ec 58             	sub    $0x58,%esp
1000151b:	c7 45 dc 00 00 00 00 	movl   $0x0,-0x24(%ebp)
10001522:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%ebp)
10001529:	83 7d 24 01          	cmpl   $0x1,0x24(%ebp)
1000152d:	74 0b                	je     0x1000153a
1000152f:	83 7d 24 ff          	cmpl   $0xffffffff,0x24(%ebp)
10001533:	74 05                	je     0x1000153a
10001535:	e9 70 01 00 00       	jmp    0x100016aa
1000153a:	8b 45 18             	mov    0x18(%ebp),%eax
1000153d:	f7 d8                	neg    %eax
1000153f:	0f af 45 24          	imul   0x24(%ebp),%eax
10001543:	89 45 e0             	mov    %eax,-0x20(%ebp)
10001546:	8b 4d e0             	mov    -0x20(%ebp),%ecx
10001549:	3b 4d 18             	cmp    0x18(%ebp),%ecx
1000154c:	7f 06                	jg     0x10001554
1000154e:	83 7d 24 01          	cmpl   $0x1,0x24(%ebp)
10001552:	74 18                	je     0x1000156c
10001554:	8b 55 18             	mov    0x18(%ebp),%edx
10001557:	f7 da                	neg    %edx
10001559:	39 55 e0             	cmp    %edx,-0x20(%ebp)
1000155c:	0f 8c 48 01 00 00    	jl     0x100016aa
10001562:	83 7d 24 ff          	cmpl   $0xffffffff,0x24(%ebp)
10001566:	0f 85 3e 01 00 00    	jne    0x100016aa
1000156c:	db 45 e0             	fildl  -0x20(%ebp)
1000156f:	dd 5d ec             	fstpl  -0x14(%ebp)
10001572:	db 45 1c             	fildl  0x1c(%ebp)
10001575:	da 75 18             	fidivl 0x18(%ebp)
10001578:	dd 5d cc             	fstpl  -0x34(%ebp)
1000157b:	8b 45 18             	mov    0x18(%ebp),%eax
1000157e:	0f af 45 18          	imul   0x18(%ebp),%eax
10001582:	89 45 c8             	mov    %eax,-0x38(%ebp)
10001585:	db 45 c8             	fildl  -0x38(%ebp)
10001588:	dd 45 ec             	fldl   -0x14(%ebp)
1000158b:	dc 4d ec             	fmull  -0x14(%ebp)
1000158e:	de e9                	fsubrp %st,%st(1)
10001590:	83 ec 08             	sub    $0x8,%esp
10001593:	dd 1c 24             	fstpl  (%esp)
10001596:	e8 57 0d 00 00       	call   0x100022f2
1000159b:	83 c4 08             	add    $0x8,%esp
1000159e:	dc 4d cc             	fmull  -0x34(%ebp)
100015a1:	dd 5d e4             	fstpl  -0x1c(%ebp)
100015a4:	8b 4d 2c             	mov    0x2c(%ebp),%ecx
100015a7:	51                   	push   %ecx
100015a8:	8b 55 28             	mov    0x28(%ebp),%edx
100015ab:	52                   	push   %edx
100015ac:	e8 35 0d 00 00       	call   0x100022e6
100015b1:	83 c4 08             	add    $0x8,%esp
100015b4:	dc 4d ec             	fmull  -0x14(%ebp)
100015b7:	dd 5d c0             	fstpl  -0x40(%ebp)
100015ba:	db 45 24             	fildl  0x24(%ebp)
100015bd:	dc 4d e4             	fmull  -0x1c(%ebp)
100015c0:	dd 5d b8             	fstpl  -0x48(%ebp)
100015c3:	8b 45 2c             	mov    0x2c(%ebp),%eax
100015c6:	50                   	push   %eax
100015c7:	8b 4d 28             	mov    0x28(%ebp),%ecx
100015ca:	51                   	push   %ecx
100015cb:	e8 1c 0d 00 00       	call   0x100022ec
100015d0:	83 c4 08             	add    $0x8,%esp
100015d3:	dc 4d b8             	fmull  -0x48(%ebp)
100015d6:	dc 6d c0             	fsubrl -0x40(%ebp)
100015d9:	dd 5d f4             	fstpl  -0xc(%ebp)
100015dc:	8b 55 2c             	mov    0x2c(%ebp),%edx
100015df:	52                   	push   %edx
100015e0:	8b 45 28             	mov    0x28(%ebp),%eax
100015e3:	50                   	push   %eax
100015e4:	e8 03 0d 00 00       	call   0x100022ec
100015e9:	83 c4 08             	add    $0x8,%esp
100015ec:	dc 4d ec             	fmull  -0x14(%ebp)
100015ef:	dd 5d b0             	fstpl  -0x50(%ebp)
100015f2:	db 45 24             	fildl  0x24(%ebp)
100015f5:	dc 4d e4             	fmull  -0x1c(%ebp)
100015f8:	dd 5d a8             	fstpl  -0x58(%ebp)
100015fb:	8b 4d 2c             	mov    0x2c(%ebp),%ecx
100015fe:	51                   	push   %ecx
100015ff:	8b 55 28             	mov    0x28(%ebp),%edx
10001602:	52                   	push   %edx
10001603:	e8 de 0c 00 00       	call   0x100022e6
10001608:	83 c4 08             	add    $0x8,%esp
1000160b:	dc 4d a8             	fmull  -0x58(%ebp)
1000160e:	dc 45 b0             	faddl  -0x50(%ebp)
10001611:	dd 55 d4             	fstl   -0x2c(%ebp)
10001614:	dc 05 70 30 00 10    	faddl  0x10003070
1000161a:	e8 c1 0c 00 00       	call   0x100022e0
1000161f:	8b 4d 14             	mov    0x14(%ebp),%ecx
10001622:	03 c8                	add    %eax,%ecx
10001624:	51                   	push   %ecx
10001625:	dd 45 f4             	fldl   -0xc(%ebp)
10001628:	dc 05 70 30 00 10    	faddl  0x10003070
1000162e:	e8 ad 0c 00 00       	call   0x100022e0
10001633:	8b 55 10             	mov    0x10(%ebp),%edx
10001636:	03 d0                	add    %eax,%edx
10001638:	52                   	push   %edx
10001639:	8b 45 08             	mov    0x8(%ebp),%eax
1000163c:	50                   	push   %eax
1000163d:	ff 15 08 30 00 10    	call   *0x10003008
10001643:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
10001647:	75 53                	jne    0x1000169c
10001649:	83 7d 30 00          	cmpl   $0x0,0x30(%ebp)
1000164d:	74 06                	je     0x10001655
1000164f:	83 7d 34 00          	cmpl   $0x0,0x34(%ebp)
10001653:	75 47                	jne    0x1000169c
10001655:	8b 4d fc             	mov    -0x4(%ebp),%ecx
10001658:	51                   	push   %ecx
10001659:	8b 55 08             	mov    0x8(%ebp),%edx
1000165c:	52                   	push   %edx
1000165d:	ff 15 10 30 00 10    	call   *0x10003010
10001663:	8b 45 dc             	mov    -0x24(%ebp),%eax
10001666:	50                   	push   %eax
10001667:	ff 15 00 30 00 10    	call   *0x10003000
1000166d:	ff 15 3c 30 00 10    	call   *0x1000303c
10001673:	99                   	cltd   
10001674:	b9 40 66 03 01       	mov    $0x1036640,%ecx
10001679:	f7 f9                	idiv   %ecx
1000167b:	52                   	push   %edx
1000167c:	8b 55 20             	mov    0x20(%ebp),%edx
1000167f:	52                   	push   %edx
10001680:	6a 00                	push   $0x0
10001682:	ff 15 0c 30 00 10    	call   *0x1000300c
10001688:	89 45 dc             	mov    %eax,-0x24(%ebp)
1000168b:	8b 45 dc             	mov    -0x24(%ebp),%eax
1000168e:	50                   	push   %eax
1000168f:	8b 4d 08             	mov    0x8(%ebp),%ecx
10001692:	51                   	push   %ecx
10001693:	ff 15 10 30 00 10    	call   *0x10003010
10001699:	89 45 fc             	mov    %eax,-0x4(%ebp)
1000169c:	8b 55 e0             	mov    -0x20(%ebp),%edx
1000169f:	03 55 24             	add    0x24(%ebp),%edx
100016a2:	89 55 e0             	mov    %edx,-0x20(%ebp)
100016a5:	e9 9c fe ff ff       	jmp    0x10001546
100016aa:	8b e5                	mov    %ebp,%esp
100016ac:	5d                   	pop    %ebp
100016ad:	c3                   	ret   
 
100016ae:	55                   	push   %ebp
100016af:	8b ec                	mov    %esp,%ebp
100016b1:	81 ec 98 00 00 00    	sub    $0x98,%esp
100016b7:	56                   	push   %esi
100016b8:	c7 45 dc 00 00 00 00 	movl   $0x0,-0x24(%ebp)
100016bf:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%ebp)
100016c6:	83 7d 30 01          	cmpl   $0x1,0x30(%ebp)
100016ca:	74 0b                	je     0x100016d7
100016cc:	83 7d 30 ff          	cmpl   $0xffffffff,0x30(%ebp)
100016d0:	74 05                	je     0x100016d7
100016d2:	e9 a8 03 00 00       	jmp    0x10001a7f
100016d7:	c7 45 e0 01 00 00 00 	movl   $0x1,-0x20(%ebp)
100016de:	c7 45 d4 00 00 00 00 	movl   $0x0,-0x2c(%ebp)
100016e5:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%ebp)
100016ec:	dd 45 d4             	fldl   -0x2c(%ebp)
100016ef:	dc 05 98 30 00 10    	faddl  0x10003098
100016f5:	dc 1d 90 30 00 10    	fcompl 0x10003090
100016fb:	df e0                	fnstsw %ax
100016fd:	f6 c4 01             	test   $0x1,%ah
10001700:	0f 84 79 03 00 00    	je     0x10001a7f
10001706:	dd 45 d4             	fldl   -0x2c(%ebp)
10001709:	dc 25 78 30 00 10    	fsubl  0x10003078
1000170f:	83 ec 08             	sub    $0x8,%esp
10001712:	dd 1c 24             	fstpl  (%esp)
10001715:	e8 de 0b 00 00       	call   0x100022f8
1000171a:	83 c4 08             	add    $0x8,%esp
1000171d:	dc 1d 88 30 00 10    	fcompl 0x10003088
10001723:	df e0                	fnstsw %ax
10001725:	f6 c4 01             	test   $0x1,%ah
10001728:	74 07                	je     0x10001731
1000172a:	c7 45 e0 01 00 00 00 	movl   $0x1,-0x20(%ebp)
10001731:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
10001735:	74 1e                	je     0x10001755
10001737:	8b 45 e0             	mov    -0x20(%ebp),%eax
1000173a:	8b 4d 38             	mov    0x38(%ebp),%ecx
1000173d:	8b 14 81             	mov    (%ecx,%eax,4),%edx
10001740:	52                   	push   %edx
10001741:	8b 45 2c             	mov    0x2c(%ebp),%eax
10001744:	50                   	push   %eax
10001745:	6a 00                	push   $0x0
10001747:	ff 15 0c 30 00 10    	call   *0x1000300c
1000174d:	89 45 dc             	mov    %eax,-0x24(%ebp)
10001750:	e9 d3 00 00 00       	jmp    0x10001828
10001755:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
10001759:	75 23                	jne    0x1000177e
1000175b:	ff 15 3c 30 00 10    	call   *0x1000303c
10001761:	99                   	cltd   
10001762:	b9 80 96 98 00       	mov    $0x989680,%ecx
10001767:	f7 f9                	idiv   %ecx
10001769:	52                   	push   %edx
1000176a:	8b 55 2c             	mov    0x2c(%ebp),%edx
1000176d:	52                   	push   %edx
1000176e:	6a 00                	push   $0x0
10001770:	ff 15 0c 30 00 10    	call   *0x1000300c
10001776:	89 45 dc             	mov    %eax,-0x24(%ebp)
10001779:	e9 aa 00 00 00       	jmp    0x10001828
1000177e:	8b 45 14             	mov    0x14(%ebp),%eax
10001781:	25 01 00 00 80       	and    $0x80000001,%eax
10001786:	79 05                	jns    0x1000178d
10001788:	48                   	dec    %eax
10001789:	83 c8 fe             	or     $0xfffffffe,%eax
1000178c:	40                   	inc    %eax
1000178d:	85 c0                	test   %eax,%eax
1000178f:	75 3e                	jne    0x100017cf
10001791:	83 7d 3c 00          	cmpl   $0x0,0x3c(%ebp)
10001795:	7e 38                	jle    0x100017cf
10001797:	8b 4d 3c             	mov    0x3c(%ebp),%ecx
1000179a:	83 e9 01             	sub    $0x1,%ecx
1000179d:	8b 55 34             	mov    0x34(%ebp),%edx
100017a0:	0f af d1             	imul   %ecx,%edx
100017a3:	89 55 c8             	mov    %edx,-0x38(%ebp)
100017a6:	db 45 c8             	fildl  -0x38(%ebp)
100017a9:	da 75 20             	fidivl 0x20(%ebp)
100017ac:	dc 05 70 30 00 10    	faddl  0x10003070
100017b2:	e8 29 0b 00 00       	call   0x100022e0
100017b7:	8b 4d 0c             	mov    0xc(%ebp),%ecx
100017ba:	8b 14 81             	mov    (%ecx,%eax,4),%edx
100017bd:	52                   	push   %edx
100017be:	8b 45 2c             	mov    0x2c(%ebp),%eax
100017c1:	50                   	push   %eax
100017c2:	6a 00                	push   $0x0
100017c4:	ff 15 0c 30 00 10    	call   *0x1000300c
100017ca:	89 45 dc             	mov    %eax,-0x24(%ebp)
100017cd:	eb 59                	jmp    0x10001828
100017cf:	8b 4d 14             	mov    0x14(%ebp),%ecx
100017d2:	81 e1 01 00 00 80    	and    $0x80000001,%ecx
100017d8:	79 05                	jns    0x100017df
100017da:	49                   	dec    %ecx
100017db:	83 c9 fe             	or     $0xfffffffe,%ecx
100017de:	41                   	inc    %ecx
100017df:	83 f9 01             	cmp    $0x1,%ecx
100017e2:	75 44                	jne    0x10001828
100017e4:	83 7d 3c 00          	cmpl   $0x0,0x3c(%ebp)
100017e8:	7e 3e                	jle    0x10001828
100017ea:	8b 75 3c             	mov    0x3c(%ebp),%esi
100017ed:	83 ee 01             	sub    $0x1,%esi
100017f0:	8b 55 3c             	mov    0x3c(%ebp),%edx
100017f3:	83 ea 01             	sub    $0x1,%edx
100017f6:	8b 45 34             	mov    0x34(%ebp),%eax
100017f9:	0f af c2             	imul   %edx,%eax
100017fc:	89 45 c4             	mov    %eax,-0x3c(%ebp)
100017ff:	db 45 c4             	fildl  -0x3c(%ebp)
10001802:	da 75 20             	fidivl 0x20(%ebp)
10001805:	dc 05 70 30 00 10    	faddl  0x10003070
1000180b:	e8 d0 0a 00 00       	call   0x100022e0
10001810:	2b f0                	sub    %eax,%esi
10001812:	8b 4d 0c             	mov    0xc(%ebp),%ecx
10001815:	8b 14 b1             	mov    (%ecx,%esi,4),%edx
10001818:	52                   	push   %edx
10001819:	8b 45 2c             	mov    0x2c(%ebp),%eax
1000181c:	50                   	push   %eax
1000181d:	6a 00                	push   $0x0
1000181f:	ff 15 0c 30 00 10    	call   *0x1000300c
10001825:	89 45 dc             	mov    %eax,-0x24(%ebp)
10001828:	8b 4d dc             	mov    -0x24(%ebp),%ecx
1000182b:	51                   	push   %ecx
1000182c:	8b 55 08             	mov    0x8(%ebp),%edx
1000182f:	52                   	push   %edx
10001830:	ff 15 10 30 00 10    	call   *0x10003010
10001836:	89 45 fc             	mov    %eax,-0x4(%ebp)
10001839:	8b 45 e0             	mov    -0x20(%ebp),%eax
1000183c:	83 c0 01             	add    $0x1,%eax
1000183f:	89 45 e0             	mov    %eax,-0x20(%ebp)
10001842:	db 45 34             	fildl  0x34(%ebp)
10001845:	dd 5d ec             	fstpl  -0x14(%ebp)
10001848:	db 45 24             	fildl  0x24(%ebp)
1000184b:	da 75 20             	fidivl 0x20(%ebp)
1000184e:	dd 5d bc             	fstpl  -0x44(%ebp)
10001851:	8b 4d 20             	mov    0x20(%ebp),%ecx
10001854:	0f af 4d 20          	imul   0x20(%ebp),%ecx
10001858:	89 4d b8             	mov    %ecx,-0x48(%ebp)
1000185b:	db 45 b8             	fildl  -0x48(%ebp)
1000185e:	dd 45 ec             	fldl   -0x14(%ebp)
10001861:	dc 4d ec             	fmull  -0x14(%ebp)
10001864:	de e9                	fsubrp %st,%st(1)
10001866:	83 ec 08             	sub    $0x8,%esp
10001869:	dd 1c 24             	fstpl  (%esp)
1000186c:	e8 81 0a 00 00       	call   0x100022f2
10001871:	83 c4 08             	add    $0x8,%esp
10001874:	dc 4d bc             	fmull  -0x44(%ebp)
10001877:	dd 5d e4             	fstpl  -0x1c(%ebp)
1000187a:	8b 55 e0             	mov    -0x20(%ebp),%edx
1000187d:	81 e2 01 00 00 80    	and    $0x80000001,%edx
10001883:	79 05                	jns    0x1000188a
10001885:	4a                   	dec    %edx
10001886:	83 ca fe             	or     $0xfffffffe,%edx
10001889:	42                   	inc    %edx
1000188a:	85 d2                	test   %edx,%edx
1000188c:	75 08                	jne    0x10001896
1000188e:	dd 45 e4             	fldl   -0x1c(%ebp)
10001891:	d9 e0                	fchs   
10001893:	dd 5d e4             	fstpl  -0x1c(%ebp)
10001896:	8b 45 d8             	mov    -0x28(%ebp),%eax
10001899:	50                   	push   %eax
1000189a:	8b 4d d4             	mov    -0x2c(%ebp),%ecx
1000189d:	51                   	push   %ecx
1000189e:	e8 43 0a 00 00       	call   0x100022e6
100018a3:	83 c4 08             	add    $0x8,%esp
100018a6:	dc 4d ec             	fmull  -0x14(%ebp)
100018a9:	dd 5d b0             	fstpl  -0x50(%ebp)
100018ac:	db 45 30             	fildl  0x30(%ebp)
100018af:	dc 4d e4             	fmull  -0x1c(%ebp)
100018b2:	dd 5d a8             	fstpl  -0x58(%ebp)
100018b5:	8b 55 d8             	mov    -0x28(%ebp),%edx
100018b8:	52                   	push   %edx
100018b9:	8b 45 d4             	mov    -0x2c(%ebp),%eax
100018bc:	50                   	push   %eax
100018bd:	e8 2a 0a 00 00       	call   0x100022ec
100018c2:	83 c4 08             	add    $0x8,%esp
100018c5:	dc 4d a8             	fmull  -0x58(%ebp)
100018c8:	dc 6d b0             	fsubrl -0x50(%ebp)
100018cb:	dd 5d f4             	fstpl  -0xc(%ebp)
100018ce:	8b 4d d8             	mov    -0x28(%ebp),%ecx
100018d1:	51                   	push   %ecx
100018d2:	8b 55 d4             	mov    -0x2c(%ebp),%edx
100018d5:	52                   	push   %edx
100018d6:	e8 11 0a 00 00       	call   0x100022ec
100018db:	83 c4 08             	add    $0x8,%esp
100018de:	dc 4d ec             	fmull  -0x14(%ebp)
100018e1:	dd 5d a0             	fstpl  -0x60(%ebp)
100018e4:	db 45 30             	fildl  0x30(%ebp)
100018e7:	dc 4d e4             	fmull  -0x1c(%ebp)
100018ea:	dd 5d 98             	fstpl  -0x68(%ebp)
100018ed:	8b 45 d8             	mov    -0x28(%ebp),%eax
100018f0:	50                   	push   %eax
100018f1:	8b 4d d4             	mov    -0x2c(%ebp),%ecx
100018f4:	51                   	push   %ecx
100018f5:	e8 ec 09 00 00       	call   0x100022e6
100018fa:	83 c4 08             	add    $0x8,%esp
100018fd:	dc 4d 98             	fmull  -0x68(%ebp)
10001900:	dc 45 a0             	faddl  -0x60(%ebp)
10001903:	dd 5d cc             	fstpl  -0x34(%ebp)
10001906:	6a 00                	push   $0x0
10001908:	dd 45 cc             	fldl   -0x34(%ebp)
1000190b:	dc 05 70 30 00 10    	faddl  0x10003070
10001911:	e8 ca 09 00 00       	call   0x100022e0
10001916:	8b 55 1c             	mov    0x1c(%ebp),%edx
10001919:	03 d0                	add    %eax,%edx
1000191b:	52                   	push   %edx
1000191c:	dd 45 f4             	fldl   -0xc(%ebp)
1000191f:	dc 05 70 30 00 10    	faddl  0x10003070
10001925:	e8 b6 09 00 00       	call   0x100022e0
1000192a:	8b 4d 18             	mov    0x18(%ebp),%ecx
1000192d:	03 c8                	add    %eax,%ecx
1000192f:	51                   	push   %ecx
10001930:	8b 55 08             	mov    0x8(%ebp),%edx
10001933:	52                   	push   %edx
10001934:	ff 15 04 30 00 10    	call   *0x10003004
1000193a:	8b 45 30             	mov    0x30(%ebp),%eax
1000193d:	0f af 45 34          	imul   0x34(%ebp),%eax
10001941:	3b 45 20             	cmp    0x20(%ebp),%eax
10001944:	7d 0f                	jge    0x10001955
10001946:	8b 4d 34             	mov    0x34(%ebp),%ecx
10001949:	03 4d 30             	add    0x30(%ebp),%ecx
1000194c:	89 4d 94             	mov    %ecx,-0x6c(%ebp)
1000194f:	db 45 94             	fildl  -0x6c(%ebp)
10001952:	dd 5d ec             	fstpl  -0x14(%ebp)
10001955:	db 45 24             	fildl  0x24(%ebp)
10001958:	da 75 20             	fidivl 0x20(%ebp)
1000195b:	dd 5d 8c             	fstpl  -0x74(%ebp)
1000195e:	8b 55 20             	mov    0x20(%ebp),%edx
10001961:	0f af 55 20          	imul   0x20(%ebp),%edx
10001965:	89 55 88             	mov    %edx,-0x78(%ebp)
10001968:	db 45 88             	fildl  -0x78(%ebp)
1000196b:	dd 45 ec             	fldl   -0x14(%ebp)
1000196e:	dc 4d ec             	fmull  -0x14(%ebp)
10001971:	de e9                	fsubrp %st,%st(1)
10001973:	83 ec 08             	sub    $0x8,%esp
10001976:	dd 1c 24             	fstpl  (%esp)
10001979:	e8 74 09 00 00       	call   0x100022f2
1000197e:	83 c4 08             	add    $0x8,%esp
10001981:	dc 4d 8c             	fmull  -0x74(%ebp)
10001984:	dd 5d e4             	fstpl  -0x1c(%ebp)
10001987:	8b 45 e0             	mov    -0x20(%ebp),%eax
1000198a:	25 01 00 00 80       	and    $0x80000001,%eax
1000198f:	79 05                	jns    0x10001996
10001991:	48                   	dec    %eax
10001992:	83 c8 fe             	or     $0xfffffffe,%eax
10001995:	40                   	inc    %eax
10001996:	85 c0                	test   %eax,%eax
10001998:	75 08                	jne    0x100019a2
1000199a:	dd 45 e4             	fldl   -0x1c(%ebp)
1000199d:	d9 e0                	fchs   
1000199f:	dd 5d e4             	fstpl  -0x1c(%ebp)
100019a2:	8b 4d d8             	mov    -0x28(%ebp),%ecx
100019a5:	51                   	push   %ecx
100019a6:	8b 55 d4             	mov    -0x2c(%ebp),%edx
100019a9:	52                   	push   %edx
100019aa:	e8 37 09 00 00       	call   0x100022e6
100019af:	83 c4 08             	add    $0x8,%esp
100019b2:	dc 4d ec             	fmull  -0x14(%ebp)
100019b5:	dd 5d 80             	fstpl  -0x80(%ebp)
100019b8:	db 45 30             	fildl  0x30(%ebp)
100019bb:	dc 4d e4             	fmull  -0x1c(%ebp)
100019be:	dd 9d 78 ff ff ff    	fstpl  -0x88(%ebp)
100019c4:	8b 45 d8             	mov    -0x28(%ebp),%eax
100019c7:	50                   	push   %eax
100019c8:	8b 4d d4             	mov    -0x2c(%ebp),%ecx
100019cb:	51                   	push   %ecx
100019cc:	e8 1b 09 00 00       	call   0x100022ec
100019d1:	83 c4 08             	add    $0x8,%esp
100019d4:	dc 8d 78 ff ff ff    	fmull  -0x88(%ebp)
100019da:	dc 6d 80             	fsubrl -0x80(%ebp)
100019dd:	dd 5d f4             	fstpl  -0xc(%ebp)
100019e0:	8b 55 d8             	mov    -0x28(%ebp),%edx
100019e3:	52                   	push   %edx
100019e4:	8b 45 d4             	mov    -0x2c(%ebp),%eax
100019e7:	50                   	push   %eax
100019e8:	e8 ff 08 00 00       	call   0x100022ec
100019ed:	83 c4 08             	add    $0x8,%esp
100019f0:	dc 4d ec             	fmull  -0x14(%ebp)
100019f3:	dd 9d 70 ff ff ff    	fstpl  -0x90(%ebp)
100019f9:	db 45 30             	fildl  0x30(%ebp)
100019fc:	dc 4d e4             	fmull  -0x1c(%ebp)
100019ff:	dd 9d 68 ff ff ff    	fstpl  -0x98(%ebp)
10001a05:	8b 4d d8             	mov    -0x28(%ebp),%ecx
10001a08:	51                   	push   %ecx
10001a09:	8b 55 d4             	mov    -0x2c(%ebp),%edx
10001a0c:	52                   	push   %edx
10001a0d:	e8 d4 08 00 00       	call   0x100022e6
10001a12:	83 c4 08             	add    $0x8,%esp
10001a15:	dc 8d 68 ff ff ff    	fmull  -0x98(%ebp)
10001a1b:	dc 85 70 ff ff ff    	faddl  -0x90(%ebp)
10001a21:	dd 55 cc             	fstl   -0x34(%ebp)
10001a24:	dc 05 70 30 00 10    	faddl  0x10003070
10001a2a:	e8 b1 08 00 00       	call   0x100022e0
10001a2f:	8b 4d 1c             	mov    0x1c(%ebp),%ecx
10001a32:	03 c8                	add    %eax,%ecx
10001a34:	51                   	push   %ecx
10001a35:	dd 45 f4             	fldl   -0xc(%ebp)
10001a38:	dc 05 70 30 00 10    	faddl  0x10003070
10001a3e:	e8 9d 08 00 00       	call   0x100022e0
10001a43:	8b 55 18             	mov    0x18(%ebp),%edx
10001a46:	03 d0                	add    %eax,%edx
10001a48:	52                   	push   %edx
10001a49:	8b 45 08             	mov    0x8(%ebp),%eax
10001a4c:	50                   	push   %eax
10001a4d:	ff 15 08 30 00 10    	call   *0x10003008
10001a53:	8b 4d fc             	mov    -0x4(%ebp),%ecx
10001a56:	51                   	push   %ecx
10001a57:	8b 55 08             	mov    0x8(%ebp),%edx
10001a5a:	52                   	push   %edx
10001a5b:	ff 15 10 30 00 10    	call   *0x10003010
10001a61:	8b 45 dc             	mov    -0x24(%ebp),%eax
10001a64:	50                   	push   %eax
10001a65:	ff 15 00 30 00 10    	call   *0x10003000
10001a6b:	db 45 28             	fildl  0x28(%ebp)
10001a6e:	dc 3d 90 30 00 10    	fdivrl 0x10003090
10001a74:	dc 45 d4             	faddl  -0x2c(%ebp)
10001a77:	dd 5d d4             	fstpl  -0x2c(%ebp)
10001a7a:	e9 6d fc ff ff       	jmp    0x100016ec
10001a7f:	5e                   	pop    %esi
10001a80:	8b e5                	mov    %ebp,%esp
10001a82:	5d                   	pop    %ebp
10001a83:	c3                   	ret    

10001a84:	55                   	push   %ebp
10001a85:	8b ec                	mov    %esp,%ebp
10001a87:	b8 48 20 00 00       	mov    $0x2048,%eax
10001a8c:	e8 7f 08 00 00       	call   0x10002310
10001a91:	56                   	push   %esi
10001a92:	57                   	push   %edi
10001a93:	c7 85 e4 df ff ff 00 	movl   $0x0,-0x201c(%ebp)
10001a9a:	00 00 00 
10001a9d:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%ebp)
10001aa4:	83 7d 3c 00          	cmpl   $0x0,0x3c(%ebp)
10001aa8:	7e 0c                	jle    0x10001ab6
10001aaa:	83 7d 40 00          	cmpl   $0x0,0x40(%ebp)
10001aae:	7c 06                	jl     0x10001ab6
10001ab0:	83 7d 44 00          	cmpl   $0x0,0x44(%ebp)
10001ab4:	75 05                	jne    0x10001abb
10001ab6:	e9 bd 07 00 00       	jmp    0x10002278
10001abb:	c7 05 24 40 00 10 01 	movl   $0x1,0x10004024
10001ac2:	00 00 00 
10001ac5:	c7 05 28 40 00 10 00 	movl   $0x0,0x10004028
10001acc:	00 00 00 
10001acf:	dd 45 14             	fldl   0x14(%ebp)
10001ad2:	dc 1d a0 30 00 10    	fcompl 0x100030a0
10001ad8:	df e0                	fnstsw %ax
10001ada:	f6 c4 40             	test   $0x40,%ah
10001add:	74 1a                	je     0x10001af9
10001adf:	dd 45 1c             	fldl   0x1c(%ebp)
10001ae2:	dc 1d a0 30 00 10    	fcompl 0x100030a0
10001ae8:	df e0                	fnstsw %ax
10001aea:	f6 c4 40             	test   $0x40,%ah
10001aed:	74 0a                	je     0x10001af9
10001aef:	c7 05 28 40 00 10 01 	movl   $0x1,0x10004028
10001af6:	00 00 00 
10001af9:	c7 85 dc df ff ff 00 	movl   $0x0,-0x2024(%ebp)
10001b00:	00 00 00 
10001b03:	c7 85 e0 df ff ff 00 	movl   $0x0,-0x2020(%ebp)
10001b0a:	00 00 00 
10001b0d:	8b 45 44             	mov    0x44(%ebp),%eax
10001b10:	25 01 00 00 80       	and    $0x80000001,%eax
10001b15:	79 05                	jns    0x10001b1c
10001b17:	48                   	dec    %eax
10001b18:	83 c8 fe             	or     $0xfffffffe,%eax
10001b1b:	40                   	inc    %eax
10001b1c:	85 c0                	test   %eax,%eax
10001b1e:	74 09                	je     0x10001b29
10001b20:	8b 4d 44             	mov    0x44(%ebp),%ecx
10001b23:	83 c1 01             	add    $0x1,%ecx
10001b26:	89 4d 44             	mov    %ecx,0x44(%ebp)
10001b29:	83 7d 44 30          	cmpl   $0x30,0x44(%ebp)
10001b2d:	75 1e                	jne    0x10001b4d
10001b2f:	ff 15 3c 30 00 10    	call   *0x1000303c
10001b35:	25 01 00 00 80       	and    $0x80000001,%eax
10001b3a:	79 05                	jns    0x10001b41
10001b3c:	48                   	dec    %eax
10001b3d:	83 c8 fe             	or     $0xfffffffe,%eax
10001b40:	40                   	inc    %eax
10001b41:	85 c0                	test   %eax,%eax
10001b43:	75 08                	jne    0x10001b4d
10001b45:	8b 55 44             	mov    0x44(%ebp),%edx
10001b48:	f7 da                	neg    %edx
10001b4a:	89 55 44             	mov    %edx,0x44(%ebp)
10001b4d:	8b 45 08             	mov    0x8(%ebp),%eax
10001b50:	50                   	push   %eax
10001b51:	ff 15 5c 30 00 10    	call   *0x1000305c
10001b57:	89 45 f0             	mov    %eax,-0x10(%ebp)
10001b5a:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
10001b5e:	74 0b                	je     0x10001b6b
10001b60:	8b 4d 10             	mov    0x10(%ebp),%ecx
10001b63:	89 8d d8 df ff ff    	mov    %ecx,-0x2028(%ebp)
10001b69:	eb 0a                	jmp    0x10001b75
10001b6b:	c7 85 d8 df ff ff 00 	movl   $0x0,-0x2028(%ebp)
10001b72:	00 00 00 
10001b75:	83 7d 2c 00          	cmpl   $0x0,0x2c(%ebp)
10001b79:	74 36                	je     0x10001bb1
10001b7b:	8b 55 40             	mov    0x40(%ebp),%edx
10001b7e:	52                   	push   %edx
10001b7f:	8b 45 38             	mov    0x38(%ebp),%eax
10001b82:	50                   	push   %eax
10001b83:	8b 4d 34             	mov    0x34(%ebp),%ecx
10001b86:	51                   	push   %ecx
10001b87:	8b 55 f0             	mov    -0x10(%ebp),%edx
10001b8a:	52                   	push   %edx
10001b8b:	e8 0f f8 ff ff       	call   0x1000139f
10001b90:	83 c4 10             	add    $0x10,%esp
10001b93:	83 7d 24 00          	cmpl   $0x0,0x24(%ebp)
10001b97:	75 18                	jne    0x10001bb1
10001b99:	8b 45 3c             	mov    0x3c(%ebp),%eax
10001b9c:	50                   	push   %eax
10001b9d:	8b 4d 38             	mov    0x38(%ebp),%ecx
10001ba0:	51                   	push   %ecx
10001ba1:	8b 55 34             	mov    0x34(%ebp),%edx
10001ba4:	52                   	push   %edx
10001ba5:	8b 45 f0             	mov    -0x10(%ebp),%eax
10001ba8:	50                   	push   %eax
10001ba9:	e8 8c f8 ff ff       	call   0x1000143a
10001bae:	83 c4 10             	add    $0x10,%esp
10001bb1:	c7 85 e8 df ff ff 00 	movl   $0x0,-0x2018(%ebp)
10001bb8:	00 00 00 
10001bbb:	c7 85 dc df ff ff 00 	movl   $0x0,-0x2024(%ebp)
10001bc2:	00 00 00 
10001bc5:	c7 85 e0 df ff ff 00 	movl   $0x0,-0x2020(%ebp)
10001bcc:	00 00 00 
10001bcf:	e8 38 f4 ff ff       	call   0x1000100c
10001bd4:	8b f0                	mov    %eax,%esi
10001bd6:	8b fa                	mov    %edx,%edi
10001bd8:	dd 45 1c             	fldl   0x1c(%ebp)
10001bdb:	dc 0d 68 30 00 10    	fmull  0x10003068
10001be1:	dc 0d 10 40 00 10    	fmull  0x10004010
10001be7:	e8 f4 06 00 00       	call   0x100022e0
10001bec:	03 f0                	add    %eax,%esi
10001bee:	13 fa                	adc    %edx,%edi
10001bf0:	89 75 f4             	mov    %esi,-0xc(%ebp)
10001bf3:	89 7d f8             	mov    %edi,-0x8(%ebp)
10001bf6:	83 7d 24 00          	cmpl   $0x0,0x24(%ebp)
10001bfa:	0f 85 fb 03 00 00    	jne    0x10001ffb
10001c00:	83 3d 28 40 00 10 00 	cmpl   $0x0,0x10004028
10001c07:	0f 85 81 00 00 00    	jne    0x10001c8e
10001c0d:	db 85 e8 df ff ff    	fildl  -0x2018(%ebp)
10001c13:	dd 9d d0 df ff ff    	fstpl  -0x2030(%ebp)
10001c19:	db 45 44             	fildl  0x44(%ebp)
10001c1c:	83 ec 08             	sub    $0x8,%esp
10001c1f:	dd 1c 24             	fstpl  (%esp)
10001c22:	e8 d1 06 00 00       	call   0x100022f8
10001c27:	83 c4 08             	add    $0x8,%esp
10001c2a:	dc bd d0 df ff ff    	fdivrl -0x2030(%ebp)
10001c30:	dc 25 98 30 00 10    	fsubl  0x10003098
10001c36:	dc 5d 14             	fcompl 0x14(%ebp)
10001c39:	df e0                	fnstsw %ax
10001c3b:	f6 c4 01             	test   $0x1,%ah
10001c3e:	74 10                	je     0x10001c50
10001c40:	dd 45 14             	fldl   0x14(%ebp)
10001c43:	dc 1d a0 30 00 10    	fcompl 0x100030a0
10001c49:	df e0                	fnstsw %ax
10001c4b:	f6 c4 41             	test   $0x41,%ah
10001c4e:	74 3e                	je     0x10001c8e
10001c50:	e8 b7 f3 ff ff       	call   0x1000100c
10001c55:	89 85 c8 df ff ff    	mov    %eax,-0x2038(%ebp)
10001c5b:	89 95 cc df ff ff    	mov    %edx,-0x2034(%ebp)
10001c61:	8b 8d cc df ff ff    	mov    -0x2034(%ebp),%ecx
10001c67:	3b 4d f8             	cmp    -0x8(%ebp),%ecx
10001c6a:	0f 8f 8b 03 00 00    	jg     0x10001ffb
10001c70:	7c 0f                	jl     0x10001c81
10001c72:	8b 95 c8 df ff ff    	mov    -0x2038(%ebp),%edx
10001c78:	3b 55 f4             	cmp    -0xc(%ebp),%edx
10001c7b:	0f 83 7a 03 00 00    	jae    0x10001ffb
10001c81:	83 3d 24 40 00 10 00 	cmpl   $0x0,0x10004024
10001c88:	0f 84 6d 03 00 00    	je     0x10001ffb
10001c8e:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
10001c92:	75 26                	jne    0x10001cba
10001c94:	ff 15 3c 30 00 10    	call   *0x1000303c
10001c9a:	99                   	cltd   
10001c9b:	b9 40 66 03 01       	mov    $0x1036640,%ecx
10001ca0:	f7 f9                	idiv   %ecx
10001ca2:	52                   	push   %edx
10001ca3:	8b 55 48             	mov    0x48(%ebp),%edx
10001ca6:	52                   	push   %edx
10001ca7:	6a 00                	push   $0x0
10001ca9:	ff 15 0c 30 00 10    	call   *0x1000300c
10001caf:	89 85 e4 df ff ff    	mov    %eax,-0x201c(%ebp)
10001cb5:	e9 71 01 00 00       	jmp    0x10001e2b
10001cba:	83 7d 28 00          	cmpl   $0x0,0x28(%ebp)
10001cbe:	75 79                	jne    0x10001d39
10001cc0:	8b 85 e8 df ff ff    	mov    -0x2018(%ebp),%eax
10001cc6:	99                   	cltd   
10001cc7:	f7 bd d8 df ff ff    	idivl  -0x2028(%ebp)
10001ccd:	25 01 00 00 80       	and    $0x80000001,%eax
10001cd2:	79 05                	jns    0x10001cd9
10001cd4:	48                   	dec    %eax
10001cd5:	83 c8 fe             	or     $0xfffffffe,%eax
10001cd8:	40                   	inc    %eax
10001cd9:	85 c0                	test   %eax,%eax
10001cdb:	74 28                	je     0x10001d05
10001cdd:	8b 85 e8 df ff ff    	mov    -0x2018(%ebp),%eax
10001ce3:	99                   	cltd   
10001ce4:	f7 bd d8 df ff ff    	idivl  -0x2028(%ebp)
10001cea:	8b 45 0c             	mov    0xc(%ebp),%eax
10001ced:	8b 0c 90             	mov    (%eax,%edx,4),%ecx
10001cf0:	51                   	push   %ecx
10001cf1:	8b 55 48             	mov    0x48(%ebp),%edx
10001cf4:	52                   	push   %edx
10001cf5:	6a 00                	push   $0x0
10001cf7:	ff 15 0c 30 00 10    	call   *0x1000300c
10001cfd:	89 85 e4 df ff ff    	mov    %eax,-0x201c(%ebp)
10001d03:	eb 2f                	jmp    0x10001d34
10001d05:	8b 85 e8 df ff ff    	mov    -0x2018(%ebp),%eax
10001d0b:	99                   	cltd   
10001d0c:	f7 bd d8 df ff ff    	idivl  -0x2028(%ebp)
10001d12:	8b 85 d8 df ff ff    	mov    -0x2028(%ebp),%eax
10001d18:	2b c2                	sub    %edx,%eax
10001d1a:	8b 4d 0c             	mov    0xc(%ebp),%ecx
10001d1d:	8b 54 81 fc          	mov    -0x4(%ecx,%eax,4),%edx
10001d21:	52                   	push   %edx
10001d22:	8b 45 48             	mov    0x48(%ebp),%eax
10001d25:	50                   	push   %eax
10001d26:	6a 00                	push   $0x0
10001d28:	ff 15 0c 30 00 10    	call   *0x1000300c
10001d2e:	89 85 e4 df ff ff    	mov    %eax,-0x201c(%ebp)
10001d34:	e9 f2 00 00 00       	jmp    0x10001e2b
10001d39:	8b 4d 30             	mov    0x30(%ebp),%ecx
10001d3c:	81 e1 01 00 00 80    	and    $0x80000001,%ecx
10001d42:	79 05                	jns    0x10001d49
10001d44:	49                   	dec    %ecx
10001d45:	83 c9 fe             	or     $0xfffffffe,%ecx
10001d48:	41                   	inc    %ecx
10001d49:	85 c9                	test   %ecx,%ecx
10001d4b:	75 61                	jne    0x10001dae
10001d4d:	83 bd d8 df ff ff 00 	cmpl   $0x0,-0x2028(%ebp)
10001d54:	7e 58                	jle    0x10001dae
10001d56:	8b 45 44             	mov    0x44(%ebp),%eax
10001d59:	99                   	cltd   
10001d5a:	2b c2                	sub    %edx,%eax
10001d5c:	d1 f8                	sar    %eax
10001d5e:	50                   	push   %eax
10001d5f:	e8 9a 05 00 00       	call   0x100022fe
10001d64:	83 c4 04             	add    $0x4,%esp
10001d67:	8b c8                	mov    %eax,%ecx
10001d69:	8b 85 e8 df ff ff    	mov    -0x2018(%ebp),%eax
10001d6f:	99                   	cltd   
10001d70:	f7 f9                	idiv   %ecx
10001d72:	8b b5 d8 df ff ff    	mov    -0x2028(%ebp),%esi
10001d78:	0f af f2             	imul   %edx,%esi
10001d7b:	8b 45 44             	mov    0x44(%ebp),%eax
10001d7e:	99                   	cltd   
10001d7f:	2b c2                	sub    %edx,%eax
10001d81:	d1 f8                	sar    %eax
10001d83:	50                   	push   %eax
10001d84:	e8 75 05 00 00       	call   0x100022fe
10001d89:	83 c4 04             	add    $0x4,%esp
10001d8c:	8b c8                	mov    %eax,%ecx
10001d8e:	8b c6                	mov    %esi,%eax
10001d90:	99                   	cltd   
10001d91:	f7 f9                	idiv   %ecx
10001d93:	8b 55 0c             	mov    0xc(%ebp),%edx
10001d96:	8b 04 82             	mov    (%edx,%eax,4),%eax
10001d99:	50                   	push   %eax
10001d9a:	8b 4d 48             	mov    0x48(%ebp),%ecx
10001d9d:	51                   	push   %ecx
10001d9e:	6a 00                	push   $0x0
10001da0:	ff 15 0c 30 00 10    	call   *0x1000300c
10001da6:	89 85 e4 df ff ff    	mov    %eax,-0x201c(%ebp)
10001dac:	eb 7d                	jmp    0x10001e2b
10001dae:	8b 55 30             	mov    0x30(%ebp),%edx
10001db1:	81 e2 01 00 00 80    	and    $0x80000001,%edx
10001db7:	79 05                	jns    0x10001dbe
10001db9:	4a                   	dec    %edx
10001dba:	83 ca fe             	or     $0xfffffffe,%edx
10001dbd:	42                   	inc    %edx
10001dbe:	83 fa 01             	cmp    $0x1,%edx
10001dc1:	75 68                	jne    0x10001e2b
10001dc3:	83 bd d8 df ff ff 00 	cmpl   $0x0,-0x2028(%ebp)
10001dca:	7e 5f                	jle    0x10001e2b
10001dcc:	8b 45 44             	mov    0x44(%ebp),%eax
10001dcf:	99                   	cltd   
10001dd0:	2b c2                	sub    %edx,%eax
10001dd2:	d1 f8                	sar    %eax
10001dd4:	50                   	push   %eax
10001dd5:	e8 24 05 00 00       	call   0x100022fe
10001dda:	83 c4 04             	add    $0x4,%esp
10001ddd:	8b c8                	mov    %eax,%ecx
10001ddf:	8b 85 e8 df ff ff    	mov    -0x2018(%ebp),%eax
10001de5:	99                   	cltd   
10001de6:	f7 f9                	idiv   %ecx
10001de8:	8b b5 d8 df ff ff    	mov    -0x2028(%ebp),%esi
10001dee:	0f af f2             	imul   %edx,%esi
10001df1:	8b 45 44             	mov    0x44(%ebp),%eax
10001df4:	99                   	cltd   
10001df5:	2b c2                	sub    %edx,%eax
10001df7:	d1 f8                	sar    %eax
10001df9:	50                   	push   %eax
10001dfa:	e8 ff 04 00 00       	call   0x100022fe
10001dff:	83 c4 04             	add    $0x4,%esp
10001e02:	8b c8                	mov    %eax,%ecx
10001e04:	8b c6                	mov    %esi,%eax
10001e06:	99                   	cltd   
10001e07:	f7 f9                	idiv   %ecx
10001e09:	8b 95 d8 df ff ff    	mov    -0x2028(%ebp),%edx
10001e0f:	2b d0                	sub    %eax,%edx
10001e11:	8b 45 0c             	mov    0xc(%ebp),%eax
10001e14:	8b 4c 90 fc          	mov    -0x4(%eax,%edx,4),%ecx
10001e18:	51                   	push   %ecx
10001e19:	8b 55 48             	mov    0x48(%ebp),%edx
10001e1c:	52                   	push   %edx
10001e1d:	6a 00                	push   $0x0
10001e1f:	ff 15 0c 30 00 10    	call   *0x1000300c
10001e25:	89 85 e4 df ff ff    	mov    %eax,-0x201c(%ebp)
10001e2b:	8b 85 e4 df ff ff    	mov    -0x201c(%ebp),%eax
10001e31:	50                   	push   %eax
10001e32:	8b 4d f0             	mov    -0x10(%ebp),%ecx
10001e35:	51                   	push   %ecx
10001e36:	ff 15 10 30 00 10    	call   *0x10003010
10001e3c:	89 45 fc             	mov    %eax,-0x4(%ebp)
10001e3f:	6a 00                	push   $0x0
10001e41:	db 45 3c             	fildl  0x3c(%ebp)
10001e44:	dd 9d c0 df ff ff    	fstpl  -0x2040(%ebp)
10001e4a:	8b 95 e0 df ff ff    	mov    -0x2020(%ebp),%edx
10001e50:	52                   	push   %edx
10001e51:	8b 85 dc df ff ff    	mov    -0x2024(%ebp),%eax
10001e57:	50                   	push   %eax
10001e58:	e8 8f 04 00 00       	call   0x100022ec
10001e5d:	83 c4 08             	add    $0x8,%esp
10001e60:	dc 8d c0 df ff ff    	fmull  -0x2040(%ebp)
10001e66:	dc 05 70 30 00 10    	faddl  0x10003070
10001e6c:	e8 6f 04 00 00       	call   0x100022e0
10001e71:	8b 4d 38             	mov    0x38(%ebp),%ecx
10001e74:	2b c8                	sub    %eax,%ecx
10001e76:	51                   	push   %ecx
10001e77:	db 45 3c             	fildl  0x3c(%ebp)
10001e7a:	dd 9d b8 df ff ff    	fstpl  -0x2048(%ebp)
10001e80:	8b 95 e0 df ff ff    	mov    -0x2020(%ebp),%edx
10001e86:	52                   	push   %edx
10001e87:	8b 85 dc df ff ff    	mov    -0x2024(%ebp),%eax
10001e8d:	50                   	push   %eax
10001e8e:	e8 53 04 00 00       	call   0x100022e6
10001e93:	83 c4 08             	add    $0x8,%esp
10001e96:	dc 8d b8 df ff ff    	fmull  -0x2048(%ebp)
10001e9c:	dc 05 70 30 00 10    	faddl  0x10003070
10001ea2:	e8 39 04 00 00       	call   0x100022e0
10001ea7:	8b 4d 34             	mov    0x34(%ebp),%ecx
10001eaa:	2b c8                	sub    %eax,%ecx
10001eac:	51                   	push   %ecx
10001ead:	8b 55 f0             	mov    -0x10(%ebp),%edx
10001eb0:	52                   	push   %edx
10001eb1:	ff 15 04 30 00 10    	call   *0x10003004
10001eb7:	8b 85 d8 df ff ff    	mov    -0x2028(%ebp),%eax
10001ebd:	50                   	push   %eax
10001ebe:	8b 4d 0c             	mov    0xc(%ebp),%ecx
10001ec1:	51                   	push   %ecx
10001ec2:	8b 95 e0 df ff ff    	mov    -0x2020(%ebp),%edx
10001ec8:	52                   	push   %edx
10001ec9:	8b 85 dc df ff ff    	mov    -0x2024(%ebp),%eax
10001ecf:	50                   	push   %eax
10001ed0:	6a 01                	push   $0x1
10001ed2:	8b 4d 48             	mov    0x48(%ebp),%ecx
10001ed5:	51                   	push   %ecx
10001ed6:	8b 55 40             	mov    0x40(%ebp),%edx
10001ed9:	52                   	push   %edx
10001eda:	8b 45 3c             	mov    0x3c(%ebp),%eax
10001edd:	50                   	push   %eax
10001ede:	8b 4d 38             	mov    0x38(%ebp),%ecx
10001ee1:	51                   	push   %ecx
10001ee2:	8b 55 34             	mov    0x34(%ebp),%edx
10001ee5:	52                   	push   %edx
10001ee6:	8b 45 28             	mov    0x28(%ebp),%eax
10001ee9:	50                   	push   %eax
10001eea:	8b 4d f0             	mov    -0x10(%ebp),%ecx
10001eed:	51                   	push   %ecx
10001eee:	e8 22 f6 ff ff       	call   0x10001515
10001ef3:	83 c4 30             	add    $0x30,%esp
10001ef6:	8b 95 d8 df ff ff    	mov    -0x2028(%ebp),%edx
10001efc:	52                   	push   %edx
10001efd:	8b 45 0c             	mov    0xc(%ebp),%eax
10001f00:	50                   	push   %eax
10001f01:	8b 8d e0 df ff ff    	mov    -0x2020(%ebp),%ecx
10001f07:	51                   	push   %ecx
10001f08:	8b 95 dc df ff ff    	mov    -0x2024(%ebp),%edx
10001f0e:	52                   	push   %edx
10001f0f:	6a ff                	push   $0xffffffff
10001f11:	8b 45 48             	mov    0x48(%ebp),%eax
10001f14:	50                   	push   %eax
10001f15:	8b 4d 40             	mov    0x40(%ebp),%ecx
10001f18:	51                   	push   %ecx
10001f19:	8b 55 3c             	mov    0x3c(%ebp),%edx
10001f1c:	52                   	push   %edx
10001f1d:	8b 45 38             	mov    0x38(%ebp),%eax
10001f20:	50                   	push   %eax
10001f21:	8b 4d 34             	mov    0x34(%ebp),%ecx
10001f24:	51                   	push   %ecx
10001f25:	8b 55 28             	mov    0x28(%ebp),%edx
10001f28:	52                   	push   %edx
10001f29:	8b 45 f0             	mov    -0x10(%ebp),%eax
10001f2c:	50                   	push   %eax
10001f2d:	e8 e3 f5 ff ff       	call   0x10001515
10001f32:	83 c4 30             	add    $0x30,%esp
10001f35:	8b 4d fc             	mov    -0x4(%ebp),%ecx
10001f38:	51                   	push   %ecx
10001f39:	8b 55 f0             	mov    -0x10(%ebp),%edx
10001f3c:	52                   	push   %edx
10001f3d:	ff 15 10 30 00 10    	call   *0x10003010
10001f43:	8b 85 e4 df ff ff    	mov    -0x201c(%ebp),%eax
10001f49:	50                   	push   %eax
10001f4a:	ff 15 00 30 00 10    	call   *0x10003000
10001f50:	db 45 44             	fildl  0x44(%ebp)
10001f53:	dc 3d 90 30 00 10    	fdivrl 0x10003090
10001f59:	dc 85 dc df ff ff    	faddl  -0x2024(%ebp)
10001f5f:	dd 9d dc df ff ff    	fstpl  -0x2024(%ebp)
10001f65:	8b 8d e0 df ff ff    	mov    -0x2020(%ebp),%ecx
10001f6b:	51                   	push   %ecx
10001f6c:	8b 95 dc df ff ff    	mov    -0x2024(%ebp),%edx
10001f72:	52                   	push   %edx
10001f73:	e8 80 03 00 00       	call   0x100022f8
10001f78:	83 c4 08             	add    $0x8,%esp
10001f7b:	dc 1d 90 30 00 10    	fcompl 0x10003090
10001f81:	df e0                	fnstsw %ax
10001f83:	f6 c4 41             	test   $0x41,%ah
10001f86:	75 06                	jne    0x10001f8e
10001f88:	83 7d 30 02          	cmpl   $0x2,0x30(%ebp)
10001f8c:	7c 2f                	jl     0x10001fbd
10001f8e:	8b 85 e0 df ff ff    	mov    -0x2020(%ebp),%eax
10001f94:	50                   	push   %eax
10001f95:	8b 8d dc df ff ff    	mov    -0x2024(%ebp),%ecx
10001f9b:	51                   	push   %ecx
10001f9c:	e8 57 03 00 00       	call   0x100022f8
10001fa1:	83 c4 08             	add    $0x8,%esp
10001fa4:	dc 05 98 30 00 10    	faddl  0x10003098
10001faa:	dc 1d 90 30 00 10    	fcompl 0x10003090
10001fb0:	df e0                	fnstsw %ax
10001fb2:	f6 c4 41             	test   $0x41,%ah
10001fb5:	75 1a                	jne    0x10001fd1
10001fb7:	83 7d 30 01          	cmpl   $0x1,0x30(%ebp)
10001fbb:	7e 14                	jle    0x10001fd1
10001fbd:	c7 85 dc df ff ff 00 	movl   $0x0,-0x2024(%ebp)
10001fc4:	00 00 00 
10001fc7:	c7 85 e0 df ff ff 00 	movl   $0x0,-0x2020(%ebp)
10001fce:	00 00 00 
10001fd1:	8b 95 e8 df ff ff    	mov    -0x2018(%ebp),%edx
10001fd7:	83 c2 01             	add    $0x1,%edx
10001fda:	89 95 e8 df ff ff    	mov    %edx,-0x2018(%ebp)
10001fe0:	81 bd e8 df ff ff 00 	cmpl   $0x77359400,-0x2018(%ebp)
10001fe7:	94 35 77 
10001fea:	7e 0a                	jle    0x10001ff6
10001fec:	c7 85 e8 df ff ff 00 	movl   $0x0,-0x2018(%ebp)
10001ff3:	00 00 00 
10001ff6:	e9 05 fc ff ff       	jmp    0x10001c00
10001ffb:	83 7d 24 00          	cmpl   $0x0,0x24(%ebp)
10001fff:	0f 84 67 02 00 00    	je     0x1000226c
10002005:	83 7d 44 00          	cmpl   $0x0,0x44(%ebp)
10002009:	7d 08                	jge    0x10002013
1000200b:	8b 45 44             	mov    0x44(%ebp),%eax
1000200e:	f7 d8                	neg    %eax
10002010:	89 45 44             	mov    %eax,0x44(%ebp)
10002013:	c7 85 ec df ff ff 00 	movl   $0x0,-0x2014(%ebp)
1000201a:	00 00 00 
1000201d:	eb 0f                	jmp    0x1000202e
1000201f:	8b 8d ec df ff ff    	mov    -0x2014(%ebp),%ecx
10002025:	83 c1 01             	add    $0x1,%ecx
10002028:	89 8d ec df ff ff    	mov    %ecx,-0x2014(%ebp)
1000202e:	81 bd ec df ff ff 00 	cmpl   $0x800,-0x2014(%ebp)
10002035:	08 00 00 
10002038:	0f 8d 11 01 00 00    	jge    0x1000214f
1000203e:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
10002042:	75 20                	jne    0x10002064
10002044:	ff 15 3c 30 00 10    	call   *0x1000303c
1000204a:	99                   	cltd   
1000204b:	b9 80 96 98 00       	mov    $0x989680,%ecx
10002050:	f7 f9                	idiv   %ecx
10002052:	8b 85 ec df ff ff    	mov    -0x2014(%ebp),%eax
10002058:	89 94 85 f0 df ff ff 	mov    %edx,-0x2010(%ebp,%eax,4)
1000205f:	e9 e6 00 00 00       	jmp    0x1000214a
10002064:	8b 4d 30             	mov    0x30(%ebp),%ecx
10002067:	81 e1 03 00 00 80    	and    $0x80000003,%ecx
1000206d:	79 05                	jns    0x10002074
1000206f:	49                   	dec    %ecx
10002070:	83 c9 fc             	or     $0xfffffffc,%ecx
10002073:	41                   	inc    %ecx
10002074:	85 c9                	test   %ecx,%ecx
10002076:	75 5b                	jne    0x100020d3
10002078:	83 bd d8 df ff ff 00 	cmpl   $0x0,-0x2028(%ebp)
1000207f:	7e 52                	jle    0x100020d3
10002081:	8b 45 44             	mov    0x44(%ebp),%eax
10002084:	99                   	cltd   
10002085:	2b c2                	sub    %edx,%eax
10002087:	d1 f8                	sar    %eax
10002089:	50                   	push   %eax
1000208a:	e8 6f 02 00 00       	call   0x100022fe
1000208f:	83 c4 04             	add    $0x4,%esp
10002092:	8b c8                	mov    %eax,%ecx
10002094:	8b 85 ec df ff ff    	mov    -0x2014(%ebp),%eax
1000209a:	99                   	cltd   
1000209b:	f7 f9                	idiv   %ecx
1000209d:	8b b5 d8 df ff ff    	mov    -0x2028(%ebp),%esi
100020a3:	0f af f2             	imul   %edx,%esi
100020a6:	8b 45 44             	mov    0x44(%ebp),%eax
100020a9:	99                   	cltd   
100020aa:	2b c2                	sub    %edx,%eax
100020ac:	d1 f8                	sar    %eax
100020ae:	50                   	push   %eax
100020af:	e8 4a 02 00 00       	call   0x100022fe
100020b4:	83 c4 04             	add    $0x4,%esp
100020b7:	8b c8                	mov    %eax,%ecx
100020b9:	8b c6                	mov    %esi,%eax
100020bb:	99                   	cltd   
100020bc:	f7 f9                	idiv   %ecx
100020be:	8b 95 ec df ff ff    	mov    -0x2014(%ebp),%edx
100020c4:	8b 4d 0c             	mov    0xc(%ebp),%ecx
100020c7:	8b 04 81             	mov    (%ecx,%eax,4),%eax
100020ca:	89 84 95 f0 df ff ff 	mov    %eax,-0x2010(%ebp,%edx,4)
100020d1:	eb 77                	jmp    0x1000214a
100020d3:	8b 4d 30             	mov    0x30(%ebp),%ecx
100020d6:	81 e1 03 00 00 80    	and    $0x80000003,%ecx
100020dc:	79 05                	jns    0x100020e3
100020de:	49                   	dec    %ecx
100020df:	83 c9 fc             	or     $0xfffffffc,%ecx
100020e2:	41                   	inc    %ecx
100020e3:	83 f9 01             	cmp    $0x1,%ecx
100020e6:	75 62                	jne    0x1000214a
100020e8:	83 bd d8 df ff ff 00 	cmpl   $0x0,-0x2028(%ebp)
100020ef:	7e 59                	jle    0x1000214a
100020f1:	8b 45 44             	mov    0x44(%ebp),%eax
100020f4:	99                   	cltd   
100020f5:	2b c2                	sub    %edx,%eax
100020f7:	d1 f8                	sar    %eax
100020f9:	50                   	push   %eax
100020fa:	e8 ff 01 00 00       	call   0x100022fe
100020ff:	83 c4 04             	add    $0x4,%esp
10002102:	8b c8                	mov    %eax,%ecx
10002104:	8b 85 ec df ff ff    	mov    -0x2014(%ebp),%eax
1000210a:	99                   	cltd   
1000210b:	f7 f9                	idiv   %ecx
1000210d:	8b b5 d8 df ff ff    	mov    -0x2028(%ebp),%esi
10002113:	0f af f2             	imul   %edx,%esi
10002116:	8b 45 44             	mov    0x44(%ebp),%eax
10002119:	99                   	cltd   
1000211a:	2b c2                	sub    %edx,%eax
1000211c:	d1 f8                	sar    %eax
1000211e:	50                   	push   %eax
1000211f:	e8 da 01 00 00       	call   0x100022fe
10002124:	83 c4 04             	add    $0x4,%esp
10002127:	8b c8                	mov    %eax,%ecx
10002129:	8b c6                	mov    %esi,%eax
1000212b:	99                   	cltd   
1000212c:	f7 f9                	idiv   %ecx
1000212e:	8b 95 d8 df ff ff    	mov    -0x2028(%ebp),%edx
10002134:	2b d0                	sub    %eax,%edx
10002136:	8b 85 ec df ff ff    	mov    -0x2014(%ebp),%eax
1000213c:	8b 4d 0c             	mov    0xc(%ebp),%ecx
1000213f:	8b 54 91 fc          	mov    -0x4(%ecx,%edx,4),%edx
10002143:	89 94 85 f0 df ff ff 	mov    %edx,-0x2010(%ebp,%eax,4)
1000214a:	e9 d0 fe ff ff       	jmp    0x1000201f
1000214f:	c7 85 ec df ff ff 00 	movl   $0x0,-0x2014(%ebp)
10002156:	00 00 00 
10002159:	eb 0f                	jmp    0x1000216a
1000215b:	8b 85 ec df ff ff    	mov    -0x2014(%ebp),%eax
10002161:	83 c0 01             	add    $0x1,%eax
10002164:	89 85 ec df ff ff    	mov    %eax,-0x2014(%ebp)
1000216a:	8b 8d ec df ff ff    	mov    -0x2014(%ebp),%ecx
10002170:	3b 4d 3c             	cmp    0x3c(%ebp),%ecx
10002173:	7f 5b                	jg     0x100021d0
10002175:	8b 95 d8 df ff ff    	mov    -0x2028(%ebp),%edx
1000217b:	52                   	push   %edx
1000217c:	8d 85 f0 df ff ff    	lea    -0x2010(%ebp),%eax
10002182:	50                   	push   %eax
10002183:	8b 8d ec df ff ff    	mov    -0x2014(%ebp),%ecx
10002189:	51                   	push   %ecx
1000218a:	6a 01                	push   $0x1
1000218c:	8b 55 48             	mov    0x48(%ebp),%edx
1000218f:	52                   	push   %edx
10002190:	8b 45 44             	mov    0x44(%ebp),%eax
10002193:	50                   	push   %eax
10002194:	8b 4d 40             	mov    0x40(%ebp),%ecx
10002197:	51                   	push   %ecx
10002198:	8b 55 3c             	mov    0x3c(%ebp),%edx
1000219b:	52                   	push   %edx
1000219c:	8b 45 38             	mov    0x38(%ebp),%eax
1000219f:	50                   	push   %eax
100021a0:	8b 4d 34             	mov    0x34(%ebp),%ecx
100021a3:	51                   	push   %ecx
100021a4:	8b 55 30             	mov    0x30(%ebp),%edx
100021a7:	52                   	push   %edx
100021a8:	8b 45 28             	mov    0x28(%ebp),%eax
100021ab:	50                   	push   %eax
100021ac:	8b 4d 0c             	mov    0xc(%ebp),%ecx
100021af:	51                   	push   %ecx
100021b0:	8b 55 f0             	mov    -0x10(%ebp),%edx
100021b3:	52                   	push   %edx
100021b4:	e8 f5 f4 ff ff       	call   0x100016ae
100021b9:	83 c4 38             	add    $0x38,%esp
100021bc:	68 e1 7a 84 3f       	push   $0x3f847ae1
100021c1:	68 7b 14 ae 47       	push   $0x47ae147b
100021c6:	e8 67 ee ff ff       	call   0x10001032
100021cb:	83 c4 08             	add    $0x8,%esp
100021ce:	eb 8b                	jmp    0x1000215b
100021d0:	83 7d 2c 00          	cmpl   $0x0,0x2c(%ebp)
100021d4:	74 18                	je     0x100021ee
100021d6:	8b 45 3c             	mov    0x3c(%ebp),%eax
100021d9:	50                   	push   %eax
100021da:	8b 4d 38             	mov    0x38(%ebp),%ecx
100021dd:	51                   	push   %ecx
100021de:	8b 55 34             	mov    0x34(%ebp),%edx
100021e1:	52                   	push   %edx
100021e2:	8b 45 f0             	mov    -0x10(%ebp),%eax
100021e5:	50                   	push   %eax
100021e6:	e8 4f f2 ff ff       	call   0x1000143a
100021eb:	83 c4 10             	add    $0x10,%esp
100021ee:	8b 4d 3c             	mov    0x3c(%ebp),%ecx
100021f1:	89 8d ec df ff ff    	mov    %ecx,-0x2014(%ebp)
100021f7:	eb 0f                	jmp    0x10002208
100021f9:	8b 95 ec df ff ff    	mov    -0x2014(%ebp),%edx
100021ff:	83 ea 01             	sub    $0x1,%edx
10002202:	89 95 ec df ff ff    	mov    %edx,-0x2014(%ebp)
10002208:	83 bd ec df ff ff 00 	cmpl   $0x0,-0x2014(%ebp)
1000220f:	7c 5b                	jl     0x1000226c
10002211:	8b 85 d8 df ff ff    	mov    -0x2028(%ebp),%eax
10002217:	50                   	push   %eax
10002218:	8d 8d f0 df ff ff    	lea    -0x2010(%ebp),%ecx
1000221e:	51                   	push   %ecx
1000221f:	8b 95 ec df ff ff    	mov    -0x2014(%ebp),%edx
10002225:	52                   	push   %edx
10002226:	6a ff                	push   $0xffffffff
10002228:	8b 45 48             	mov    0x48(%ebp),%eax
1000222b:	50                   	push   %eax
1000222c:	8b 4d 44             	mov    0x44(%ebp),%ecx
1000222f:	51                   	push   %ecx
10002230:	8b 55 40             	mov    0x40(%ebp),%edx
10002233:	52                   	push   %edx
10002234:	8b 45 3c             	mov    0x3c(%ebp),%eax
10002237:	50                   	push   %eax
10002238:	8b 4d 38             	mov    0x38(%ebp),%ecx
1000223b:	51                   	push   %ecx
1000223c:	8b 55 34             	mov    0x34(%ebp),%edx
1000223f:	52                   	push   %edx
10002240:	8b 45 30             	mov    0x30(%ebp),%eax
10002243:	50                   	push   %eax
10002244:	8b 4d 28             	mov    0x28(%ebp),%ecx
10002247:	51                   	push   %ecx
10002248:	8b 55 0c             	mov    0xc(%ebp),%edx
1000224b:	52                   	push   %edx
1000224c:	8b 45 f0             	mov    -0x10(%ebp),%eax
1000224f:	50                   	push   %eax
10002250:	e8 59 f4 ff ff       	call   0x100016ae
10002255:	83 c4 38             	add    $0x38,%esp
10002258:	68 e1 7a 84 3f       	push   $0x3f847ae1
1000225d:	68 7b 14 ae 47       	push   $0x47ae147b
10002262:	e8 cb ed ff ff       	call   0x10001032
10002267:	83 c4 08             	add    $0x8,%esp
1000226a:	eb 8d                	jmp    0x100021f9
1000226c:	8b 4d f0             	mov    -0x10(%ebp),%ecx
1000226f:	51                   	push   %ecx
10002270:	6a 00                	push   $0x0
10002272:	ff 15 58 30 00 10    	call   *0x10003058
10002278:	5f                   	pop    %edi
10002279:	5e                   	pop    %esi
1000227a:	8b e5                	mov    %ebp,%esp
1000227c:	5d                   	pop    %ebp
1000227d:	c3                   	ret  
 
1000227e:	55                   	push   %ebp
1000227f:	8b ec                	mov    %esp,%ebp
10002281:	c7 05 24 40 00 10 00 	movl   $0x0,0x10004024
10002288:	00 00 00 
1000228b:	c7 05 28 40 00 10 00 	movl   $0x0,0x10004028
10002292:	00 00 00 
10002295:	5d                   	pop    %ebp
10002296:	c3                   	ret    

10002297:	55                   	push   %ebp
10002298:	8b ec                	mov    %esp,%ebp
1000229a:	6a 02                	push   $0x2
1000229c:	6a 30                	push   $0x30
1000229e:	6a 28                	push   $0x28
100022a0:	68 c8 00 00 00       	push   $0xc8
100022a5:	68 fa 00 00 00       	push   $0xfa
100022aa:	68 2c 01 00 00       	push   $0x12c
100022af:	6a 00                	push   $0x0
100022b1:	6a 00                	push   $0x0
100022b3:	6a 01                	push   $0x1
100022b5:	6a 00                	push   $0x0
100022b7:	68 00 00 3e 40       	push   $0x403e0000
100022bc:	6a 00                	push   $0x0
100022be:	6a 00                	push   $0x0
100022c0:	6a 00                	push   $0x0
100022c2:	8b 45 10             	mov    0x10(%ebp),%eax
100022c5:	50                   	push   %eax
100022c6:	8b 4d 0c             	mov    0xc(%ebp),%ecx
100022c9:	51                   	push   %ecx
100022ca:	8b 55 08             	mov    0x8(%ebp),%edx
100022cd:	52                   	push   %edx
100022ce:	e8 b1 f7 ff ff       	call   0x10001a84
100022d3:	83 c4 44             	add    $0x44,%esp
100022d6:	5d                   	pop    %ebp
100022d7:	c3                   	ret    

100022d8:	cc                   	int3   
100022d9:	cc                   	int3   
100022da:	cc                   	int3   
100022db:	cc                   	int3   
100022dc:	cc                   	int3   
100022dd:	cc                   	int3   
100022de:	cc                   	int3   
100022df:	cc                   	int3   
100022e0:	ff 25 2c 30 00 10    	jmp    *0x1000302c
100022e6:	ff 25 30 30 00 10    	jmp    *0x10003030
100022ec:	ff 25 40 30 00 10    	jmp    *0x10003040
100022f2:	ff 25 44 30 00 10    	jmp    *0x10003044
100022f8:	ff 25 48 30 00 10    	jmp    *0x10003048
100022fe:	ff 25 4c 30 00 10    	jmp    *0x1000304c
10002304:	cc                   	int3   
10002305:	cc                   	int3   
10002306:	cc                   	int3   
10002307:	cc                   	int3   
10002308:	cc                   	int3   
10002309:	cc                   	int3   
1000230a:	cc                   	int3   
1000230b:	cc                   	int3   
1000230c:	cc                   	int3   
1000230d:	cc                   	int3   
1000230e:	cc                   	int3   
1000230f:	cc                   	int3   
10002310:	51                   	push   %ecx
10002311:	3d 00 10 00 00       	cmp    $0x1000,%eax
10002316:	8d 4c 24 08          	lea    0x8(%esp),%ecx
1000231a:	72 14                	jb     0x10002330
1000231c:	81 e9 00 10 00 00    	sub    $0x1000,%ecx
10002322:	2d 00 10 00 00       	sub    $0x1000,%eax
10002327:	85 01                	test   %eax,(%ecx)
10002329:	3d 00 10 00 00       	cmp    $0x1000,%eax
1000232e:	73 ec                	jae    0x1000231c
10002330:	2b c8                	sub    %eax,%ecx
10002332:	8b c4                	mov    %esp,%eax
10002334:	85 01                	test   %eax,(%ecx)
10002336:	8b e1                	mov    %ecx,%esp
10002338:	8b 08                	mov    (%eax),%ecx
1000233a:	8b 40 04             	mov    0x4(%eax),%eax
1000233d:	50                   	push   %eax
1000233e:	c3                   	ret    

1000233f:	8b 44 24 08          	mov    0x8(%esp),%eax
10002343:	85 c0                	test   %eax,%eax
10002345:	75 0e                	jne    0x10002355
10002347:	39 05 20 40 00 10    	cmp    %eax,0x10004020
1000234d:	7e 2e                	jle    0x1000237d
1000234f:	ff 0d 20 40 00 10    	decl   0x10004020
10002355:	8b 0d 28 30 00 10    	mov    0x10003028,%ecx
1000235b:	83 f8 01             	cmp    $0x1,%eax
1000235e:	8b 09                	mov    (%ecx),%ecx
10002360:	89 0d 2c 40 00 10    	mov    %ecx,0x1000402c
10002366:	75 3f                	jne    0x100023a7
10002368:	68 80 00 00 00       	push   $0x80
1000236d:	ff 15 38 30 00 10    	call   *0x10003038
10002373:	85 c0                	test   %eax,%eax
10002375:	59                   	pop    %ecx
10002376:	a3 34 40 00 10       	mov    %eax,0x10004034
1000237b:	75 04                	jne    0x10002381
1000237d:	33 c0                	xor    %eax,%eax
1000237f:	eb 66                	jmp    0x100023e7
10002381:	83 20 00             	andl   $0x0,(%eax)
10002384:	a1 34 40 00 10       	mov    0x10004034,%eax
10002389:	68 04 40 00 10       	push   $0x10004004
1000238e:	68 00 40 00 10       	push   $0x10004000
10002393:	a3 30 40 00 10       	mov    %eax,0x10004030
10002398:	e8 eb 00 00 00       	call   0x10002488
1000239d:	ff 05 20 40 00 10    	incl   0x10004020
100023a3:	59                   	pop    %ecx
100023a4:	59                   	pop    %ecx
100023a5:	eb 3d                	jmp    0x100023e4
100023a7:	85 c0                	test   %eax,%eax
100023a9:	75 39                	jne    0x100023e4
100023ab:	a1 34 40 00 10       	mov    0x10004034,%eax
100023b0:	85 c0                	test   %eax,%eax
100023b2:	74 30                	je     0x100023e4
100023b4:	8b 0d 30 40 00 10    	mov    0x10004030,%ecx
100023ba:	56                   	push   %esi
100023bb:	8d 71 fc             	lea    -0x4(%ecx),%esi
100023be:	3b f0                	cmp    %eax,%esi
100023c0:	72 12                	jb     0x100023d4
100023c2:	8b 0e                	mov    (%esi),%ecx
100023c4:	85 c9                	test   %ecx,%ecx
100023c6:	74 07                	je     0x100023cf
100023c8:	ff d1                	call   *%ecx
100023ca:	a1 34 40 00 10       	mov    0x10004034,%eax
100023cf:	83 ee 04             	sub    $0x4,%esi
100023d2:	eb ea                	jmp    0x100023be
100023d4:	50                   	push   %eax
100023d5:	ff 15 34 30 00 10    	call   *0x10003034
100023db:	83 25 34 40 00 10 00 	andl   $0x0,0x10004034
100023e2:	59                   	pop    %ecx
100023e3:	5e                   	pop    %esi
100023e4:	6a 01                	push   $0x1
100023e6:	58                   	pop    %eax
100023e7:	c2 0c 00             	ret    $0xc

100023ea:	55                   	push   %ebp
100023eb:	8b ec                	mov    %esp,%ebp
100023ed:	53                   	push   %ebx
100023ee:	8b 5d 08             	mov    0x8(%ebp),%ebx
100023f1:	56                   	push   %esi
100023f2:	8b 75 0c             	mov    0xc(%ebp),%esi
100023f5:	57                   	push   %edi
100023f6:	8b 7d 10             	mov    0x10(%ebp),%edi
100023f9:	85 f6                	test   %esi,%esi
100023fb:	75 09                	jne    0x10002406
100023fd:	83 3d 20 40 00 10 00 	cmpl   $0x0,0x10004020
10002404:	eb 26                	jmp    0x1000242c
10002406:	83 fe 01             	cmp    $0x1,%esi
10002409:	74 05                	je     0x10002410
1000240b:	83 fe 02             	cmp    $0x2,%esi
1000240e:	75 22                	jne    0x10002432
10002410:	a1 38 40 00 10       	mov    0x10004038,%eax
10002415:	85 c0                	test   %eax,%eax
10002417:	74 09                	je     0x10002422
10002419:	57                   	push   %edi
1000241a:	56                   	push   %esi
1000241b:	53                   	push   %ebx
1000241c:	ff d0                	call   *%eax
1000241e:	85 c0                	test   %eax,%eax
10002420:	74 0c                	je     0x1000242e
10002422:	57                   	push   %edi
10002423:	56                   	push   %esi
10002424:	53                   	push   %ebx
10002425:	e8 15 ff ff ff       	call   0x1000233f
1000242a:	85 c0                	test   %eax,%eax
1000242c:	75 04                	jne    0x10002432
1000242e:	33 c0                	xor    %eax,%eax
10002430:	eb 4e                	jmp    0x10002480
10002432:	57                   	push   %edi
10002433:	56                   	push   %esi
10002434:	53                   	push   %ebx
10002435:	e8 c6 eb ff ff       	call   0x10001000
1000243a:	83 fe 01             	cmp    $0x1,%esi
1000243d:	89 45 0c             	mov    %eax,0xc(%ebp)
10002440:	75 0c                	jne    0x1000244e
10002442:	85 c0                	test   %eax,%eax
10002444:	75 37                	jne    0x1000247d
10002446:	57                   	push   %edi
10002447:	50                   	push   %eax
10002448:	53                   	push   %ebx
10002449:	e8 f1 fe ff ff       	call   0x1000233f
1000244e:	85 f6                	test   %esi,%esi
10002450:	74 05                	je     0x10002457
10002452:	83 fe 03             	cmp    $0x3,%esi
10002455:	75 26                	jne    0x1000247d
10002457:	57                   	push   %edi
10002458:	56                   	push   %esi
10002459:	53                   	push   %ebx
1000245a:	e8 e0 fe ff ff       	call   0x1000233f
1000245f:	85 c0                	test   %eax,%eax
10002461:	75 03                	jne    0x10002466
10002463:	21 45 0c             	and    %eax,0xc(%ebp)
10002466:	83 7d 0c 00          	cmpl   $0x0,0xc(%ebp)
1000246a:	74 11                	je     0x1000247d
1000246c:	a1 38 40 00 10       	mov    0x10004038,%eax
10002471:	85 c0                	test   %eax,%eax
10002473:	74 08                	je     0x1000247d
10002475:	57                   	push   %edi
10002476:	56                   	push   %esi
10002477:	53                   	push   %ebx
10002478:	ff d0                	call   *%eax
1000247a:	89 45 0c             	mov    %eax,0xc(%ebp)
1000247d:	8b 45 0c             	mov    0xc(%ebp),%eax
10002480:	5f                   	pop    %edi
10002481:	5e                   	pop    %esi
10002482:	5b                   	pop    %ebx
10002483:	5d                   	pop    %ebp
10002484:	c2 0c 00             	ret    $0xc

10002487:	cc                   	int3   
10002488:	ff 25 50 30 00 10    	jmp    *0x10003050
