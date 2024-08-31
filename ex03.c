#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
# include <locale.h>

#define TAMANHO_BUFFER 128

int main() {

    setlocale(LC_ALL, "Portuguese");

    const char *nome_origem = "aula02.txt";
    const char *nome_destino = "aula02_copia.txt";
    char buffer[TAMANHO_BUFFER];

    int arq_entrada = open(nome_origem, O_RDONLY);
    int arq_saida = open(nome_destino, O_WRONLY | O_CREAT | O_TRUNC);

    if (arq_entrada == -1 || arq_saida == -1) {
        printf("Houve um erro na abertura de um dos arquivos");
        return -1;
    } 
    
    printf("Arquivos abertos com sucesso!");

    read(arq_entrada, buffer, sizeof(buffer));

    buffer[strlen(buffer) - 1] = '\0';

    write(arq_saida, buffer, strlen(buffer) - 1);

    printf("\nCópia realizada com sucesso!");
    return 0;
}