#include <stdio.h>

struct Aluno {
    char nome[50];
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    float nota[2];
    float media;
};

float calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2;
}

int main() {
    struct Aluno alunos[5];

    // Preencher os dados dos alunos
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do aluno %d: ", i+1);
        scanf("%s", alunos[i].nome);
        printf("Digite o dia de nascimento do aluno %d: ", i+1);
        scanf("%d", &alunos[i].diaNascimento);
        printf("Digite o mês de nascimento do aluno %d: ", i+1);
        scanf("%d", &alunos[i].mesNascimento);
        printf("Digite o ano de nascimento do aluno %d: ", i+1);
        scanf("%d", &alunos[i].anoNascimento);
        
        for (j = 0; j <= 2; j++) {
           printf("Digite a %d nota do aluno: ", i+1);
           scanf("%f", &alunos[i].nota);
        }

        // Calcular a média do aluno
        alunos[i].media = calcularMedia(alunos[i]);
    }

    // Imprimir a média de cada aluno
    for (int i = 0; i < 5; i++) {
        printf("A média do aluno %s é %.2f\n", alunos[i].nome, alunos[i].media);
    }

    return 0;
}
