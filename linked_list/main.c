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
void agregar(lista* list, int value) {
  if(es_vacia(*list)) {
    node* n = malloc(sizeof(node));
    // (*n).value = value;
    n->value = value;
    n->next = NULL;
    n->longitud = 1;

    *list = n;
  } else {
    node* n = malloc(sizeof(node));
    n->longitud = (*list)->longitud + 1;
    n->value = value;
    n->next = *list;

    *list = n;
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

void concatenar(lista list1, lista list2) {
  for(; !es_vacia(list1->next); list1=list1->next);
  list1->next = list2;
}

void eliminar(lista* list, int index) {
  if(es_vacia(*list)) return;
  if(index == 0) {
    lista li = *list;
    *list = (*list)->next;
    free(li);
    return;
  } else {
    return eliminar(&((*list)->next), index-1);
  }
}

void borrar(lista* list) {
  if(es_vacia(*list)) return;
  else {
    eliminar(list, 0);
    borrar(list);
  }
}

int main() {
  printf("Ingresa las ventas, escribe 0 si deseas parar el programa: \n");

  lista l1 = vacia(); // l : NULL
  lista l2 = vacia();
  lista l3 = vacia();
  int numero;

  do {
    scanf("%d", &numero);
    if(numero != 0)
      agregar(&l1, numero); // l : struct->value = 2
  } while(numero != 0);

  agregar(&l2, 7);
  agregar(&l2, 2);
  agregar(&l2, 3);

  agregar(&l3, 9);
  agregar(&l3, 4);
  agregar(&l3, 2);

  concatenar(l1, l2);
  concatenar(l1, l3);

  mostrar(l1);

  eliminar(&l1, 3);

  // printf("\n%d\n", longitud(l));

  // int mayor_v = extremo(l, greater);
  // int menor_v = extremo(l, lower);

  // printf("La venta mayor es: %d \n", mayor_v);
  // printf("La venta menor es: %d \n", menor_v);

  printf("\n");
  mostrar(l1);

  borrar(&l1);

  printf("\n");
  mostrar(l1);

  printf("\n%d", len(l1));
}