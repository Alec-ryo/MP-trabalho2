#include <romano.h>
#include <stdio.h>
#include <romano.h>

int main(int argc, char **argv){

  char romano[30];
  int num;

  system("clear");

  printf("Digite o valor em algarismo romano: ");
  scanf("%29s", romano);

  num = conversor(romano);

  printf("\n%d\n", num);

  return 0;
}
