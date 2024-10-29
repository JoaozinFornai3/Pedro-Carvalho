#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

Lista* criarLista() {
    return NULL;
}

int verificarVazia(Lista *l) {
    return (l == NULL);
}

Lista* inserirLista(Lista *l, int valor) {
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;

    if (verificarVazia(l) || valor < l->info) { 
        novo->prox = l;
        return novo;
    }

    Lista *atual = l;
    while (atual->prox != NULL && atual->prox->info < valor) { 
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    return l;
}

void exibirLista(Lista *l) {
    Lista *atual = l;
    while (atual != NULL) {
        printf("%d -> ", atual->info);
        atual = atual->prox;
    }
    printf("NULL\n");
}

Lista* buscarLista(Lista *l, int valor) {
    Lista *atual = l;
    while (atual != NULL && atual->info != valor) {
        atual = atual->prox;
    }
    return atual;
}

Lista* excluirLista(Lista *l, int valor) {
    if (verificarVazia(l)) return l;

    Lista *atual = l;
    Lista *anterior = NULL;

    while (atual != NULL && atual->info != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return l;

    if (anterior == NULL) { 
        l = atual->prox;
    } else { 
        anterior->prox = atual->prox;
    }

    free(atual); 
    return l;
}

void liberarLista(Lista *l) {
    Lista *atual = l;
    while (atual != NULL) {
        Lista *temp = atual->prox;
        free(atual);
        atual = temp;
    }
}

int main(){
    Lista *minhaLista = criarLista();

    minhaLista = inserirLista(minhaLista, 5);
    minhaLista = inserirLista(minhaLista, 2);
    minhaLista = inserirLista(minhaLista, 8);
    minhaLista = inserirLista(minhaLista, 3);

    printf("Lista apos insercoes: ");
    exibirLista(minhaLista);

    minhaLista = excluirLista(minhaLista, 5);
    printf("Lista apos excluir 5: ");
    exibirLista(minhaLista);

    Lista *busca = buscarLista(minhaLista, 3);
    if (busca != NULL)
        printf("Elemento 3 encontrado!\n");
    else
        printf("Elemento 3 nao encontrado.\n");

    liberarLista(minhaLista); 
    return 0;
}
