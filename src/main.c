#include "sistema.h"

int main()
{
  Sistema_t sistema = novo_sistema();

  int opcao;
  char nome[100];
  int idade;
  int emergencia;

  do {
    printf("\n=====================================\n");
    printf("  BLUA - SISTEMA DE TELECONSULTAS\n");
    printf("=====================================\n");
    printf("1 - Adicionar paciente\n");
    printf("2 - Atender proximo paciente\n");
    printf("3 - Mostrar filas\n");
    printf("4 - Mostrar historico\n");
    printf("5 - Desfazer ultima acao administrativa\n");
    printf("6 - Executar cenarios automaticos\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    limpar_buffer();

    switch (opcao) {
      case 1:
        printf("\nNome do paciente: ");
        fgets(nome, sizeof(nome), stdin);

        nome[strcspn(nome, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &idade);

        printf("Emergencia? (1 = SIM | 0 = NAO): ");
        scanf("%d", &emergencia);

        limpar_buffer();

        adicionar_paciente(&sistema, new_paciente(nome, idade, emergencia));

        break;

      case 2:
        atender_paciente(&sistema);
        break;

      case 3:
        mostrar_filas(&sistema);
        break;

      case 4:
        mostrar_historico(&sistema);
        break;

      case 5:
        desfazer_ultima_acao(&sistema);
        break;

      case 6:
        executar_cenarios(&sistema);
        break;

      case 0:
        printf("\nEncerrando sistema...\n");
        break;

      default:
        printf("\nOpcao invalida.\n");
    }

  } while (opcao != 0);
  free_sistema(&sistema);
  return 0;
}
