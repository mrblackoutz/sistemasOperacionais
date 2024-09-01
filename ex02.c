# include <stdio.h>
# include <locale.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER 128

int main() {
    const char* nomeArquivo = "aula02.txt";
    char buffer[BUFFER];

    setlocale(LC_ALL, "Portuguese");

    FILE *arq = fopen(nomeArquivo, "r");

    if (arq == NULL) {
        printf("Erro na abertura do arquivo.\n");
        return -1;
    }

    int count = 0;

    while (fgets(buffer, sizeof(buffer), arq) != NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == '\n') {
                count++;
            }
        }
    }
    
    if (strlen(buffer) > 0 && buffer[strlen(buffer) - 1] != '\n') {
        count++;
    }

    printf("\nNúmero de linhas do arquivo: %d\n\n", count);
    return 0;
}
