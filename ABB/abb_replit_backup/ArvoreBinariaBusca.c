#include "ArvoreBinariaBusca.h"

/*struct no {
	int valor;		
	struct no* esquerda;
  struct no* direita;
};

struct raiz {
  tNo* raiz;
};*/

//-----------------FUNÇÕES AUXILIARES-----------------//
tNo* no_criar(int valor) {
  tNo *no = (tNo*)malloc(sizeof(tNo));
  no->valor = valor;
  no->esquerda = NULL;
  no->direita = NULL;
  return no; //pay atention in this when you test the main
};

void arvore_inserir_esquerda(tNo *no, int valor) {

  if(no->esquerda == NULL) {
    //tNo *novo = no_criar(valor);
    tNo *novo = (tNo*)malloc(sizeof(tNo));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    no->esquerda = novo;
    
  } else {
    
    if(valor < no->esquerda->valor) {
      arvore_inserir_esquerda(no->esquerda, valor);
    } else {
      arvore_inserir_direita(no->esquerda, valor);
    }
    
  }
};

void arvore_inserir_direita(tNo *no, int valor) {

  if(no->direita == NULL) {
    //tNo *novo = no_criar(valor);
    tNo *novo = (tNo*)malloc(sizeof(tNo));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    no->direita = novo;
    
  } else {
    
    if(valor < no->direita->valor) {
      arvore_inserir_esquerda(no->direita, valor);
    } else {
      arvore_inserir_direita(no->direita, valor);
    }
    
  }
};

//-----------------FUNÇÕES PRINCIPAIS-----------------//
//tRaiz* arvore_criar(void) {}

void arvore_inserir(tRaiz *arvore, int valor) {
  
  if(arvore->raiz == NULL) {
    //tNo *novo = no_criar(valor);
    tNo *novo = (tNo*)malloc(sizeof(tNo));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    
    arvore->raiz = novo;    
  } else {
    if (valor < arvore->raiz->valor) {
      arvore_inserir_esquerda(arvore->raiz, valor);
    } else {
      arvore_inserir_direita(arvore->raiz, valor);
    }
  }
};

void arvore_exibir(tNo *raiz) {
  if(raiz != NULL) {
    //imprime a raiz, depois esquerda, depois a direita
      //printf(" %d ", raiz->valor);
      //arvore_exibir(raiz->esquerda);
      //arvore_exibir(raiz->direita);

    //imprime a esquerda, depois raiz, depois a direita
      arvore_exibir(raiz->esquerda);
      printf(" %d ", raiz->valor);
      arvore_exibir(raiz->direita);
  }
};

void arvore_exibir_maiores(tNo *raiz, int valor) {
  if(raiz != NULL) {   
    arvore_exibir_maiores(raiz->esquerda, valor);
    if(raiz->valor > valor) {
      printf(" %d ", raiz->valor);
    }
    arvore_exibir_maiores(raiz->direita, valor);
  } 
};

void arvore_exibir_quatro_maiores(tNo *raiz, int valor, int cont) {
  if(raiz != NULL) {   
    
    if((raiz->valor > valor) && (cont <4)) {
      printf(" %d ", raiz->valor);
      //cont++;
      arvore_exibir_quatro_maiores(raiz->direita, valor, cont+1);
    }
    if (raiz->valor < valor) {
      arvore_exibir_quatro_maiores(raiz->esquerda, valor, cont); 
    }
  } 
};

void arvore_exibir_entre_xy(tNo *raiz, int x, int y, int cont) {
  if(raiz != NULL) {   
    arvore_exibir_entre_xy(raiz->esquerda, x, y, cont++);
    
    if((raiz->valor > x) && (raiz->valor < y)) {
      printf(" %d ", raiz->valor);
    }
    
    arvore_exibir_entre_xy(raiz->direita, x, y, cont--);
  } 
};

void arvore_exibir_menor_valor(tNo *raiz) {
  if(raiz != NULL) {
    arvore_exibir_menor_valor(raiz->esquerda);    
    if(raiz->esquerda == NULL) {
      printf(" %d ", raiz->valor);
    }    
  } 
};

//Folhas: chaves que não tem "galhos" ou seja, que direita e esquerda são nulos (NULL)
void arvore_exibir_folhas(tNo *raiz) {
  if(raiz != NULL) {
    if((raiz->esquerda == NULL) && (raiz->direita == NULL)) {
      printf(" %d ", raiz->valor);
    }   
    arvore_exibir_folhas(raiz->esquerda);    
    arvore_exibir_folhas(raiz->direita); 
  } 
};
