#include <stdio.h>

int main() {
  char a[3] = {7,8,5};

  *(a + 0) = 0;
  *(a + 1) = 0;
  *(a + 2) = 0;

  printf("%d %d %d\n", *a, *(a+1),*(a+2));
}