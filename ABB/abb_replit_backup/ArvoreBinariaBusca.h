#include <stdio.h>
#include <stdlib.h>

typedef struct no tNo; 
typedef struct raiz tRaiz; 

struct no {
	int valor;		
	struct no* esquerda;
  struct no* direita;
};

struct raiz {
  tNo* raiz;
};

//tRaiz* arvore_criar(void); //"cria a raiz da arvore binaria"
void arvore_inserir_esquerda(tNo *no, int valor);
void arvore_inserir_direita(tNo *no, int valor);
void arvore_inserir(tRaiz *arvore, int valor);
void arvore_exibir(tNo *raiz);

void arvore_exibir_maiores(tNo *raiz, int valor);
void arvore_exibir_quatro_maiores(tNo *raiz, int valor, int cont);
void arvore_exibir_entre_xy(tNo *raiz, int x, int y, int cont);
void arvore_exibir_menor_valor(tNo *raiz);
void arvore_exibir_folhas(tNo *raiz);