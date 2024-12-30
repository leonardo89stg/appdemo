[bits 16]               ; Especifica que o código estará no modo real (16-bit)
[org 0x7c00]            ; Define a posição do carregamento do bootloader (em 0x7C00 na memória)

start:
    ; Limpa a tela
    mov ah, 0x0e
    mov al, '>'
    int 0x10

    ; Carregar o Kernel
    mov ah, 0x02            ; Função para ler setor do disco
    mov al, 1               ; Número de setores a ler (1 setor)
    mov ch, 0               ; Cabeçalho do cilindro
    mov cl, 2               ; Setor de partida (primeiro setor após o bootloader)
    mov dh, 0               ; Cabeçalho da cabeça
    mov dl, 0x80            ; Disco a ser lido (primeiro disco rígido, 0x80)
    int 0x13                ; Interrupção para ler o disco

    ; Pular para o Kernel carregado
    jmp 0x0000:0x1000       ; O kernel foi carregado no endereço 0x1000 (ajuste conforme necessário)

times 510-($-$$) db 0       ; Preenche até 510 bytes
dw 0xAA55                   ; Assinatura do setor de inicialização (0xAA55)
