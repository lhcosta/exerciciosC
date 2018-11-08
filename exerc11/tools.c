/*********************************
 * - tools.c
 * - arquivo de funções comuns usadas em vários códigos
 * -- menu:
 *    - apresenta um menu de opções recebidas como entrada e retora a opção escolhida
 * 
 * Created by José Adalberto F. Gualeve  on 09/08/18.
 * Copyright 2018 - All rights reserved 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tools.h"

/* apresenta um menu de opções e retorna o número da opção escolhida*/
int menu(int nopcoes, char *opcoes[])
{
    int i;
    int op;
    printf("\n              == MENU ==\n");
    for (i = 0; i < nopcoes; ++i) {
        printf("%s\n", opcoes[i]);
    }
    printf("0: Sair\n\n=> ");
    scanf("%d", &op);
    return op;
}

/* ajusta o final da string após o uso de fgets */
void ajustaEOL(char texto[], int tamanho)
{
    unsigned long len = strlen(texto);
    if (len < (unsigned long)tamanho-1)
        texto[len-1]='\0';
    return;
}

/* lista o conteúdo de um vetor de inteiros */
void listar(int vet[], int tam)
{
	int i = 0;
		
    for (i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
    return;
}
