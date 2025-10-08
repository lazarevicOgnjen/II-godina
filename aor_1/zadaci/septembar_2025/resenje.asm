; sum_expr.asm
; računa SUM = sum_{i=5..n} ( (n+i)/(i-1) + (n-i)^2 )
; N - dd (32-bit) ulaz, SUM - dq (64-bit) izlaz

SECTION .data
N   dd 10        ; primer: n = 10 (možete zameniti)
SUM dq 0

SECTION .text
global _start

_start:
    ; load n (32-bit) -> r9 (signed 64-bit)
    mov     eax, DWORD [rel N]
    movsxd  r9, eax        ; r9 = n (signed 64)

    xor     rsi, rsi       ; rsi = accumulator SUM = 0 (64-bit)

    ; if n < 5 -> SUM = 0, kraj
    cmp     r9, 5
    jl      store_and_exit

    mov     rcx, 5         ; i = 5 (64-bit)

loop_i:
    ; --- izračun (n+i)/(i-1)  (64-bit signed div) ---
    mov     rax, r9        ; rax = n
    add     rax, rcx       ; rax = n + i
    cqo                    ; sign-extend rax -> rdx:rax
    mov     rdi, rcx
    dec     rdi            ; rdi = i-1
    idiv    rdi            ; rax = quotient = (n+i)/(i-1)
    mov     r10, rax       ; r10 = term1

    ; --- izračun (n-i)^2 ---
    mov     rax, r9        ; rax = n
    sub     rax, rcx       ; rax = n - i
    imul    rax, rax       ; rax = (n-i)^2  (64-bit signed multiply safe here)
    ; sada rax = term2

    add     rax, r10       ; rax = term1 + term2

    add     rsi, rax       ; SUM += term1 + term2

    ; i++
    inc     rcx
    cmp     rcx, r9
    jle     loop_i

store_and_exit:
    mov     [rel SUM], rsi ; spremi 64-bit SUM u memoriju

    ; exit syscall (return code 0)
    mov     rax, 60
    xor     rdi, rdi
    syscall
