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

    while(!feof(arq)) {
        fgets(buffer, sizeof(buffer), arq);
        count++;
    }

    printf("\nNúmero de linhas do arquivo: %d\n\n", count);
    return 0;
}