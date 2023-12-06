/******************************************************************************

Aluna: Amanda Nascimento
Data: 18/03/2022
Lista 1 - Exercício 1 Letra A

*******************************************************************************/

// #include <stdio.h>

void exibe(int horas, int minutos){
  printf("%dh%dmin", horas, minutos);
}

int divisaoInteira(int totalMinutos, int *horas, int *minutos){
  *horas = totalMinutos/60;
  *minutos = totalMinutos%60;
}

int horario(int totalMinutos, int *horas, int *minutos){
  divisaoInteira(totalMinutos,horas,minutos);
}

int main(void) {
  int minutosDeUmEvento = 800;
  int horas, minutos;
  int *ponteiroHoras, *ponteiroMinutos;
  int i, maior;

  ponteiroHoras = &horas;
  ponteiroMinutos = &minutos;
  
  for(i=0; i<4; i++){
    printf("\nDigite os minutos: ");
    scanf("%d", &minutosDeUmEvento);
    
    horario(minutosDeUmEvento, ponteiroHoras, ponteiroMinutos);
    exibe(horas, minutos);
    
    if (minutosDeUmEvento > maior) {
        maior = minutosDeUmEvento;
    }
  }
  
    horario(maior, ponteiroHoras, ponteiroMinutos);
    printf("\nmaior tempo: ");
    exibe(horas, minutos);
  
  return 0;
}





