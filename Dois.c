#include <stdio.h>
#include <string.h>

#define maxNota 3
#define maxAluno 2

typedef struct {
    char nome[maxAluno][200];
    float notas[maxAluno][maxNota];
    float media[maxAluno];
    char msg[50];
} Aluno;

void calcularMedia(Aluno *aluno) {
    aluno->media[maxAluno] = (aluno->notas[maxAluno][0] + aluno->notas[maxAluno][1] + aluno->notas[maxAluno][2]) / maxNota;
}   

int main() {
    Aluno aluno;

    int i, j;

    for (i = 0; i < maxAluno; i++) {
        printf("Digite seu nome: ");
        gets(aluno.nome);

        for (j = 0; j < maxNota; j++) {
            printf("Digite sua %d nota: ", j + 1);
            scanf("%f", &aluno.notas[j]);
        }

        fflush(stdin);
    }
 
    calcularMedia(&aluno);

    if (aluno.media >= 7) strcpy(aluno.msg, "Aprovado");
    else if (aluno.media >= 5 && aluno.media < 7) strcpy(aluno.msg, "Recuperacao");
    else strcpy(aluno.msg, "Reprovado");


    printf("\nResultado\n\n");

    for (i = 0; i < maxAluno; i++) {
        printf("Nome: %s\n", aluno.nome);

        for (j = 0; j < maxNota; j++) {
            printf("%d)- Nota: %.1f\n", j + 1, aluno.notas[j]);
            printf("Media: %.2f\n", aluno.media[j]);
            printf("Aprovacao: %s\n", aluno.msg[j]);
        }
    }


    return 0;
}