#ifndef FILA_H_
#define FILA_H_
#include <stdbool.h>
#include <stddef.h>

#include "lista_encadeada.h"
#include "paciente.h"

typedef struct Fila_s {
  Node_t* head;
  Node_t* tail;
  size_t size;
} Fila_t;

Fila_t new_fila();
void push_fila(Fila_t* self, paciente_t data);
void pop_fila(Fila_t* self);
paciente_t peek_fila(Fila_t* self);
bool is_empty_fila(Fila_t* self);
void free_fila(Fila_t* self);
#endif  // FILA_H_
