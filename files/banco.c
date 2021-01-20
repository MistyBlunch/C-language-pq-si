#include <stdio.h>

int main() {
  FILE* archivo = fopen("banco.txt", "r+");

  int n;
  fscanf(archivo, "%d", &n);
  // printf("%d", n);

  char nombres[n][10];
  float saldos[n];

  for (int i = 0; i < n; i++) {
    fscanf(archivo, "%s", nombres[i]);
    fscanf(archivo, "%f", &saldos[i]);
  }

  for (int i = 0; i < n; i++) 
    fprintf(stdout, "Nombre %s, Saldo %f\n", nombres[i], saldos[i]);

    fprintf(archivo, "\nAdios!\n");
}