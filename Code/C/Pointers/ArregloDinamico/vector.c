// vector.c

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(Vector *vector) {
  // Inicializa el vector con una capacidad inicial de VECTOR_INITIAL_CAPACITY
  vector->size = 0;
  vector->capacity = CAPACIDAD_INICIAL;
  vector->data = malloc(sizeof(int) * vector->capacity);
}


void vector_append(Vector *vector, int value) {
  // verifica si hay espacio disponible
  vector_increase_capacity_if_full(vector);

  // Agrega un valor en el siguiente posicion de memoria
  vector->size++;
  vector->data[vector->size] = value;
}

int vector_get(Vector *vector, int index) {
  if (index >= vector->size || index < 0) {
    printf("El valor %d esta fuera del rango %d\n", index, vector->size);
    exit(1);
  }
  return vector->data[index];
}

void vector_set(Vector *vector, int index, int value) {
  if (index>vector->size){
    printf("El valor %d esta fuera de rango\n",index);
    exit(1);
  }  
  vector->data[index] = value;
}

void vector_increase_capacity_if_full(Vector *vector) {
  if (vector->size >= vector->capacity) {
    // Incrementa la capacidad del vector
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
  }
}


void vector_free(Vector *vector) {
  free(vector->data);
}