
#include <stdio.h>

#include "fila.h"
#include "paciente.h"
#include "pilha.h"

typedef struct Sistema_s {
  Fila_t fila_normal;
  Fila_t fila_emergencial;
  Pilha_t historico;
  Pilha_t acoes_administrativas;
} Sistema_t;

Sistema_t novo_sistema()
{
  Sistema_t sistema;

  sistema.fila_normal = new_fila();
  sistema.fila_emergencial = new_fila();
  sistema.historico = new_pilha();
  sistema.acoes_administrativas = new_pilha();

  return sistema;
}

void exibir_paciente(paciente_t paciente)
{
  printf("Nome: %s | Idade: %d | Emergencia: %s\n",
         paciente.nome,
         paciente.idade,
         paciente.is_emergency ? "SIM" : "NAO");
}

void adicionar_paciente(Sistema_t* sistema, paciente_t paciente)
{
  if (paciente.is_emergency) {
    push_fila(&sistema->fila_emergencial, paciente);
    printf("\nPaciente adicionado na FILA DE EMERGENCIA!\n");
  } else {
    push_fila(&sistema->fila_normal, paciente);
    printf("\nPaciente adicionado na FILA NORMAL!\n");
  }

  push_pilha(&sistema->acoes_administrativas, paciente);
}

void atender_paciente(Sistema_t* sistema)
{
  paciente_t paciente;

  if (!is_empty_fila(&sistema->fila_emergencial)) {
    paciente = peek_fila(&sistema->fila_emergencial);
    pop_fila(&sistema->fila_emergencial);

    printf("\n=== ATENDIMENTO PRIORITARIO ===\n");
  } else if (!is_empty_fila(&sistema->fila_normal)) {
    paciente = peek_fila(&sistema->fila_normal);
    pop_fila(&sistema->fila_normal);

    printf("\n=== ATENDIMENTO NORMAL ===\n");
  } else {
    printf("\nNao ha pacientes aguardando.\n");
    return;
  }

  printf("Paciente atendido:\n");
  exibir_paciente(paciente);

  push_pilha(&sistema->historico, paciente);
}

void mostrar_historico(Sistema_t* sistema)
{
  if (is_empty_pilha(&sistema->historico)) {
    printf("\nNenhum atendimento finalizado.\n");
    return;
  }

  Node_t* atual = sistema->historico.topo;

  printf("\n=== HISTORICO DAS ULTIMAS CONSULTAS ===\n");

  while (atual != NULL) {
    exibir_paciente(atual->data);
    atual = atual->next;
  }
}

void mostrar_filas(Sistema_t* sistema)
{
  Node_t* atual;

  printf("\n========== FILA DE EMERGENCIA ==========\n");

  atual = sistema->fila_emergencial.head;

  if (atual == NULL) {
    printf("Fila vazia.\n");
  }

  while (atual != NULL) {
    exibir_paciente(atual->data);
    atual = atual->next;
  }

  printf("\n========== FILA NORMAL ==========\n");

  atual = sistema->fila_normal.head;

  if (atual == NULL) {
    printf("Fila vazia.\n");
  }

  while (atual != NULL) {
    exibir_paciente(atual->data);
    atual = atual->next;
  }
}

void desfazer_ultima_acao(Sistema_t* sistema)
{
  if (is_empty_pilha(&sistema->acoes_administrativas)) {
    printf("\nNenhuma acao para desfazer.\n");
    return;
  }

  paciente_t ultimo = peek_pilha(&sistema->acoes_administrativas);

  printf("\nUltima acao registrada:\n");
  exibir_paciente(ultimo);

  pop_pilha(&sistema->acoes_administrativas);

  printf("Acao removida da pilha administrativa.\n");
}

void executar_cenarios(Sistema_t* sistema)
{
  printf("\n===============================\n");
  printf("CENARIO 1 - FILA FIFO NORMAL\n");
  printf("===============================\n");

  adicionar_paciente(sistema, new_paciente("Ana", 25, false));
  adicionar_paciente(sistema, new_paciente("Bruno", 40, false));

  atender_paciente(sistema);

  printf("\n===============================\n");
  printf("CENARIO 2 - PRIORIDADE EMERGENCIAL\n");
  printf("===============================\n");

  adicionar_paciente(sistema, new_paciente("Carlos", 70, true));
  adicionar_paciente(sistema, new_paciente("Julia", 30, false));

  atender_paciente(sistema);

  printf("\n===============================\n");
  printf("CENARIO 3 - HISTORICO E DESFAZER\n");
  printf("===============================\n");

  mostrar_historico(sistema);
  desfazer_ultima_acao(sistema);
}

void free_sistema(Sistema_t* self)
{
  free_pilha(&self->acoes_administrativas);
  free_pilha(&self->historico);
  free_fila(&self->fila_normal);
  free_fila(&self->fila_emergencial);
}

int main()
{
  Sistema_t sistema = novo_sistema();
  executar_cenarios(&sistema);
  free_sistema(&sistema);
  return 0;
}
