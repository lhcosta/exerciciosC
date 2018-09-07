/*Síntese - Lucas Henrique 
Objetivo: fazer ordenacao utilizando dois metodos (quick e sort) e exibir a quantidade de trocas e comparações
Entrada: dois arrays com valores aleatórios
Saída: quandidade de trocas e comparações
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

void gerarNumAleatorios(int *vet, int *vetAux, int qtd);
void quickSort(int *array, int left, int right, int *qtdTrocas, int *qtdComp);
void mergeSort(int *array, int inicio, int fim);
void merge(int *array, int inicio, int meio, int fim);

int main(){
	
	int vet[MAX_NUM] = {0},i=0;
	int vetAux[MAX_NUM] = {0};
	int qtdComp=0,qtdTrocas=0;
	
	gerarNumAleatorios(vet,vetAux,10);
	
	quickSort(vet,0,9,&qtdTrocas,&qtdComp);
	
	for(i=0;i<10;i++){
		printf("%d\n", vet[i]);
	}
	
	printf("Quantidade de Trocas %d\n", qtdTrocas);
	printf("Quantidade de Comparacoes %d\n", qtdComp);
	
	
	return 0;
}

/*Objetivo: gerar numeros aleatorios
Parâmetros: ponteiros de dois array e quantidade
Retorno: nenhum
*/

void gerarNumAleatorios(int *vet, int *vetAux, int qtd){
	
	int i=0;
	
	srand(time(NULL));
	
	for(i=0;i<qtd;i++){
		vetAux[i] = vet[i] = rand() % MAX_NUM;
	}
	
	
	return;
}

/*Objetivo: ordenacao quicksort
Parâmetros: array, primeiro indice e o ultimo
Retorno: nenhum
*/

void quickSort(int *array, int left, int right, int *qtdTrocas, int *qtdComp){
	
	int pivo = left, i=0, aux=0, j=0;
	int **auxTrocas = &qtdTrocas;
	int **auxCom = &qtdComp;
	
	
	for(i=left+1;i<=right;i++){
		j = i;
		
		if(array[j] < array[pivo]){
			*qtdComp += 1;
			aux = array[j];

			while(j > pivo){
				array[j] = array[j-1];
				*qtdTrocas += 1;
				j--;
			}
			
			array[j] = aux;
			pivo++;
			*qtdTrocas += 1;
		}
	}
	
	if(pivo-1 >= left){
		quickSort(array,left,pivo-1,*auxTrocas,*auxCom);
	}
	
	if(pivo+1 <= right){
		quickSort(array,pivo+1,right,*auxTrocas,*auxCom);
	}
	
	return;
}

/*Objetivo: ordenacao mergesort
Parâmetros: array, primeiro indice e o ultimo
Retorno: nenhum
*/

void mergeSort(int *array, int inicio, int fim){
	
	int meio;
	
	if(inicio < fim){
		meio = (inicio+fim)/2;
		mergeSort(array,inicio,meio);
		mergeSort(array,meio+1,fim);
		merge(array, inicio,meio,fim);
	}
	
	return;
	
}

void merge(int *array, int inicio, int meio, int fim){
	
	int *temp, p1=0, p2=0, tamanho=0, i=0, j=0, k=0;
	int fim1=0, fim2=0;
	
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	
	temp = (int *)malloc(tamanho*sizeof(int));
	
	if(temp != NULL){
		for(i=0;i<tamanho;i++){
			if(!fim1 && !fim2){
				if(array[p1] < array[p2]){
					temp[i] = array[p1++];
				}else{
					temp[i] = array[p2++];
				}
				
				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;		
			}else{
				if(!fim1){
					temp[i] = array[p1++];	
				}else{
					temp[i] = array[p2++];
				}
			}
		}
		
		for(j=0, k=inicio; j<tamanho; j++,k++){
			array[k] = temp[j];
		}
	}
	
	free(temp);
	
	return;
		
}
