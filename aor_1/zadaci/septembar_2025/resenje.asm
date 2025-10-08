section .data
    N    dd 10         ; 32-bitni ulazni broj
    SUM  dq 0          ; 64-bitna lokacija za rezultat

section .text
    mov eax, [N]       ; Učitavanje N u EAX
    mov ecx, 5         ; Početak petlje od i=5
    mov edx, 0         ; Inicijalizacija SUM na 0

loop_start:
    cmp ecx, eax       ; Provjeri da li smo stigli do N
    jg loop_end        ; Ako jeste, izlazimo iz petlje

    ; Izračunavanje (n + i)/(i - 1)
    mov ebx, eax       ; Prenos N u EBX
    add ebx, ecx       ; EBX = N + i
    sub ecx, 1         ; ECX = i - 1
    xor edx, edx       ; Postavljanje EDX na 0 za dijeljenje
    div ecx            ; EAX = (N + i)/(i - 1), EDX = ostatak
    add edx, eax       ; Dodavanje u SUM

    ; Izračunavanje (n - i)^2
    mov eax, [N]       ; Prenos N u EAX
    sub eax, ecx       ; EAX = N - i
    imul eax, eax      ; EAX = (N - i)^2
    add edx, eax       ; Dodavanje u SUM

    ; Postavljanje SUM na 64-bitnu lokaciju
    mov [SUM], rdx

    ; Povratak na petlju
    inc ecx            ; Povećanje i
    jmp loop_start

loop_end:
    ret
