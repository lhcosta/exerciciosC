/*Sintese - Lucas Henrique
Objetivo: salvar numeros aleatorios em um estrutura, realizando busca e ordenação
Entrada: o valor que deseja buscar
Saída: numero cadastrado ou nao
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "validacoes.h"

#define TAXA_RAND 100
#define QTD_NUM 50
#define TAM_ARRAY 7
#define TAM_STRUCT_ARRAY 8

/*Variaveis Globais*/
int qtdColisoes = 0;

typedef struct{
	int num[TAM_STRUCT_ARRAY];
	int contador;
}Array;

//Protótipos das Funções
void randNum(int *array, int qtdNumeros);
int funcaoHash(int num);
void inicializaArray(Array *arrayNum);
void saveData(Array *arrayNum, int num, int indice);
void imprimeArray(Array *arrayNum);
void insertionSort(int *array, int qtdNum);
int buscaBinaria(int *array, int qtdNum, int num);
void pesquisaValores(Array *array);
void menu(Array *array);

int main(){
	
	int num[QTD_NUM] = {0};
	int aux = 0, i = 0, j = 0, contador = 0;
	Array arrayNum[TAM_ARRAY];
	
	inicializaArray(arrayNum);
	randNum(num,QTD_NUM);
	
	/*Preenchedo a estrutura de array*/
	for(i=0;i<QTD_NUM;i++){
		aux = funcaoHash(num[i]);
		saveData(arrayNum,num[i],aux);
	}
	
	//Invocando Menu
	menu(arrayNum);
	
	
	return 0;
}

/*Objetivo: menu de opcoes
Parâmetros: estrutura array de numeros
Retorno: nenhum
*/

void menu(Array *array){
	
	int opcao = 0;
	
	do{
		printf("\tMENU\n\n");
		printf("1 -> CONSULTAR NUMERO\n");
		printf("2 -> IMPRIMIR TODOS OS NUMEROS\n");
		printf("0 -> SAIR\n");
		scanf("%d", &opcao);system("cls");
		
		switch(opcao){
			case 1:
				pesquisaValores(array);
				break;
			case 2:
				imprimeArray(array);
				break;
			case 0:
				exit(0);
			default:
				printf("Opcao Invalida\nDigite Novamente\n");		
		}
		getch();system("cls");
	}while(opcao != 0);
}

/*Objetivo: salvar os números randomicos em novo array de acordo com o hash 
Parâmetros: ponteiro para o array
Retorno: nenhum
*/

void saveData(Array *arrayNum, int num, int indice){

	/*Vetor Cheio*/
	if(arrayNum[indice].contador == TAM_STRUCT_ARRAY){
		qtdColisoes += 1;
		return;
	}
	
	arrayNum[indice].num[arrayNum[indice].contador] = num;
	arrayNum[indice].contador++;
	
	/*Realizando ordenacao*/
	insertionSort(arrayNum[indice].num,arrayNum[indice].contador);
	
	return;
}


/*Objetivo: gerar numeros inteiros aleatorios
Parâmetros: array e quantidade de numeros
Retorno: nenhum
*/

void randNum(int *array, int qtdNumeros){
	
	int num=0,i=0;
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<qtdNumeros;i++){
		array[i] = rand() % TAXA_RAND;
	}
	
	return;
}

/*Objetivo: gerar chaves para os valores recebidos
Parâmetros: valores
Retorno: chave para o armazenamento no array
*/

int funcaoHash(int num){
	
	int index=0;
	
	if(num % 2 == 0){
		index += num + 17;
		if(index % 10 == 0){
			index += 13;
		}
	}else{
		index += num + 11;
	}
	
	return index % TAM_ARRAY;
	
}

/*Objetivo: inicializa estrutura
Parâmetros: ponteiro do array
Retorno: nenhum
*/

void inicializaArray(Array *arrayNum){
	
	int i = 0, j = 0;
	
	for(i=0;i<TAM_ARRAY;i++){
		arrayNum[i].contador = 0;
		for(j=0;j<TAM_STRUCT_ARRAY;j++){
			arrayNum[i].num[j] = 0;
		}
	}
	
	return;
}

/*Objetivo: imprime valores do array
Parâmetros: ponteiro do array
Retorno: nenhum
*/

void imprimeArray(Array *arrayNum){
	
	int i = 0, j = 0;
	
	printf("VALORES\n\n");
	for(i=0;i<TAM_ARRAY;i++){
		printf("Linha %-3d -> ", i+1);
		for(j=0;j<TAM_STRUCT_ARRAY;j++){
			printf("%3d ", arrayNum[i].num[j]);
		}
		printf("\n");
	}
	
	printf("\nQuantidade de Colisoes -> %d\n", qtdColisoes);
	
	return;
}

/*Objetivo: ordernar os valores de um array
Parâmetros: ponteiro do array e quantidade de numeros
Retorno: nenhum
*/

void insertionSort(int *array, int qtdNum){

	int i = 0, j = 0;
	int aux = 0;

	for(j=1;j<qtdNum;j++){
		aux = array[j];
		i = j - 1;

		while((!(i<0)) && (array[i] > aux)){
			array[i+1] = array[i--];
		}

		array[i+1] = aux;
	}

	return;

}

/*Objetivo: realizar uma busca binária em array
Parâmetros: array e numero a ser procurado
Retorno: indice no array do valor solicitado
*/

int buscaBinaria(int *array, int qtdNum, int num){
	
	int inicio, meio, fim;
	
	inicio = 0;
	fim = qtdNum - 1;
	
	while(inicio <= fim){
		meio = (fim - inicio)/2;
		
		if(num == array[meio]){
			return meio;
		}
		
		if(num > array[meio]){
			inicio = meio + 1;
		}else if(num < array[meio]){
			fim = meio - 1;
		}
	}
	
	return -1;
}

/*Objetivo: pesquisa valor a ser encotrando utilizando funcao hash e busca binaria
Parâmetros: ponteiro da estrutura array
Retorno: nenhum
*/

void pesquisaValores(Array *array){
	
	int num = 0, aux = 0;
	int i = 0;
	
	printf("\tBUSCANDO NUMERO\n\n");
	leValidaInt(&num,1,TAXA_RAND,"Digite o numero que deseja encontrar: ");
	aux = funcaoHash(num);
	i = buscaBinaria(array[aux].num,array[aux].contador,num);
	
	if(i < 0){
		printf("Valor nao encotrado\n");
		return;
	}
	
	printf("Valor %d Encotrado -- Linha -> %d - Posicao -> %d\n", num,aux+1, i+1);
	return;
	
}
