;; using a nested loop create a 10 by 10 square
section .data
        global _start
        char db ' ' ; declare char to store dots and newlines
segment .bss
    uInput resb 1
section .text
_start:
	;;Getting User Input
    mov eax, 3 ; system call input
    mov ebx, 0 ; stand input
    mov ecx, uInput ; store inputted value in num1 - note ascii 
				; value and should be between 1-9
    mov edx, 1 ; size of input value in bytes
    int 80h ; call kernel with interrupt to receive value
	;; use ax for the row counter
	mov rax, [uInput] ; move value in num1 into rax
    sub rax, 48; subtract 48 from value so now it is integer 
			   ; and not ascii value
    mov [uInput], rax ; move value back into num1 
        ;; use ax for the row counter
    mov rax, [uInput]; move num1 into rax to set the size of 
				 ; the outer loop - rows of triangle
	outer_loop:
        	;; use ax for the row counter
        	mov rbx, [uInput] ; move squaresize into rbx to 
		; set the size of the inner loop - column of triangle
		inc bx
		inner_loop:
			;; draw a dot
			call dot
			;; subtract from the counter
			;; and repeat if we haven't hit 0 for inner loop
			dec bx
			cmp bx, ax
			jg inner_loop
		;; go on to next line
		call linefeed
		;; subtract from the counter
		;; and repeat if we haven't hit 0 for outer loop	
		dec ax
		cmp ax, 0
		jne outer_loop
		;; go to next line
		call linefeed
		;; exit cleanly
		call exit
;; Some useful routines that I can call many times
;; or even copy and paste into other code
	
exit:	
	mov eax,1; system call to exit            
	mov ebx,0; exit value             
	int 80h; call kernel with interrupt to exit program
	ret
;; new line code section
linefeed:	
	;; move newline character into char
	mov [char],  byte 10
	push rax; push rax on to stack to allow outer loop to occur
	push rbx; push rbx on to stack to allow inner loop to occur 
	mov eax,4; system call to write out           
	mov ebx,1; standard out to screen 
	mov ecx, char; go to next line on screen 
	mov edx,1; size of new line
	int 80h; interrupt to kernel to go to next line by looking 
			; into registers
	pop rbx; pop rbx on to stack to allow outer loop to occur
	pop rax; pop rax on to stack to allow inner loop to occur 
	ret
	
dot:	

	mov [char],  byte '+'; put dot (.) in char
	push rax; push rax on to stack to allow outer loop to occur
	push rbx; push rbx on to stack to allow inner loop to occur 
	mov eax,4; system call to write out           
	mov ebx,1; standard out to screen 
	mov ecx, char; put dot in register ecx 
	mov edx,1; size of dot in register
	int 80h; interrupt to kernel to print dot on screen by 
   			; looking into registers         
	pop rbx
	pop rax

	ret