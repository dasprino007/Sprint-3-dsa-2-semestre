#include "sistema.h"

int main()
{
  Sistema_t sistema = novo_sistema();
  executar_cenarios(&sistema);
  free_sistema(&sistema);
  return 0;
}
