/******************************************************************************

Aluna: Amanda Nascimento
Data: 18/03/2022
Lista 2 - Exercício 2 Letra E

*******************************************************************************/

// #include <stdio.h>
// #include <stdlib.h>

int preencheMatriz(int n, int m[n][n]){
    
    int i,j;
    
    for(i=0; i<n; i++) {
        printf("\n");
        for(j=0; j<n; j++) {
            m[i][j] = rand()%10;
            printf(" %d ", m[i][j]);
        }
    }
    
}

void exibeSemDiagonal(int n, int m[n][n]){
    int cont=0, i, j;    
    
    printf("\n");
    
    for(i=0; i<n; i++) {
        printf("\n");
        
        for(j=0; j<n; j++) {
            if(j != i){ 
                printf(" %d ", m[i][j]);
            } else {
                printf("   ");
            }
        }
    } 
}

int main() {
    int n = 5;
    int matriz[n][n];
    int i, j;
    
    preencheMatriz(n, matriz);
    exibeSemDiagonal(n, matriz);
    return 0;
}

