#ifndef LISTA_ENCADEADA_H_
#define LISTA_ENCADEADA_H_
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "paciente.h"

typedef struct Node_s {
  paciente_t data;
  struct Node_s* next;
} Node_t;

Node_t* new_node(paciente_t data);
Node_t* push_in_first_node(Node_t* self, paciente_t data);
void push_node(Node_t* self, paciente_t data);
Node_t* pop_node(Node_t* self, paciente_t data);
void free_list(Node_t* self);
#endif  // LISTA_ENCADEADA_H_
