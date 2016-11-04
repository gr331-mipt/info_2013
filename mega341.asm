include io.asm
.386
.model flat

.data
buf	db 101 dup(0)
sz_buf	equ $ - buf

.code


; parameter: dl = char to analyse
; return: eax = 1 if dl is Latin, eax = 0 otherwise
isLatin proc
	xor eax, eax
	cmp dl, 'A'		; if (c >= 'A' &&
	jb short end_if ; skip_And
	cmp dl, 'Z'		;	c <= 'Z' ||
	jbe short body_if
; skip_And:
	cmp dl, 'a'		;	c >= 'a' &&
	jb short end_if
	cmp dl, 'z'		;	c <= 'z')
	ja short end_if
body_if:
		inc eax
end_if:
	ret
isLatin endp

; 3) Text begins and ends with Latin characters
check proc
	xor eax, eax
	mov esi, -1
length_cycle:			; for (n = 0; s[n]; n++);
	inc esi
	cmp buf[esi], 0
	jne short length_cycle

	test esi, esi		; if (n == 0)   return 0;
	jz short exit_check

	mov dl, buf[0]
	call isLatin
	test eax, eax		; if (isLatin(s[0]) &&
	jz short exit_check
	mov dl, buf[esi-1]
	call isLatin		; 	isLatin(s[n-1]))

exit_check:
	ret
check endp


; 4) Replace each lower-case letter with corresponding upper-case one
rule1 proc
	mov esi, 0
rule1_cycle:			; for (i = 0; s[i]; i++)
	cmp buf[esi], 0
	je short exit_rule1_cycle
		cmp buf[esi], 'a'	; if (s[i] >= 'a' &&
		jb short exit_rule1_if
		cmp buf[esi], 'z'	;	s[i] <= 'z')
		ja short exit_rule1_if
			sub buf[esi], 'a' - 'A'
exit_rule1_if:
	inc esi
	jmp short rule1_cycle
exit_rule1_cycle:
	ret
rule1 endp


; 1) Move all digits to beginning of text, saving order
rule2 proc
	cmp buf, 0		; if (s[0] == '\0')
	je short exit_rule2_cycle	; return;
	mov esi, 1
rule2_cycle:			; for (i = 1; s[i]; i++)
	cmp buf[esi], 0
	je short exit_rule2_cycle
		cmp buf[esi], '0'	; if (s[i] >= '0' &&
		jb short exit_rule2_if
		cmp buf[esi], '9'	;	s[i] <= '9')
		ja short exit_rule2_if
			mov cl, buf[esi]
			mov edi, esi		; j = i - 1
			dec edi
rule2_for:
			test edi, edi		; j >= 0
			jl short exit_rule2_for
			cmp buf[edi], '0'	; s[j] < '0' ||
			jb short body_rule2_for
			cmp buf[edi], '9'	; s[j] > '9'
			jbe short exit_rule2_for
body_rule2_for:
				mov ch, buf[edi]	; s[j+1] = s[j]
				mov buf[edi+1], ch
				dec edi
				jmp short rule2_for
exit_rule2_for:
			mov buf[edi+1], cl
exit_rule2_if:
	inc esi
	jmp short rule2_cycle
exit_rule2_cycle:
	ret
rule2 endp


WinMain proc
	gets sz_buf, offset buf
	puts offset buf
	newln

	call check
	test eax, eax
	jz short do_rule2
		call rule1
		jmp short exit_main_check
do_rule2:
		call rule2
exit_main_check:

	puts offset buf
	newln

	exit 0
WinMain endp

end WinMain
