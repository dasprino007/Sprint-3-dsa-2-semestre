#include <stdio.h>

#include "paciente.h"
#include "pilha.h"

void test_pilha()
{
  paciente_t paciente_1 = {.nome = "joão", .idade = 10};
  paciente_t paciente_2 = {.nome = "Diego", .idade = 20};
  paciente_t paciente_3 = {.nome = "Diana", .idade = 15};

  Pilha_t pilha = new_pilha();

  push_pilha(&pilha, paciente_1);
  push_pilha(&pilha, paciente_2);
  push_pilha(&pilha, paciente_3);

  paciente_t peek = peek_pilha(&pilha);
  printf("pilha : %s\n", peek.nome);
  pop_pilha(&pilha);

  peek = peek_pilha(&pilha);

  free_pilha(&pilha);
}

int main() {}
