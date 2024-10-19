#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int numero;
    struct no *proximo;
} No;

void criarLista (No* lista){
    lista->numero = 0;  
    lista->proximo = NULL;
}

int receberValor (){
    int num;

    printf("Digite o numero: ");
    scanf("%d",&num);

    return num;
}


void inserirLista (No **lista,int num){
    No *newno = malloc(sizeof(No));
    No *aux = *lista;
    No *anterior;

    newno->numero = num;

    //Inserir no início
    if((*lista)->numero >= num || (*lista)->proximo == NULL){
        newno->proximo = *lista;
        *lista = newno;
    }
    else{
        // Encontrar o nó depois e antes do que vc quer inserir
        while (aux->numero < num && aux->proximo != NULL){
        anterior = aux;
        aux = aux->proximo;
        }

        newno->proximo = aux;
        anterior->proximo = newno;
    }
}

void exibirLista (No *lista){
    if (lista == NULL) {
    printf("\nA lista esta vazia\n");
    return;
    }
    else{
        No *exibir = lista;
        printf("\n=====Lista de valores armazenados=====\n\n[ ");
        while (exibir->proximo != NULL ) {
            printf("%d ", exibir->numero);
            exibir = exibir->proximo;
        }
        printf("]\n");
    }
}

int verificarVazio (No *lista){
    if (lista->numero == NULL && lista->proximo == NULL) {
        printf("\nA lista esta vazia");
        return -1; 
    }
    else{
        printf("\nHa elementos na lista");
        return 1;
    }
}

No* buscarLista (No *lista,int num) {
    No *aux = lista;
    

    while (aux != NULL && aux->numero != num) {
        aux = aux->proximo;
    }

    if (aux == NULL) {
        printf("\nO item não foi encontrado\n");
        return NULL; 
    } else {
        printf("\nItem encontrado: %d\n", aux->numero);
        return aux;
    }
}

int excluirLista(No **lista,int num) {
    No *aux = *lista;
    No *anterior = NULL;

    while (aux != NULL && aux->numero != num) {
        anterior = aux;
        aux = aux->proximo;
    }

    if (aux == NULL){
        printf("\nO item nao foi encontrado\n");
        return -1;
    }

    if (anterior == NULL) {
        *lista = aux->proximo;
        printf("\nO numero era o primeiro, entao realocamos a lista\n");
    } 
    else {
        anterior->proximo = aux->proximo;
        printf("\nO numero foi removido\n");
    }

    free(aux);
    return 0;
}

int liberarLista (No **lista){

    int vazia = verificarVazio(*lista);

    if (vazia == -1){
        free(*lista);
        printf("\nLista excluida com sucesso");
        return 1;
    }
    else{
        printf("\nHa elementos na lista e ela nao sera excluida");
        return 0;
    }
}

void exibirBemVindo() {
    printf("******************************************************************************\n");
    printf("*                                                                            *\n");
    printf("*  BBBBBB   EEEEEEEE  M     M    V     V  IIIIIII  N     N  DDDDDD   OOOOOO  *\n");
    printf("*  B     B  E         MM   MM    V     V     I     NN    N  D     D  O    O  *\n");
    printf("*  BBBBBB   EEEEE     M M M M    V     V     I     N N   N  D     D  O    O  *\n");
    printf("*  B     B  E         M  M  M     V   V      I     N  N  N  D     D  O    O  *\n");
    printf("*  BBBBBB   EEEEEEEE  M     M      VVV    IIIIIII  N   N N  DDDDDD   OOOOOO  *\n");
    printf("*                                                                            *\n");
    printf("******************************************************************************\n");
    printf("\n\nFeito por: Igor Stenio Pereira Santos Matricula: 202403930111\n\n");
}

void exibirMenu(){
    printf("\n");
    printf("1 - Inserir numero\n");
    printf("2 - Buscar item\n");
    printf("3 - Excluir item\n");
    printf("4 - Exibir lista\n");
    printf("5 - Verificar vazio\n");
    printf("6 - Liberar lista\n");
    printf("7 - SAIR");
}
