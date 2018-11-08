#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#define MAX_NOME 53
#define MAX_MAT 11

struct aluno{
	char matricula[MAX_MAT];
	char nome[MAX_NOME];
};

typedef struct aluno Aluno;
typedef struct elemento Lista;

Lista** criar_lista();
int incluir_elemento_lista(Lista **l, Aluno *aluno);
int imprimir_lista(Lista **l);
int lista_vazia(Lista **l);
int consulta_lista(Lista **l, char *matriculaAluno);
int remover_elemento_lista(Lista **l, char *matriculaAluno);

#endif
