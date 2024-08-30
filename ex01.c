#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_BUFFER 1024

int main() {
    const char *nome_arq = "aula02.txt";
    char buffer[TAMANHO_BUFFER];

    int arq = open(nome_arq, O_RDWR);

    if(arq == -1) {
        printf("Erro na abertura do arquivo\n\n");
        return -1;
    }
    else { 
        printf("Arquivo aberto com sucesso\n\n");
    }

    read(arq, buffer, sizeof(buffer));
    buffer[strlen(buffer) + 1] = '\0';

    printf("%s\n", buffer);
    return 0;
}
