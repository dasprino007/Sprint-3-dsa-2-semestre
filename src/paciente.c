#include "paciente.h"

paciente_t new_paciente(char* nome, int idade, bool is_emergency)
{
  return (paciente_t) {
      .nome = nome, .idade = idade, .is_emergency = is_emergency};
};

bool paciente_equals(paciente_t value_1, paciente_t value_2)
{
  return (bool)(strcmp(value_1.nome, value_2.nome) == 0
                && value_1.idade == value_2.idade);
};

bool is_paciente_emergency(paciente_t* self)
{
  return self->is_emergency;
};
