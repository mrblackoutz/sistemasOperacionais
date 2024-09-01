#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <locale.h> 
#include <stdlib.h> 
#include <string.h>

#define BUFFER 128

int main() {
    const char* nomeArquivo = "aula02.txt";
    char buffer[BUFFER];

    setlocale(LC_ALL, "Portuguese");

    int fd = open(nomeArquivo, O_RDONLY);
    if (fd == -1) {
        printf("Erro na abertura do arquivo.\n");
        return -1;
    }

    int count = 0;
    int bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0';
        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {
                count++;
            }
        }
    }

    if (bytesRead == 0 && buffer[strlen(buffer) - 1] != '\n') {
        count++;
    }

    printf("\nNúmero de linhas do arquivo: %d\n\n", count);

    close(fd);

    return 0;
}
