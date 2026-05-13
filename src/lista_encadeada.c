#include "lista_encadeada.h"

#include <stdlib.h>
#include <string.h>

bool paciente_equals(paciente_t value_1, paciente_t value_2)
{
  return (bool)(strcmp(value_1.nome, value_2.nome) == 0
                && value_1.idade == value_2.idade);
};

Node_t* new_node(paciente_t data)
{
  Node_t* node = malloc(sizeof(Node_t));
  node->data = data;
  node->next = NULL;
  return node;
};

Node_t* push_node(Node_t* self, paciente_t data)
{
  while (self->next != NULL) {
    self = self->next;
  }
  self->next = new_node(data);
  return self;
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
  while (self != NULL) {
    Node_t* aux = self->next;
    free(self);

    self = aux;
  }
};
