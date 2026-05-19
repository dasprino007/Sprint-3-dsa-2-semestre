#include "fila.h"

Fila_t new_fila()
{
  return (Fila_t) {.head = NULL, .tail = NULL, .size = 0};
};

void free_fila(Fila_t* self)
{
  if (is_empty_fila(self)) {
    return;
  }

  free_list(self->head);
  self->tail = NULL;
  self->size = 0;
};

static void push_empty_fila(Fila_t* self, paciente_t data)
{
  self->tail = new_node(data);
  self->head = self->tail;
};

void push_fila(Fila_t* self, paciente_t data)
{
  if (is_empty_fila(self)) {
    push_empty_fila(self, data);
  } else {
    push_node(self->head, data);
    self->tail = self->tail->next;
  }
  self->size++;
};

void pop_fila(Fila_t* self)
{
  if (is_empty_fila(self)) {
    return;
  }
  if (self->head == self->tail) {
    free_fila(self);
    return;
  }

  Node_t* aux = self->head->next;
  free(self->head);
  self->head = aux;

  self->size--;
};

paciente_t peek_fila(Fila_t* self)
{
  return self->head->data;
};

bool is_empty_fila(Fila_t* self)
{
  return (bool)(self->head == NULL && self->tail == NULL || self->size == 0);
};
