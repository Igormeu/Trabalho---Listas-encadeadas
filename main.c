#include <stdlib.h>
#include <stdio.h>
#include "strutc_lista.h"

int main (){
    No *lista = malloc(sizeof(No));
    int opcao;

    system("cls");
    exibirBemVindo();
    criarLista(lista);
    do{
        int num = 0;
        exibirMenu();
        printf("\nDigite a opcao ao qual deseja testar: ");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            num = receberValor();
            inserirLista(&lista,num);
            break;
        case 2:
            num = receberValor();
            buscarLista(lista,num);
            break;
        case 3:
            num = receberValor();
            excluirLista(&lista,num);
            break;
        case 4:
            exibirLista(lista);
            break;
        case 5:
            verificarVazio(lista);
            break;
        case 6:
            if (liberarLista(&lista) == 1){
                printf("\n\nNao ha mais lista para manipular, tchau");
                break;
            }
            else{
                opcao = 0;
                break;
            }  
        case 7:
            printf("\n\nSee you soon");
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    }
    while (opcao != 7 && opcao != 6);

}