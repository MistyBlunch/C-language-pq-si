// No pertenece al leng, sino al compilador
// No es librería, se necesita poner ya que no conoce los tipos de los argumentos dentro de printf
// Ayuda a reconocer el tipo de los argumentos que se les pasa a las funciones
#include <stdio.h>
#define NUM 100

// Esto es stdio, funcará por más que no haga el include de stdio.h
// extern int printf(const char *__restric __format, ...);

// Pasos del compilador
// 1. Pre compilacion(pre procesado) -> Agrega las cabeceras
// 2. Análisis sintáctico(analizador léxico) -> Verifica en qué leng se está manejando el codigo(C o C++)
// 3. Chequeo de tipos -> Verifica que los tipos de los operandos sean válidos
// 4. Pasar a lenguaje Assembly
// 5. Enlazado (Linkear). 
int main() {
  int x;
  x = 5 / &x; // No será válido

  printf("%d", NUM); // NUM será reemplazado por 100
  printf("hola mundo\n");
}

/* 
Librería VS Header:


*/