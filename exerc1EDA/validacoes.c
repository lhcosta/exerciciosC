#include "validacoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>  //Utilizar Função getch();

//Objetivo: ler e validar dados inteiros
//Parâmetros: ponteiro do valor, valor mínimo e máximo, texto
//Retorno: nenhum

void leValidaInt(int *num, int valorMin, int valorMax, char texto[20]){
	
	char aux[10];
	int i=0,flag=0;
	
	do{
		do{
			fflush(stdin);
			printf(texto);
			scanf("%s", &aux);
			
			for(i=0;i<strlen(aux);i++){
				if(!isdigit(aux[i])){
					ERRO_INT
					flag=1;
					break;
				}
				flag=0;
			}
		}while(flag!=0);
		
		*num = atoi(aux);
		
		if(*num < valorMin || *num > valorMax){
			ERRO_QTD_NUM
			flag=1;
		}else{
			flag=0;
		}
	}while(flag!=0);	
}

//Objetivo: ler e validar dados do tipo float
//Parâmetros: ponteiro do valor, valor mínimo e máximo, texto
//Retorno: nenhum

void leValidaFloat(float *num, float valorMin, float valorMax, char texto[20]){
	
	char aux[20];
	int i=0,flag=0,ponto=0;
	
	do{
		do{
			do{
				flag=0;ponto=0;
				fflush(stdin);
				printf(texto);
				scanf("%s", &aux);
				
				if(aux[0] == '.'){
					flag=1;
				}
				
			}while(flag!=0);
			
				for(i=0;i<strlen(aux);i++){
					
				/*Validar números e pontos*/
					if(!isdigit(aux[i]) && aux[i]!='.'){
						ERRO_FLOAT
						flag=1;
						break;
					}
					
					
					if(aux[i]=='.'){
						ponto++;
					}
					
					if(ponto > 1){
						printf("Digite apenas um ponto\n");getch();system("cls");
						flag=1;
						break;
					}	
					
					/*Evitar espaços entre casas decimais*/	
					if(aux[i] == '.' && aux[i+1]=='\0'){
						printf("ERRO! Digite no formato correto, sem espacos!\n");getch();system("cls");
						flag=1;
						break;
					}
				}
			
		}while(flag!=0);
		
		*num = atof(aux);
		
		if(*num < valorMin || *num > valorMax){
			ERRO_QTD_NUM
			flag=1;
		}
	}while(flag!=0);	
		
}

//Objetivo: Ler e validar nomes
//Parâmetros:  ponteiro de nome e texto
//Retorno: nenhum

void leValidaNome(char texto[20], char *nome) {
	int flag = 1, qtdEspacos = 0, i;
	int aux=0;
	
	do {
		qtdEspacos = 0;
		fflush(stdin);
		printf(texto);
		scanf("%[^\n]s", nome);
		
		for (i = 0; i < strlen(nome); i++) {
			if (nome[i] == ' ' || nome[i] == '\0' || nome[i] == '\n') {
				qtdEspacos++;
			} 
		}
		
		if(qtdEspacos == strlen(nome)) {
			printf("Nome invalido! O nome esta vazio.\n");
			flag = 0;
		}else if(strlen(nome) < 2) {
			printf("Nome invalido! O nome e muito curto.\n");
			flag = 0;
		}else if(nome[0] == ' ') {
			printf("Nome invalido! O nome deve comecar com letra.\n");
			flag = 0;
		}else{
			for (i = 0; i < strlen(nome); i++) {
				if (!isalpha(nome[i])) {
					if(nome[i]==' '){
						if(nome[i+1]==' '){
							printf("Digite apenas um espaco entre os nomes.\n");
							flag = 0;
							break;
						}
					}else{
						printf("Nome invalido! Digite apenas letras.\n");
						flag = 0;
						break;
					}
				} else {
					flag = 1;
				}
			}
		}
	} while(!flag);	
}
