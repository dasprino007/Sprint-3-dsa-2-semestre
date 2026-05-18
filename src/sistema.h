#ifndef SISTEMA_H_
#define SISTEMA_H_
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

Sistema_t novo_sistema();
void exibir_paciente(paciente_t paciente);
void adicionar_paciente(Sistema_t* sistema, paciente_t paciente);
void atender_paciente(Sistema_t* sistema);
void mostrar_historico(Sistema_t* sistema);
void mostrar_filas(Sistema_t* sistema);
void desfazer_ultima_acao(Sistema_t* sistema);
void executar_cenarios(Sistema_t* sistema);
void free_sistema(Sistema_t* self);
void limpar_buffer();
#endif  // SISTEMA_H_
