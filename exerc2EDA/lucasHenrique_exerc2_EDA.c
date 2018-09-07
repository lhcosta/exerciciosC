/*Métodos de Pesquisa - Lucas Henrique
Objetivo: realizar métodos de pesquisa
Entrada: chave para ser encontrada
Saída: posição no array e números de tentativas
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

int pesquisaSequencial(int *valor, int *array, int *numTentativas, int tamArray);
int pesquisaBinaria(int *valor, int *array, int *numTentativas, int tamArray);

int main(){
	
	int array[MAX_NUM] = {2,3,6,9,10,11,23,35,45,54};
	int aux=0,valor=0,numTentativas=0;
	
	printf("Numero Desejado: ");
	scanf("%d", &valor);
	
	aux = pesquisaBinaria(&valor,array,&numTentativas,MAX_NUM);
	
	if(aux != -1){
		printf("Valor Encontrado na Posicao -> %d\n", aux+1);
		printf("Numeros de Tentativas -> %d\n", numTentativas);
	}else{
		printf("Valor nao Encotrado\n");
	}
	
	getch();
	
	
	return 0;
}

/*Objetivo: realizar uma pesquisa sequencial
Parâmetros: ponteiros do valor, array, número de tentativas e tamanho do array
Retorno: posição dentro do array
*/

int pesquisaSequencial(int *valor, int *array, int *numTentativas, int tamArray){
	
	int i=0;
	
	/*Caso ocorra uma segunda chamada ao método o valor será reinicializado*/
	*numTentativas = 0;
	
	for(i=0;i<tamArray;i++){
		*numTentativas += 1;
		if(*valor == array[i]){
			return i;	
		}
	}	
	
	return -1;
	
}

/*Objetivo: realizar uma pesquisa binaria
Parâmetros: ponteiros do valor, array, número de tentativas e tamanho do array
Retorno: posição dentro do array
*/

int pesquisaBinaria(int *valor, int *array, int *numTentativas, int tamArray){
	
	int inicio,meio,fim;
	
	inicio=0;
	fim=tamArray-1;
	*numTentativas = 0;
	
	while(inicio<=fim){
		
		*numTentativas += 1;
		meio = (inicio + fim)/2;
		
		if(*valor > array[meio]){
			inicio = meio + 1;
		}else if(*valor < array[meio]){
			fim = meio - 1;
		}else{
			return meio;
		}		
	}

	return -1;
}

