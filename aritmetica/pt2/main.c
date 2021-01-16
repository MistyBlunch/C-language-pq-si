#include <stdio.h>

int main() {
  int x = 5;
  int y = 2;

  int* z = &y;
  *(z+1) = 0;
  
  printf("x = %d\n", x);
}