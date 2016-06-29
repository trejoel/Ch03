// vector-usage.c

#include <stdio.h>
#include "vector.h"

int main() {
  // declare and initialize a new vector
  int i,pos;
  Vector vector;  
  vector_init(&vector);
  printf("capacidad inicial: %d\n",vector.capacity);  

  // fill it up with 150 arbitrary values
  // this should expand capacity up to 200  
  for (i = 0; i <= 250; i++) {
    vector_append(&vector, i);
  }
  printf("capacidad inicial: %d\n",vector.capacity);  
  printf("Que posicion deseas obtener\n");
  scanf("%d",&pos);

  
  // print out an arbitrary value in the vector
  printf("El valor en la posicion %d es: %d\n",pos, vector_get(&vector, pos));

  // we're all done playing with our vector, 
  // so free its underlying data array
  vector_free(&vector);
}