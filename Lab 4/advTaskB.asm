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
        
        mov si, size ; print instructions for user
        call writeString
        
        mov ah, 00h
        int 16h
        
        sub al, 48 ; each number is equal to its ascii code - 48
        mov ch, al; num of top of diamond lines
        mov cl, 1 ; num of starting stars
        mov dh, ch
        mov dl, cl 
        mov si, linebreak
        call writeString
        call rowLoop               
        call rowLoopReverse

        
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
   
rowLoop:
        lineSpaceLoop:  ; writes the required num of spaces to screen
                      mov si, spaceChar
                      call writeString
                      dec dh
                      cmp dh, 0
                      jg lineSpaceLoop
        lineStarLoop:   ; writes the required num of stars to screen
                      mov si, starChar
                      call writeString
                      dec dl
                      cmp dl, 0
                      jg lineStarLoop
                      mov si, linebreak
                      call writeString

        ; every time it loops will decrease one space but add 2 stars
        dec ch
        add cl, 2 
        mov dl, cl
        mov dh, ch             
        cmp dh, 1
        jg rowLoop
rowLoopReverse:
; here the same as above happens but in reverse
        lineSpaceLoopReverse: 
       	              mov si, spaceChar
                      call writeString
                      dec dh
                      cmp dh, 0
                      jg lineSpaceLoopReverse
        lineStarLoopReverse:
       	              mov si, starChar
                      call writeString
                      dec dl
                      cmp dl, 0
                      jg lineStarLoopReverse
                      mov si, linebreak
                      call writeString 
        inc ch
        sub cl, 2
        mov dl, cl
        mov dh, ch                 
        cmp dh, 3
        jl rowLoopReverse
done:
        ret
        Name db 'Guilherme Miguel',13,10,0
        Course db 'Computer Science',13,10,0
        Os db 'Ubuntu Linux',13,10,0 ; Null-terminated
        size db 'Input Diamond top part line size'
        spaceChar db ' ',0 ;
        starChar db '*',0
        linebreak db '',13,10,0 
        times 510-($-$$) db 0
        dw 0xAA55