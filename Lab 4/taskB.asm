[BITS 16]
[ORG 0x7C00]
top:
        ;; Put 0 into ds (data segment)
        ;; Can't do it directly
        mov ax,0x0000
        mov ds,ax
        ;; si is the location relative to the data segment of the
        ;; string/char to display
        mov si, Name
        call writeString ; See below
        int 21h
        
        mov si, Course
        call writeString ; See below
        int 21h
        
        mov si, Os
        call writeString ; See below
        int 21h
        
        mov si, dotSpace
        call writeString ; See below
        int 21h

        mov si, dot
        call writeString ; See below
        int 21h

                
        mov si, dotSpace
        call writeString ; See below
        int 21h

        jmp $ ; Spin
writeString:
        mov ah,0x0E ; Display a chacter (as before)
        mov bh,0x00
        mov bl,0x07
nextchar:
        Lodsb ; Loads [SI] into AL and increases SI by one
        ;; Effectively "pumps" the string through AL
        cmp al,0 ; End of the string?
        jz done
        int 0x10
        jmp nextchar
done:
        ret
        Name db 'Guilherme Miguel',13,10,0
        Course db 'Computer Science',13,10,0
        Os db 'Ubuntu Linux',13,10,0 ; Null-terminated
        dotSpace db ' . ',13, 10, 0;
        dot db '...',13, 10, 0;
        times 510-($-$$) db 0
        dw 0xAA55

