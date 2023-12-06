#include <stdio.h>
#include "ArvoreBinariaBusca.h"

int main(void) {
  int op, valor;
  tRaiz arvore;
  arvore.raiz = NULL;

  do {
    printf("\n\n----------MENU----------\n");
    printf("\n [0]: Sair\n [1]: Inserir\n [2]: Exibir\n [3]: Inserir Árvore Completa\n [4]: Exibir valores maiores que x\n [5]: Exibir os quatro valores maiores que x\n [6]: Exibir todos os valores entre x e y\n [7]: Exibir o menor valor na árvore\n [8]: Exibir folhas da árvore\n");
    printf("\n Opção: ");
    scanf("%d", &op);

    switch(op) {
      case 0: printf("\nVocê saiu do menu!\n");
        break;
      case 1: 
        printf("\nDigite o valor: ");
        scanf("%d", &valor);
        arvore_inserir(&arvore, valor);
        break;
      case 2:
        printf("\n");
        arvore_exibir(arvore.raiz);
        break;
      case 3:
        printf("\nInserindo árvore pre-definida!\n");
        arvore_inserir(&arvore, 40);
        arvore_inserir(&arvore, 55);
        arvore_inserir(&arvore, 22);
        arvore_inserir(&arvore, 21);
        arvore_inserir(&arvore, 28);
        arvore_inserir(&arvore, 70);
        arvore_inserir(&arvore, 4);
        arvore_inserir(&arvore, 76);
        arvore_inserir(&arvore, 100);
        arvore_inserir(&arvore, 50);
        arvore_inserir(&arvore, 42);
        arvore_inserir(&arvore, 52);
        break;
      case 4:
        //adicionar função para retornar se valor existe ou não
        arvore_exibir_maiores(arvore.raiz, 22);
        break;
      case 5:
        arvore_exibir_quatro_maiores(arvore.raiz, 22, 0);//errada
        break;
      case 6:
        arvore_exibir_entre_xy(arvore.raiz, 22, 100, 0);
        break;
      case 7:
        arvore_exibir_menor_valor(arvore.raiz);
        break;
      case 8: 
        arvore_exibir_folhas(arvore.raiz);
        break;
      
      default: printf("\nOpção Inválida\n");
    }
  } while(op != 0);


}