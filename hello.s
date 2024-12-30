.section .data
message:    .asciz "Hello, World!\n"

.section .text
.global _start

_start:
    # Carrega o endereço da mensagem na área de dados
    la a1, message        # a1 = endereço da mensagem
    li a0, 1              # a0 = 1 (stdout)
    li a2, 12             # a2 = tamanho da mensagem
    li a7, 64             # a7 = syscall_write
    ecall                 # Chamada de sistema para escrever

    # Finaliza o programa
    li a0, 0              # Código de saída
    li a7, 93             # a7 = syscall_exit
    ecall                 # Chamada de sistema para sair
