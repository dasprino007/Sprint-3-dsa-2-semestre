#ifndef FILA_H_
#define FILA_H_
#include "lista_encadeada.h"

typedef struct Fila_s {
  Node_t* topo;
} Fila_t;

Fila_t new_fila();
void push_fila(Fila_t* self);
void pop_fila(Fila_t* self);
paciente_t peek_fila(Fila_t* self);
bool is_empty_fila(Fila_t* self);
#endif  // FILA_H_
