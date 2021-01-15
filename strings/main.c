#include <stdio.h>
#include <string.h>

// En las cadenas, el leng C, se agrega al finalizar un /0
int longitud(char cadena[]) {
  int l = 0;

  while(*cadena != '\0') {
    l++;
    cadena++;
  }
  return l;
}

int compare(char c1[], char c2[]) {
  while(*c1 != '\0') {
    if(*c1 != *c2) 
      return 0;
    c1++;
    c2++;
  }
  return 1;
}

int main() {
  char cadena1[] = "hola";
  char cadena2[] = "hola";

  printf("la longitud de %s, es %d. \n", cadena1, longitud(cadena1));

  // printf("cadena1 = %p, cadena2 = %p\n", cadena1, cadena2);

  if(compare(cadena1, cadena2))
    printf("Las cadenas son iguales\n");
  else 
    printf("Las cadenas no son iguales\n");
}


/*
arr[num]
===
arr + num * sizeof(tipo)
100 + 3  * sizeof(char)
*/