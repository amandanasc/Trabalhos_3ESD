/******************************************************************************

Aluna: Amanda Nascimento
Data: 24/03/2022
Lista 3 - Exercício 1

*******************************************************************************/

#include <stdio.h>

typedef struct {
    int minutos, segundos, codigoModalidade;
}tNadadores;

typedef struct {
    int codigoModalidade, segundos;
}tRecord;

void preencher(tNadadores n[], tRecord r[], int k) {
    int i, totalSegundos, j;
    
    for(i=0; i<k; i++) {
        printf("\n\nDigite o codigo da modalidade [1]- Crawl [2]- Costas [3]- Borboleta: ");
        scanf("%d", &n[i].codigoModalidade);
        
        printf("\nDigite a quantidade de minutos: ");
        scanf("%d", &n[i].minutos);
        
        printf("\nDigite a quantidade de segundos: ");
        scanf("%d", &n[i].segundos);
        
        totalSegundos = (n[i].minutos * 60) + n[i].segundos;
        
        for(j=0; j<3; j++) {
            
            if((r[j].codigoModalidade == n[i].codigoModalidade)&&(totalSegundos < r[j].segundos)) {
                r[j].segundos = totalSegundos;
            }
        }
    }
}

void ordenar(tNadadores n[], int k) {
    int i = 0, j = 0;
    tNadadores aux;
    aux.codigoModalidade = 0;
    aux.segundos = 0;
    aux.minutos = 0;
    
    for (i=0; i<k; i++) {
        for (j=0; j<k; j++) {
            if (n[i].codigoModalidade < n[j].codigoModalidade){
                aux = n[i];
                n[i] = n[j];
                n[j] = aux;
            }
        }
    }
}

void exibir(tRecord r[], tNadadores n[], int k) {
    int i;
    
    for(i=0; i<3; i++) {
        printf("\n\nCodigo Modalidade: %d", r[i].codigoModalidade);
        printf("\nRecord segundos: %d", r[i].segundos);
    }
    
    for(i=0; i<k; i++) {
        printf("\n\nCodigo Modalidade: %d", n[i].codigoModalidade);
        printf("\nTempo: %dm %ds", n[i].minutos, n[i].segundos);
    }
    
}

int main()
{
    int k = 6;
    tNadadores n[k];
    tRecord r[3];
    
    //record inicial
    r[0].codigoModalidade = 1;
    r[1].codigoModalidade = 2;
    r[2].codigoModalidade = 3;
    
    r[0].segundos = 100;
    r[1].segundos = 200;
    r[2].segundos = 300;
    
    exibir(r, n, 0);
    
    preencher(n, r, k);
    
    ordenar(n, k);
    
    exibir(r, n, k);
    return 0;
}

