#include <stdio.h>
#include <stdlib.h>

#define JOGADOR_1 'X'
#define JOGADOR_2 'O'
#define CARACTERE_VAZIO '_'
#define EMPATE 'E'
#define QTD_LINHAS 3
#define QTD_COLUNAS 3

int linha;
int coluna;
int posicao;
int cont_jogadas = 0;
int tam_tabuleiro = QTD_LINHAS * QTD_COLUNAS;
char jogador_atual = JOGADOR_1;
char ganhador = EMPATE

int main() {

  int opcao = 0;
do {
  int deu_certo = system("clear");
  printf("               H A S H T A G    \n");
  printf("                  \033[1;31mX vs O\033[0m    \n");
  printf("\n");
  printf("1 - Iniciar\n"); 
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
    printf("Escreva números de 1 a 9 para jogar\n");
    printf("Não esqueça de digitar o número da posição\n");
    printf("Pressione ENTER para voltar ao menu");
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