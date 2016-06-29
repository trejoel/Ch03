// vector.h

#define CAPACIDAD_INICIAL 100

// Define un dato de tipo vector
typedef struct {
  int size;      // Espacios utilizados hasta ahora
  int capacity;  // total de espacios disponibles
  int *data;     // arreglo de enteros
} Vector;

void vector_init(Vector *vector);

void vector_append(Vector *vector, int value);

int vector_get(Vector *vector, int index);

void vector_set(Vector *vector, int index, int value);

void vector_increase_capacity_if_full(Vector *vector);

void vector_free(Vector *vector);