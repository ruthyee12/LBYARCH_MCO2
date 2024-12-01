section .text
bits 64
default rel
global distance_asm

distance_asm:
    ; Parameters:
    ; RCX: n (number of points)
    ; RDX: X1 (pointer to X1 array)
    ; R8:  X2 (pointer to X2 array)
    ; R9:  Y1 (pointer to Y1 array)
    ; [RSP+40]: Y2 (pointer to Y2 array)
    ; [RSP+48]: Z  (pointer to Z array)

    mov r10, [rsp+40]    
    mov r11, [rsp+48]    

L1:
    test rcx, rcx        
    jz done            

    movss xmm0, [r8]     
    subss xmm0, [rdx]  
    mulss xmm0, xmm0    
    movss xmm1, [r10]   
    subss xmm1, [r9]     
    mulss xmm1, xmm1    
    addss xmm0, xmm1    
    sqrtss xmm0, xmm0  
    movss [r11], xmm0   


    add rdx, 4           ; X1++
    add r8, 4            ; X2++
    add r9, 4            ; Y1++
    add r10, 4           ; Y2++
    add r11, 4           ; Z++

    dec rcx              
    jmp L1              

done:
    ret
