/*Métodos de Ordenação - Lucas Henrique - UC17201125
Objetivo: realizar três tipos diferentes de ordenação verificando qual o mais eficaz
Entrada: array de inteiros
Saída: quantidade de comparações e trocas feitas
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX 10

/*Protótipos de Funções*/
void bubbleSort(int *array, int qtdNum);
void insertionSort(int *array, int qtdNum);
void selectionSort(int *array, int qtdNum);

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int i=0,v1[MAX]={0},v2[MAX]={0},v3[MAX]={0};
	
	srand(time(NULL));
	
	for(i=0;i<MAX;i++){
		v3[i] = v2[i] = v1[i] = rand() % 20;
	}
	
	printf("Metódo BubbleSort\n");
	bubbleSort(v1,MAX);
	
	printf("Metódo InsertionSort\n");
	insertionSort(v2,MAX);
	
	printf("Metódo SelectionSort\n");
	selectionSort(v3,MAX);
	
	for(i=0;i<MAX;i++){
		printf("%d %d %d\n", v1[i],v2[i],v3[i]);
	}
	
	
	return 0;
}

/*Método de Ordenação BubbleSort - ORDEM CRESCENTE*/

void bubbleSort(int *array, int qtdNum){
	
	int j=0,aux,flag;
	int qtdCompare=0,qtdTrocas=0;
	
	do{
		flag = 0;
		for(j=0;j<qtdNum-1;j++){
			qtdCompare++; /*Quantidade de Comparações*/
			if(array[j] > array[j+1]){
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;	
				qtdTrocas++; /*Quantidade de Trocas*/
				flag = j;
			}
		}
		qtdNum--;
	}while(flag != 0);
	
	printf("Quantidade de Comparações -> %d\n", qtdCompare);
	printf("Quantidade de Trocas -> %d\n\n", qtdTrocas);
}

/*Método de Ordenação InsertionSort*/

void insertionSort(int *array, int qtdNum){
	
	int i=0,j=0,aux=0,qtdCompare=0,qtdTrocas=0;
	
	for(j=1;j<qtdNum;j++) {
		
		aux = array[j];
		i = j-1;
		
		qtdCompare++;
		while( (!(i<0)) && (array[i] > aux)){
			array[i+1] = array[i--];
			qtdCompare++;
			qtdTrocas++;
		}
		
		array[i+1] = aux;
	}
	
	
	printf("Quantidade de Comparações -> %d\n", qtdCompare);
	printf("Quantidade de Trocas -> %d\n\n", qtdTrocas);
	
	
}

/*Métodos de SelectionSort*/

void selectionSort(int *array, int qtdNum){
	
	int i=0,j=0,k=0,aux=0;
	int qtdCompare=0,qtdTrocas=0;
	
	for(i=0;i<qtdNum-1;i++){
		k = i;
		
		for(j=i+1; j < qtdNum; j++){
			if(array[j] < array[k]){
				qtdCompare++;
				k = j;
			}
		}
		
		aux = array[i];
		array[i] = array[k];
		array[k] = aux;
		qtdTrocas++;
	}
	
	printf("Quantidade de Comparações -> %d\n", qtdCompare);
	printf("Quantidade de Trocas -> %d\n\n", qtdTrocas);
	
	
	
}
