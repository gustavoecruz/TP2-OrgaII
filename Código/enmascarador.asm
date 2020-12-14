section .data

section .text
global _enmascarar_asm

_enmascarar_asm:
    ;enter
    PUSH EBP
    MOV	 EBP, ESP
    
    ;recibo parámetros (punteros a rgb)
    MOV EAX, [EBP+8]    ;img1
    MOV EBX, [EBP+12]   ;img2
    MOV EDX, [EBP+16]   ;mask
    MOV ECX, [EBP+20]   ;cantidad de bytes

iterar:
    CMP ECX, 0 ;si mi cantidad de bytes es 0, ya recorri todo
    JE salir
    
    ;guardo en los registros los punteros de las img y mask
    MOVUPS XMM0, [EAX]
    MOVUPS XMM1, [EBX]
    MOVUPS XMM2, [EDX]
    
    PAND    XMM1, XMM2  ;en la img2 dejo la parte negra de la mascara
    POR     XMM0, XMM2  ;en la img1 dejo la parte blanca de la mascara
    PXOR    XMM0, XMM2  ;correcion de pixeles
    PADDB   XMM0, XMM1  ;sumo img1 y img2
    MOVUPS  [EAX], XMM0

    ;muevo los punteros    
    ADD EAX, 16
    ADD EBX, 16
    ADD EDX, 16
    SUB ECX, 16
    JMP iterar

salir:
    ;leave
    MOV ESP, EBP
    POP EBP
    RET
