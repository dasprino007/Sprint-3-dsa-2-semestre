#include "test.h"

void test_pilha()
{
  paciente_t paciente_1 = {.nome = "joão", .idade = 10, .is_emergency = true};
  paciente_t paciente_2 = {.nome = "Diego", .idade = 20, .is_emergency = true};
  paciente_t paciente_3 = {.nome = "Diana", .idade = 13, .is_emergency = true};

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

void test_fila()
{
  paciente_t paciente_1 = {.nome = "joão", .idade = 10};
  paciente_t paciente_2 = {.nome = "Diego", .idade = 20};
  paciente_t paciente_3 = {.nome = "Diana", .idade = 15};

  Fila_t fila = new_fila();

  push_fila(&fila, paciente_1);
  push_fila(&fila, paciente_2);
  push_fila(&fila, paciente_3);

  paciente_t peek = peek_fila(&fila);
  printf("fila : %s\n", peek.nome);
  pop_fila(&fila);

  peek = peek_fila(&fila);

  free_fila(&fila);
}
