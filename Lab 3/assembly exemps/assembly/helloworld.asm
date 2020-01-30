section .data ;; The section of the assembly code is where we 
			; keep the constants
	hello db "Hello world!",10 ;;declare constant hello that 
			; points to �Hello world!� 10 equates to the 
			; line character
	helloLen equ $-hello ;; This returns the length of the 
					; �Hello world!� string
section .text ;; This is the section where the assembly code 
		    ; is stored
	global _start
 	_start
	mov eax,4 ;; Move the system call 4 to the register eax 
			; to say ouput
	mov ebx,1 ;;  put the value 1 in the register ebx - 
			; standard output to the screen
	mov ecx, hello ; Put the offset of hello in ecx register 
				; so we can access the string 'hello 
				; world' and the new line character
	mov edx, helloLen ;; put the length of the 'hello world' 
				   ; string into the register
	int 80h ; Call the operating system with an interrupt.  
	mov eax,4 ;; Move the system call 4 to the register eax 
			; to say ouput
	mov ebx,1 ;;  put the value 1 in the register ebx - 
			; standard output to the screen
	mov ecx, hello ; Put the offset of hello in ecx register 
				; so we can access the string 'hello 
				; world' and the new line character
	mov edx, helloLen ;; put the length of the 'hello world' 
				   ; string into the register
	int 80h ; Call the operating system with an interrupt. 
		   ; The operating system checks the registers and 
		   ; performs the operation to write to screen
	mov eax,1 ; Put 1 in eax which equates to the system call 
			; for exit (sys_exit)
	mov ebx,0 ; Put 0 in ebx which is the exit value 0 (no 
			; error)
	int 80h; Call the operating system with an interrupt.  
		  ; The operating system checks the registers and 
		  ; performs the exit operation 
	
