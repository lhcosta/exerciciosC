/*
 * - main.c
 *
 *
 * Created by José Adalberto F. Gualeve  on 11/10/18.
 * Copyright 2018 - All rights reserved
*/
#include<stdio.h>
#include<stdlib.h>
#include"lista.h"
#include"tools.h"
#define OPCOES 4

int main()
{
    char* opcoes[OPCOES] = {"1- Inserir elemento na lista","2- Imprimir a lista completa","3- Buscar um elemento da lista","4- Liberar lista\n"};
    Descritor *lista = NULL;
    int op=0, numSearch=0, aux=0, num=0;
    
    criarLista(&lista);
    
    while ((op = menu(OPCOES, opcoes)) != 0) {
        switch (op) {
        case 1:
            printf("Digite um numero: ");
            scanf("%d", &num);
            if(inserirElemento(lista,num)){
            	printf("Numero inserido com sucesso\n");
			}
			getch();system("cls");
            break;
        case 2:
            /* imprimir lista completa */
            imprimirLista(lista);getch();system("cls");
            break;
        case 3:
            /* buscar um elemento da lista */
            printf("Digite um numero: ");
            scanf("%d", &numSearch);
            aux = buscarElemento(lista,numSearch);
            if(aux){
            	printf("Valor pertence a lista -> %d\n", numSearch);
			}else{
				printf("Valor nao encontrado\n");
			}
			getch();system("cls");
            break;
        case 4:
			liberarLista(lista);
			printf("Lista Liberada\n");getch();system("cls");
        }
    }
    return 0;
}
