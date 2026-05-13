#ifndef PILHA_H_
#define PILHA_H_
#include "lista_encadeada.h"

typedef struct Pilha_s {
  paciente_t topo;
  Node_t* lista;
} Pilha_t;

Pilha_t new_pilha();
void push_pilha(Pilha_t* self);
void pop_pilha(Pilha_t* self);
paciente_t peek_pilha(Pilha_t* self);
bool is_empty_pilha(Pilha_t* self);
#endif  // PILHA_H_
