#include <stdint.h>

#define KERNEL_START_ADDR 0x80000000 // Endereço onde o kernel será carregado na memória

// Função que inicializa o processador e configura a memória
void init_system() {
    // Configuração do Stack Pointer (Ponteiro da pilha) - Exemplo de endereço
    uint64_t stack_pointer = 0x80010000;
    asm volatile("mv sp, %0" : : "r" (stack_pointer));

    // Limpeza de registradores (opcional)
    asm volatile("li t0, 0"); // Zera o registrador t0
}

// Função que carrega o kernel (simulação de carregamento)
void load_kernel(uint32_t* kernel_address) {
    // Em um bootloader real, isso envolveria a leitura do kernel a partir de uma mídia de armazenamento.
    // Aqui estamos assumindo que o kernel já está em uma posição fixa na memória (KERNEL_START_ADDR).
    // Simulando o carregamento do kernel para o endereço de início.

    for (int i = 0; i < 1024; i++) {
        kernel_address[i] = 0xDEADBEEF; // Apenas uma simulação de carga de dados
    }
}

// Função que transfere controle para o kernel
void jump_to_kernel(uint32_t* kernel_entry_point) {
    // O ponteiro para a entrada do kernel é passado como parâmetro e é chamado
    void (*kernel_entry)(void) = (void (*)(void)) kernel_entry_point;
    kernel_entry();  // Chama a função inicial do kernel
}

// Função principal do bootloader
void bootloader_main() {
    // Passo 1: Inicializar o sistema
    init_system();

    // Passo 2: Carregar o kernel para a memória
    uint32_t* kernel = (uint32_t*) KERNEL_START_ADDR;
    load_kernel(kernel);

    // Passo 3: Transferir controle para o kernel
    jump_to_kernel(kernel);
}
