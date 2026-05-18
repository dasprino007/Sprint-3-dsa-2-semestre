
# Sprint — Estruturas de Dados Aplicadas à Saúde Digital

Projeto desenvolvido para a disciplina de Estruturas de Dados.

## Objetivo
Simular o gerenciamento de atendimentos remotos da plataforma Blua utilizando:

- Fila FIFO para pacientes normais
- Fila prioritária para emergências
- Pilha LIFO para histórico de consultas
- Pilha para desfazer ações administrativas

Todas as estruturas foram implementadas utilizando listas encadeadas, sem bibliotecas prontas.

---

## Estruturas Utilizadas

### Fila
Operações implementadas:
- enqueue → `push_fila`
- dequeue → `pop_fila`
- peek → `peek_fila`
- is_empty → `is_empty_fila`

### Pilha
Operações implementadas:
- push → `push_pilha`
- pop → `pop_pilha`
- peek → `peek_pilha`
- is_empty → `is_empty_pilha`

---

## Funcionalidades

- Cadastro de pacientes
- Atendimento sequencial
- Priorização de emergências
- Histórico de consultas
- Desfazer última ação administrativa
- Cenários automáticos para demonstração

---

## Como executar

### Linux / Mac
```bash
gcc src/*.c -o blua
./blua
```

### Windows (MinGW)
```bash
gcc src/*.c -o blua.exe
blua.exe
```

---

## Cenários Demonstrados

### Cenário 1 — FIFO
Pacientes normais são atendidos na ordem de chegada.

### Cenário 2 — Emergência
Pacientes críticos possuem prioridade sobre os demais.

### Cenário 3 — Histórico e Desfazer
Consultas finalizadas são armazenadas em pilha e ações administrativas podem ser desfeitas.

---

## Estrutura do Projeto

```text
src/
 ├── fila.c
 ├── fila.h
 ├── pilha.c
 ├── pilha.h
 ├── lista_encadeada.c
 ├── lista_encadeada.h
 ├── paciente.c
 ├── paciente.h
 └── main.c
```
