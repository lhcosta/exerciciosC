#ifndef LISTA_CIRCULAR
#define LISTA_CIRCULAR

typedef struct elemento Elemento;

typedef struct descritor{
	Elemento **inicio;
	Elemento **final;
	int geraSenha;
	int qtd;
}Descritor;

void criarLista(Descritor **lista, int qtdElementos);
void pegaSenha(Descritor *lista);
void chamaSenha(Descritor *lista);
void imprimeLista(Descritor *lista);


#endif
