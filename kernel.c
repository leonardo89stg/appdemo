void _start() {
    // Definir o ponteiro para a memória de vídeo
    char *video_memory = (char *)0xB8000;

    // Mensagem a ser exibida na tela
    const char *message = "Hello, World from C!";
    
    // Escrever a mensagem na memória de vídeo
    for (int i = 0; message[i] != '\0'; i++) {
        video_memory[i * 2] = message[i];      // Caractere
        video_memory[i * 2 + 1] = 0x07;        // Atributo (cor branca)
    }

    // Loop infinito para impedir que o código se "desvie"
    while (1);
}
