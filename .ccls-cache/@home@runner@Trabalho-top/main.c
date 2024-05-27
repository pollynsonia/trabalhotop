#include <stdio.h>
#include <stdlib.h>

int main() {

  int opcao = 0;
do {
  int deu_certo = system("clear");
  printf("               J O G O  F O D I C O . C    \n"); //mudar nome do jogo
  printf("\n");
  printf("1 - Iniciar\n"); // checar se pode botar esc
  printf("2 - Instruções\n");
  printf("3 - Sair\n");
  printf("\n");
  printf("Escolha uma opção => ");
  deu_certo = scanf("%i", &opcao);
  while (getchar() != '\n');

  switch (opcao) {
    case 1: {
      deu_certo = system("clear");
      char nome[31];
      printf("Nome do Jogador: ");
      deu_certo = scanf("%[^\n]s", nome);
      printf("Bem vindo %s\n", nome);
      printf("Pressiona ENTER para iniciar");
      getchar();
      break;
    
  case 2: 
    deu_certo = system("clear");
    printf("Instruções\n"); // mudar instruções
    printf("\n");
    printf("1. Ganhe\n");
    printf("2. Não perca\n");
    printf("3. Ame o Zé Regis\n");
    printf("4. MAME o Zé Regis\n");
    printf("5. Seja o vencedor\n");
    printf("\n");
    printf("Pressione enter para voltar ao menu\n");
    getchar();
    break;
      
    case 3: break;
      default:
        printf("Opção inválida, pressione ENTER para continuar");
      getchar();
    }
  }
} while (opcao != 3);

  
  
  return 0;
}