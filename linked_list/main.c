#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  int longitud;
  struct node *next;
} node;

typedef node* lista;

// Tiempo constante
lista vacia() {
  return NULL; // = 0
}

// Tiempo constante
int es_vacia(lista list) {
  if(list == vacia()) return 1;
  return 0;
}

// Tiempo constante
lista agregar(lista list, int value) {
  if(es_vacia(list)) {
    node* n = malloc(sizeof(node));
    // (*n).value = value;
    n->value = value;
    n->next = NULL;
    n->longitud = 1;

    return n;
  } else {
    node* n = malloc(sizeof(node));
    n->longitud = list->longitud + 1;
    n->value = value;
    n->next = list;

    return n;
  }
}

// Tiempo lineal
void mostrar(lista list) {
  while(list != vacia()) {
    printf("%d ", list->value);
    list = list->next;
  }
}

// Tiempo constante
int longitud(lista list) {
  return list->longitud;
}

// Recursiva - Tiempo lineal
int len(lista list) {
  if(list == vacia()) return 0;
  return 1 + len(list->next);
}

// Tiempo lineal
int encuentra_menor(lista list) {
  int menor = list->value;
  int lon = len(list);

  if(lon == 0) return 0;
  if(lon == 1) return menor;
  else {
    for(int i = 0; i < lon-1; i++) {
      list = list->next;
      if(menor < list->value || menor == list->value) continue;
      else if(menor > list->value)
        menor = list->value;
    }
    return menor;
  }
}

// Tiempo lineal
// int menor(lista list) {
//   int menor =  list->value;

//   if(es_vacia(list)) return 0;

//   for(list=list->next; !es_vacia(list); list=list->next)
//     if(list->value < menor) 
//       menor = list->value;
//   return menor;
// }

// Tiempo lineal
int encuentra_mayor(lista list) {
  int mayor = list->value;
  int lon = len(list);

  if(lon == 0) return 0;
  if(lon == 1) return mayor;
  else {
    for(int i = 0; i < lon-1; i++) {
      list = list->next;
      if(mayor > list->value || mayor == list->value) continue;
      else if(mayor < list->value)
        mayor = list->value;
    }
    return mayor;
  }
}

// Tiempo lineal
// int mayor(lista list) {
//   int mayor =  list->value;

//   if(es_vacia(list)) return 0;

//   for(list=list->next; !es_vacia(list); list=list->next)
//     if(list->value > mayor) 
//       mayor = list->value;
//   return mayor;
// }


typedef int (*comparacion) (int, int);

// Funciones de alto orden - T Lineal
int extremo(lista list, comparacion func) {
  int numero =  list->value;

  if(es_vacia(list)) return 0;

  for(list=list->next; !es_vacia(list); list=list->next)
    if(func(list->value, numero)) 
      numero = list->value;
  return numero;
}

int greater(int x, int y) {
  return x > y;
}

int lower(int x, int y) {
  return x < y;
}


int main() {
  printf("Ingresa las ventas, escribe 0 si deseas parar el programa: \n");

  lista l = vacia(); // l : NULL
  int numero;

  do {
    scanf("%d", &numero);
    if(numero != 0)
      l = agregar(l, numero); // l : struct->value = 2
  } while(numero != 0);

  printf("\n%d\n", longitud(l));

  int mayor_v = extremo(l, greater);
  int menor_v = extremo(l, lower);

  printf("La venta mayor es: %d \n", mayor_v);
  printf("La venta menor es: %d \n", menor_v);

  printf("\n");
  mostrar(l);
  printf("\n%d", len(l));
}