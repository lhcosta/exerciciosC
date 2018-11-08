#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"
#include "arquivos.h"
#include <string.h>

#define MAX_LISTAS 15
#define TAM_MAT 12

void menu(Lista **l[], Aluno *alunos, int qtdAlunos);
int funcaoHash(char *matriculaAluno, int tamArray);
void inserirMatricula(char *matriculaAluno, int *indiceHash);

int main(int argc, char *argv[]) {
	
	int i = 0, qtdAlunos = 0;
	Aluno *alunos;
	Lista **l[MAX_LISTAS];
	
	readFile(&alunos,"alunos.dat","rb",sizeof(Aluno),&qtdAlunos);
	
	for(i=0;i<MAX_LISTAS;i++){
		l[i] = criar_lista();
	}
	
	menu(l,alunos,qtdAlunos);
	
	return 0;
}

void menu(Lista **l[], Aluno *alunos, int qtdAlunos){
	
	int opcao = 0;
	int qtdAlunosInclusos = 0;
	int i = 0;
	int indice = 0;
	char matriculaAluno[TAM_MAT];
	
	do{
		printf("\tMENU\n\n");
		printf("1 - Incluir alunos na listas\n");
		printf("2 - Listagem das listas\n");
		printf("3 - Consultar aluno nas listas\n");
		printf("4 - Remover aluno da lista\n");
		printf("5 - Encerrar programa\n");
		scanf("%d", &opcao);system("cls");
		
		switch(opcao){
			case 1:
				while(qtdAlunosInclusos < qtdAlunos){	
					indice = funcaoHash(alunos[qtdAlunosInclusos].matricula,MAX_LISTAS);
					
					if(incluir_elemento_lista(l[indice],&alunos[qtdAlunosInclusos])){
						printf("Aluno(a) %s incluso com sucesso na Lista %d\n",alunos[qtdAlunosInclusos].nome ,indice+1);
					}
					qtdAlunosInclusos++;
					
				}//else{
					//printf("Todos os alunos foram cadastrados\n");
				//}
				getch();
				break;
			case 2:
				for(i=0;i<MAX_LISTAS;i++){
					printf("Lista %d\n\n", i+1);
					if(!imprimir_lista(l[i])){
						printf("Lista Vazia\n");
					}
					printf("--------------\n");
				}
				getch();
				break;
			case 3:
				printf("\tPesquisa Alunos\n\n");
				inserirMatricula(matriculaAluno,&indice);
				if(consulta_lista(l[indice],matriculaAluno)){
					printf("Aluno Encontrado -> Lista %d\n",indice+1);
				}else{
					printf("Nenhum aluno encontrado\n");
				}
				getch();
				break;
			case 4:
				printf("\tExcluir Aluno\n\n");
				inserirMatricula(matriculaAluno,&indice);
				if(remover_elemento_lista(l[indice],matriculaAluno)){
					printf("Aluno Removido com sucesso\n");
				}else{
					printf("Nenhum aluno encontrado\n");
				}
				getch();
				break;
			case 5:
				exit(0);
			default:
				printf("Escolha Invalida\nDigite Novamente\n");getch();			
		}
		system("cls");
	}while(opcao!=5);
	
}

int funcaoHash(char *matriculaAluno, int tamArray){
	
	int indice = 0;
	int i = 0;
	
	for(i=0;i<strlen(matriculaAluno);i++){
		indice += (int) matriculaAluno[i];
	} 
	
	if(indice % 2 == 0){
		indice += 17;
	}else if(indice % 10 == 0){
		indice /= 3;
	}else{
		indice /= 2;
	}
	
	return indice % tamArray;
}

void inserirMatricula(char *matriculaAluno, int *indiceHash){
	int i = 0;
	
	fflush(stdin);
	printf("Matricula Aluno: ");
	scanf("%s", matriculaAluno);
	
	for(i=0;i<2;i++){
		//Colocando em maiusculo as letras iniciais
		matriculaAluno[i] = toupper(matriculaAluno[i]);
	}
	//Indice da lista
	*indiceHash = funcaoHash(matriculaAluno,MAX_LISTAS);

}
