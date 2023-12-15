#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[15];
    char email[50];
};

char* buscar_numero(char nome_busca[50], struct Contato contatos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(contatos[i].nome, nome_busca) == 0) {
            return contatos[i].telefone;
        }
    }
    return "Contato não encontrado.";
}

int main() {
    struct Contato contatos[3]
    
    for (int i = 0; i < 3; i++) {
        printf("Digite o nome do contato %d: ", i+1);
        scanf("%s", contatos[i].nome);
        printf("Digite o número de telefone do contato %d: ", i+1);
        scanf("%s", contatos[i].telefone);
        printf("Digite o email do contato %d: ", i+1);
        scanf("%s", contatos[i].email);
    }

    char nome_busca[50];
    printf("Digite o nome do contato que deseja buscar: ");
    scanf("%s", nome_busca);

    char* numero_telefone = buscar_numero(nome_busca, contatos, 3);
    printf("O número de telefone de %s é: %s\n", nome_busca, numero_telefone);

    return 0;
}
