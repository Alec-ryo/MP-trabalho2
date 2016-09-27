#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <romano.h>

int unidade (char*, int*);
int dezena (char*, int*);
int centena (char*, int*);
int milhar (char*, int*);
int conversor (char*);

//funçao que converte os números
int conversor(char* romano){

  int num, U, D, C, M, numero;
  int idx = 0;

  M = milhar(romano, &idx); //calcula o algorismo da casa de milhar
  C = centena(romano, &idx);  //calcula o algorismo da casa de centena
  D = dezena(romano, &idx); //calcula o algorismo da casa de dezena
  U = unidade(romano, &idx);  //calcula o algorismo da casa da unidade

  num = M + C + D + U; //Soma e adquire o valor do numero

  if(num == 0){ //Se não passar por nenhum identificador de algarismo romano será pq não existe letra válida
    return -1;
  }

  numero = strlen(romano);

  if(idx != numero){  //identifica se todos os valores foram varridos e se não é pq o número é inválido
    return -1;
  }

  return num;

}

//calcula o algorismo da casa da unidade
int unidade (char* romano, int* idx){

  int num = 0;

  if(romano[(*idx)] == 'i' || romano[(*idx)] == 'I'){
    num = 1;
    (*idx) ++;
    if(romano[(*idx)] == 'v' || romano[(*idx)] == 'V'){
      num = 4;
      (*idx) ++;
    }
    if(romano[(*idx)] == 'x' || romano[(*idx)] == 'X'){
      num = 9;
      (*idx) ++;
    }

    if(romano[(*idx)] == 'i' || romano[(*idx)] == 'I'){
      num = 2;
      (*idx) ++;
      if(romano[(*idx)] == 'i' || romano[(*idx)] == 'I'){
        num = 3;
        (*idx) ++;
      }
    }
  }

  if(romano[(*idx)] == 'v' || romano[(*idx)] == 'V'){
    num = 5;
    (*idx) ++;
    if(romano[(*idx)] == 'i' || romano[(*idx)] == 'I'){
      num = 6;
      (*idx) ++;
      if(romano[(*idx)] == 'i' || romano[(*idx)] == 'I'){
        num = 7;
        (*idx) ++;
        if(romano[(*idx)] =='i' || romano[(*idx)] == 'I'){
          num = 8;
          (*idx) ++;
        }
      }
    }
  }

  return num;
}

//calcula o algorismo da casa de dezena
int dezena(char* romano, int* idx){

  int num = 0;

  if(romano[(*idx)] == 'x' || romano[(*idx)] == 'X'){
    num = 10;
    (*idx) ++;

    if(romano[(*idx)] == 'x' || romano[(*idx)] == 'X'){
      num = 20;
      (*idx) ++;
      if(romano[(*idx)] == 'x' || romano[(*idx)] == 'X'){
        num = 30;
        (*idx) ++;
      }
    }

    if(romano[(*idx)] == 'l' || romano[(*idx)] == 'L'){
      num = 40;
      (*idx) ++;
    }

    if(romano[(*idx)] == 'c' || romano[(*idx)] == 'C'){
      num = 90;
      (*idx) ++;
    }

  }

  if(romano[(*idx)] == 'l' || romano[(*idx)] == 'L'){
    num = 50;
    (*idx) ++;
    if(romano[(*idx)] == 'x' || romano[(*idx)] == 'X'){
      num = 60;
      (*idx) ++;
      if(romano[(*idx)] == 'x' || romano[(*idx)] == 'X'){
        num = 70;
        (*idx) ++;
        if(romano[(*idx)] == 'x' || romano[(*idx)] == 'X'){
          num = 80;
          (*idx) ++;
        }
      }
    }
  }

  return num;
}

//calcula o algorismo da casa da centena
int centena (char* romano, int* idx){

  int num = 0;

  if(romano[(*idx)] == 'c' || romano[(*idx)] == 'C'){
    num = 100;
    (*idx) ++;
    if(romano[(*idx)] == 'c' || romano[(*idx)] == 'C'){
      num = 200;
      (*idx) ++;
      if(romano[(*idx)] == 'c' || romano[(*idx)] == 'C'){
        num = 300;
        (*idx) ++;
      }
    }
    if(romano[(*idx)] == 'd' || romano[(*idx)] == 'D'){
      num = 400;
      (*idx) ++;
    }
    if(romano[(*idx)] == 'm' || romano[(*idx)] == 'M'){
      num = 900;
      (*idx) ++;
    }
  }

  if(romano[(*idx)] == 'd' || romano[(*idx)] == 'D'){
    num = 500;
    (*idx) ++;
    if(romano[(*idx)] == 'c' || romano[(*idx)] == 'C'){
      num = 600;
      (*idx) ++;
      if(romano[(*idx)] == 'c' || romano[(*idx)] == 'C'){
        num = 700;
        (*idx) ++;
        if(romano[(*idx)] == 'c' || romano[(*idx)] == 'C'){
          num = 800;
          (*idx) ++;
        }
      }
    }
  }

  return num;

}

//calcula o algorismo da casa de milhar
int milhar (char* romano, int* idx){

  int num = 0;

  if(romano[(*idx)] == 'm' || romano[(*idx)] == 'M'){
    num = 1000;
    (*idx) ++;
    if(romano[(*idx)] == 'm' || romano[(*idx)] == 'M'){
      num = 2000;
      (*idx) ++;
      if(romano[(*idx)] == 'm' || romano[(*idx)] == 'M'){
        num = 3000;
        (*idx) ++;
      }
    }
  }

  return num;
}

