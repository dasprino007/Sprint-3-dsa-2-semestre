#include <stdio.h>

#include "fila.h"
#include "paciente.h"
#include "pilha.h"

typedef struct Sistema_s {
  Fila_t fila_normal;
  Fila_t fila_emergencial;
  Pilha_t historico;
  Pilha_t acoes_adminsitrativas;
} Sistema_t;

Sistema_t novo_sistema();
void adicionar_paciente(Sistema_t* sistema, paciente_t paciente);
void remover_paciente(Sistema_t* sistema, paciente_t paciente);
void desfazer_sistema(Sistema_t* sistema, paciente_t paciente);
void atender_paciente(Sistema_t* sistema,
                      paciente_t paciente,
                      const char* medico_nome);

int main() {}
