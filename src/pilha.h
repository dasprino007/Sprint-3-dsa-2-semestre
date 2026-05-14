#ifndef PILHA_H_
#define PILHA_H_
#include "lista_encadeada.h"
#include "paciente.h"

typedef struct Pilha_s {
  Node_t* topo;
  size_t size;
} Pilha_t;

Pilha_t new_pilha();
void push_pilha(Pilha_t* self, paciente_t data);
void pop_pilha(Pilha_t* self);
paciente_t peek_pilha(Pilha_t* self);
bool is_empty_pilha(Pilha_t* self);
void free_pilha(Pilha_t* self);
#endif  // PILHA_H_
