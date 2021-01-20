#include <stdio.h>
#include <stdlib.h>

// argc -> arg count
// Cantidad de parametros y los parametros 
int main(int argc, char** argv) {
  // for (int i = 0; i < argc; i++) 
  //   printf("%s\n", argv[i]);

  if(argc != 3) return 1;

  printf("%d", atoi(argv[1]) / atoi(argv[2]));
  return 0;
}

// int* == int a[]