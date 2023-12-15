#include <stdio.h>

// Definindo a struct contaBancaria
struct contaBancaria {
    int numeroConta;
    char nomeTitular[50];
    float saldo;
    char tipoConta[20];
};

// Função para depositar dinheiro na conta
void depositar(struct contaBancaria *conta, float valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Depósito de R$%.2f realizado com sucesso.\n", valor);
    } else {
        printf("Valor inválido. O depósito não foi realizado.\n");
    }
}

// Função para sacar dinheiro da conta
void sacar(struct contaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso.\n", valor);
    } else {
        printf("Valor inválido ou saldo insuficiente. O saque não foi realizado.\n");
    }
}

// Função para imprimir o saldo atual
void imprimirSaldo(struct contaBancaria conta) {
    printf("Saldo atual da conta: R$%.2f\n", conta.saldo);
}

int main() {
    // Inicializando uma conta bancária
    struct contaBancaria minhaConta = {12345, "João Silva", 1000.0, "Corrente"};

    int escolha;
    float valor;

    do {
        // Exibindo o menu
        printf("\nMenu:\n");
        printf("1- Depositar dinheiro.\n");
        printf("2- Sacar dinheiro.\n");
        printf("3- Imprimir saldo.\n");
        printf("4- Sair do programa.\n");

        // Lendo a escolha do usuário
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                // Realizando um depósito
                printf("\nDigite o valor a ser depositado: ");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;

            case 2:
                // Realizando um saque
                printf("\nDigite o valor a ser sacado: ");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;

            case 3:
                // Imprimindo o saldo
                imprimirSaldo(minhaConta);
                break;

            case 4:
                // Saindo do programa
                printf("Saindo do programa.\n");
                break;

            default:
                // Mensagem para opção inválida
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 4);

    return 0;
}
