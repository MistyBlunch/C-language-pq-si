#include <stdio.h>

// int* puntero a entero
void swap(int* a, int* b) {
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

int main() {
  int a = 0;
  int b = 0;

  scanf("%d", &a);
  scanf("%d", &b);

  swap(&a, &b);

  printf("a = %d, b = %d\n", a, b);
}