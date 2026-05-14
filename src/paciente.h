#ifndef PACIENTE_H_
#define PACIENTE_H_

#include <stdbool.h>
#include <string.h>

typedef struct paciente_s {
  char* nome;
  int idade;
  bool is_emergency;
} paciente_t;

paciente_t new_paciente(char* nome, int idade, bool is_emergency);
bool paciente_equals(paciente_t value_1, paciente_t value_2);
bool is_paciente_emergency(paciente_t* self);
#endif  // PACIENTE_H_
