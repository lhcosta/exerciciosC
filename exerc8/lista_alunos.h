#ifndef LISTA_ALUNOS
#define LISTA_ALUNOS

typedef struct{
	int matricula;
	char nome[30];
}Aluno;

struct lista{
	Aluno aluno;
	int colisao;
	struct lista *prox;
};

typedef struct lista Lista;

void criar_lista(Lista **l);
void inserir_aluno(Lista *l, Aluno *aluno);
int lista_vazia(Lista *l);
void imprimirLista(Lista *l);
void cadastrarAluno(Aluno *aluno);
int funcaoHash(Aluno *aluno, int tamArray);
void menu();

#endif
