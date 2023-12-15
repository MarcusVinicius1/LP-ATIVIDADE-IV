#include <stdio.h>

struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
};

float calcularMediaSalarial(struct Funcionario *funcionarios, int numFuncionarios, const char *cargoAlvo) {
    int count = 0;
    float somaSalarios = 0.0;

    for (int i = 0; i < numFuncionarios; ++i) {
        if (strcmp(funcionarios[i].cargo, cargoAlvo) == 0) {
            somaSalarios += funcionarios[i].salario;
            count++;
        }
    }

    if (count > 0) {
        return somaSalarios / count;
    } else {
        return 0.0;
    }
}

int main() {
    struct Funcionario funcionarios[] = {
        {"João", "Programador", 5000.0},
        {"Maria", "Analista", 4500.0},
        {"Carlos", "Programador", 5500.0},
        {"Ana", "Gerente", 7000.0}
    };

    int numFuncionarios = sizeof(funcionarios) / sizeof(funcionarios[0]);

    const char cargoAlvo[] = "Programador";
    float mediaSalarialProgramadores = calcularMediaSalarial(funcionarios, numFuncionarios, cargoAlvo);

    if (mediaSalarialProgramadores > 0.0) {
        printf("A média salarial dos programadores é: R$%.2f\n", mediaSalarialProgramadores);
    } else {
        printf("Não há programadores na empresa.\n");
    }

    return 0;
}
