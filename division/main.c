#include <stdio.h>
#include <math.h>

int main() {
  int x, y;

  scanf("%d", &x);
  scanf("%d", &y);

  if(y == 0) return 1;
  
  printf("%d\n", x / y);
  return 0;
}