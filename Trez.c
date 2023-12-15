#include <stdio.h>

// Definindo a struct Produto
struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

// Função para calcular o valor total em estoque
float calcularValorTotal(struct Produto produto) {
    return produto.preco * produto.quantidade;
}

// Função para atualizar a quantidade em estoque com base em uma compra
void realizarCompra(struct Produto *produto, int quantidadeComprada) {
    if (quantidadeComprada > 0) {
        produto->quantidade += quantidadeComprada;
        printf("%d unidades de %s foram adicionadas ao estoque.\n", quantidadeComprada, produto->nome);
    } else {
        printf("Quantidade inválida. A compra não foi realizada.\n");
    }
}

int main() {
    // Inicializando um produto
    struct Produto meuProduto = {"Produto A", 10.99, 50};

    int escolha;
    int quantidadeComprada;

    do {
        // Exibindo o menu
        printf("\nMenu:\n");
        printf("1- Adicionar produto.\n");
        printf("2- Realizar uma compra.\n");
        printf("3- Consultar estoque.\n");
        printf("4- Sair do programa.\n");

        // Lendo a escolha do usuário
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                // Exibindo informações do produto
                printf("\nInformações do produto:\n");
                printf("Nome: %s\n", meuProduto.nome);
                printf("Preço: R$%.2f\n", meuProduto.preco);
                printf("Quantidade em estoque: %d unidades\n", meuProduto.quantidade);
                break;

            case 2:
                // Realizando uma compra
                printf("\nDigite a quantidade a ser comprada: ");
                scanf("%d", &quantidadeComprada);
                realizarCompra(&meuProduto, quantidadeComprada);
                break;

            case 3:
                // Consultando o estoque
                printf("\nQuantidade em estoque: %d unidades\n", meuProduto.quantidade);
                printf("Valor total em estoque: R$%.2f\n", calcularValorTotal(meuProduto));
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
