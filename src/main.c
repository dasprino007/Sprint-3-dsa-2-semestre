#include <stdio.h>

#include "lista_encadeada.h"

int main()
{
  paciente_t paciente_1 = {.nome = "joão", .idade = 10};
  paciente_t paciente_2 = {.nome = "Diego", .idade = 20};
  paciente_t paciente_3 = {.nome = "Diana", .idade = 15};

  Node_t* lista = new_node(paciente_1);
  push_node(lista, paciente_2);
  push_node(lista, paciente_3);

  lista = pop_node(lista, paciente_3);
  free_list(lista);
  return 0;
}
