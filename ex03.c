#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAMANHO_BUFFER 128

int main() {

    setlocale(LC_ALL, "Portuguese");

    const char *nome_origem = "aula02.txt";
    const char *nome_destino = "aula02_copia.txt";
    char buffer[TAMANHO_BUFFER];

    int arq_entrada = open(nome_origem, O_RDONLY);
    int arq_saida = open(nome_destino, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (arq_entrada == -1 || arq_saida == -1) {
        printf("Houve um erro na abertura de um dos arquivos.\n");
        if (arq_entrada != -1) close(arq_entrada);
        if (arq_saida != -1) close(arq_saida);
        return -1;
    } 
    
    printf("Arquivos abertos com sucesso!\n");

    ssize_t bytes_lidos;
    while ((bytes_lidos = read(arq_entrada, buffer, sizeof(buffer))) > 0) {
        if (write(arq_saida, buffer, bytes_lidos) != bytes_lidos) {
            printf("Erro ao escrever no arquivo de destino.\n");
            close(arq_entrada);
            close(arq_saida);
            return -1;
        }
    }

    if (bytes_lidos == -1) {
        printf("Erro ao ler o arquivo de origem.\n");
        close(arq_entrada);
        close(arq_saida);
        return -1;
    }

    printf("\nCópia realizada com sucesso!\n");

    close(arq_entrada);
    close(arq_saida);

    return 0;
}
