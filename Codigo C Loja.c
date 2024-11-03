#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRUTAS 100
#define NOME_MAX 50
#define ARQUIVO_VENDAS "vendas.txt"

typedef struct {
    char nome[NOME_MAX];
    float preco;
    int quantidade;
} Fruta;

Fruta frutas[MAX_FRUTAS];
int num_frutas = 0;

void cadastrar_fruta() {
    if (num_frutas >= MAX_FRUTAS) {
        printf("Limite de frutas atingido!\n");
        return;
    }
    Fruta nova_fruta;
    printf("Nome da fruta: ");
    scanf("%s", nova_fruta.nome);
    printf("Preco: ");
    scanf("%f", &nova_fruta.preco);
    printf("Quantidade: ");
    scanf("%d", &nova_fruta.quantidade);
    frutas[num_frutas++] = nova_fruta;
    printf("Fruta cadastrada com sucesso!\n");
}

void listar_frutas() {
    printf("Frutas cadastradas:\n");
    for (int i = 0; i < num_frutas; i++) {
        printf("%d. %s - R$%.2f - %d unidades\n", i + 1, frutas[i].nome, frutas[i].preco, frutas[i].quantidade);
    }
}

Fruta* buscar_fruta(const char* nome) {
    for (int i = 0; i < num_frutas; i++) {
        if (strcmp(frutas[i].nome, nome) == 0) {
            return &frutas[i];
        }
    }
    return NULL;
}

void alterar_fruta() {
    char nome[NOME_MAX];
    printf("Nome da fruta a ser alterada: ");
    scanf("%s", nome);
    Fruta* fruta = buscar_fruta(nome);
    if (fruta) {
        printf("Novo preco: ");
        scanf("%f", &fruta->preco);
        printf("Nova quantidade: ");
        scanf("%d", &fruta->quantidade);
        printf("Fruta alterada com sucesso!\n");
    } else {
        printf("Fruta não encontrada!\n");
    }
}

void excluir_fruta() {
    char nome[NOME_MAX];
    printf("Nome da fruta a ser excluída: ");
    scanf("%s", nome);
    for (int i = 0; i < num_frutas; i++) {
        if (strcmp(frutas[i].nome, nome) == 0) {
            frutas[i] = frutas[num_frutas - 1]; // Move a última fruta para o lugar da excluída
            num_frutas--;
            printf("Fruta excluída com sucesso!\n");
            return;
        }
    }
    printf("Fruta não encontrada!\n");
}

void vender_fruta() {
    char nome[NOME_MAX];
    int quantidade;
    printf("Nome da fruta a ser vendida: ");
    scanf("%s", nome);
    Fruta* fruta = buscar_fruta(nome);
    if (fruta) {
        printf("Quantidade a ser vendida: ");
        scanf("%d", &quantidade);
        if (quantidade > fruta->quantidade) {
            printf("Quantidade insuficiente em estoque!\n");
        } else {
            fruta->quantidade -= quantidade;
            FILE* arquivo = fopen(ARQUIVO_VENDAS, "a");
            if (arquivo) {
                fprintf(arquivo, "Venda: %s - Quantidade: %d - Preço total: R$%.2f\n", fruta->nome, quantidade, fruta->preco * quantidade);
                fclose(arquivo);
                printf("Venda registrada com sucesso!\n");
            } else {
                printf("Erro ao abrir o arquivo de vendas!\n");
            }
        }
    } else {
        printf("Fruta não encontrada!\n");
    }
}

void menu() {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar fruta\n");
        printf("2. Listar frutas\n");
        printf("3. Buscar fruta\n");
        printf("4. Alterar fruta\n");
        printf("5. Excluir fruta\n");
        printf("6. Vender fruta\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_fruta();
                break;
            case 2:
                listar_frutas();
                break;
            case 3: {
                char nome[NOME_MAX];
                printf("Nome da fruta a ser buscada: ");
                scanf("%s", nome);
                Fruta* fruta = buscar_fruta(nome);
                if (fruta) {
                    printf("Fruta encontrada: %s - R$%.2f - %d unidades\n", fruta->nome, fruta->preco, fruta->quantidade);
                } else {
                    printf("Fruta não encontrada!\n");
                }
                break;
            }
            case 4:
                alterar_fruta();
                break;
            case 5:
                excluir_fruta();
                break;
            case 6:
                vender_fruta();
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 7);
}

int main() {
    menu();
    return 0;
}
// Joao Pedro Carvalho de Aguiar: 202304365598
// Yudi Campos : 202402625501