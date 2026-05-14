#include "lista_encadeada.h"

Node_t* new_node(paciente_t data)
{
  Node_t* node = malloc(sizeof(Node_t));
  *node = (Node_t) {
      .data = data,
      .next = NULL,
  };
  return node;
};

void push_node(Node_t* self, paciente_t data)
{
  while (self->next != NULL) {
    self = self->next;
  }
  self->next = new_node(data);
};

Node_t* push_in_first_node(Node_t* self, paciente_t data)
{
  Node_t* aux = self;
  self = new_node(data);
  self->next = aux;

  return self;
};

Node_t* pop_node(Node_t* self, paciente_t data)
{
  bool is_found = paciente_equals(self->data, data);

  if (is_found) {
    Node_t* aux = self->next;
    free(self);
    self = aux;
    return self;
  };

  while (self->next != NULL && !paciente_equals(self->next->data, data)) {
    self = self->next;
  }

  is_found = paciente_equals(self->next->data, data);

  if (is_found) {
    Node_t* aux = self->next->next;
    free(self->next);
    self->next = aux;
  }

  return self;
};

void free_list(Node_t* self)
{
  Node_t* aux = NULL;
  while (self != NULL) {
    aux = self->next;
    free(self);

    self = aux;
  }
};
