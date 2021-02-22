#include <stdio.h>
#include <stdlib.h>

int* redim(int* arr, int size, int new_size) {
  int* tmp;
  tmp = malloc(sizeof(int)* new_size);

  for(int i=0; i<size; i++) {
    tmp[i] = arr[i];
  }

  free(arr);
  return tmp;
}

int main(){
  int* arr;
  arr = malloc(sizeof(int)*3);

  arr[0]= 3;
  arr[1]= 2;
  arr[2]= 1;

  arr = redim(arr, 3, 5);

  arr[3]= 5;
  arr[4]= 7;

  for (size_t i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  free(arr);
}