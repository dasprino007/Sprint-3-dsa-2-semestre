#include "pilha.h"

Pilha_t new_pilha()
{
  return (Pilha_t) {.topo = NULL, .size = 0};
};

void push_pilha(Pilha_t* self, paciente_t data)
{
  self->topo = push_in_first_node(self->topo, data);
  self->size++;
};

void pop_pilha(Pilha_t* self)
{
  Node_t* aux = self->topo->next;
  free(self->topo);
  self->topo = aux;
  self->size--;
};

paciente_t peek_pilha(Pilha_t* self)
{
  return self->topo->data;
};

bool is_empty_pilha(Pilha_t* self)
{
  return self->topo == NULL;
};

void free_pilha(Pilha_t* self)
{
  free_list(self->topo);
  self->size = 0;
};
