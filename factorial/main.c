#include <stdio.h>

int main() {
  int numero;

  printf("Ingrese un número: ");
  // Le tengo que especificar el tipo de formato
  scanf("%d", &numero);

  int factorial = 1;
  // for(int i=1; i<=numero; i++) {
  //   factorial *= i;
  // }

  int i = 1;
  // while (i <= numero) {
  //   factorial *= i;
  //   i++;
  // }

  // Verificar que no sea 0
  do {
    factorial *= i;
    i++;
  } while(i <= numero);

  // %d -> especificador de formato (es necesario agregarlo)
  // %d se va a imprimir una variable de tipo int(d de decimal)
  // %x -> hexadecimal

  // char cinco[] = "cinco";

  printf("El factorial de %d es: %d\n", numero, factorial);
}