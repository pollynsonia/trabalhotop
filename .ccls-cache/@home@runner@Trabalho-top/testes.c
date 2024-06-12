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
char ganhador = EMPATE;

int main(int argc, char const *argv[]) {
    int opcao = 0;
    do {
        int deu_certo = system("clear");
        printf("MEU JOGO\n");
        printf("1 - Iniciar\n");
        printf("2 - Resultado\n");
        printf("3 - Instruções\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao => ");
        deu_certo = scanf("%i", &opcao);
        while (getchar() != '\n'); // Limpar buffer do teclado

        switch (opcao) {
            case 1: {
                deu_certo = system("clear");
                char nome[31];
                printf("Nome do Jogador: ");
                deu_certo = scanf(" %[^\n]s", nome);
                printf("Ola %s\n", nome);
                printf("Pressione ENTER para iniciar\n");
                getchar();

                do {
                    char tabuleiro[QTD_LINHAS][QTD_COLUNAS];

                    for (linha = 0; linha < QTD_LINHAS; linha++) {
                        for (coluna = 0; coluna < QTD_COLUNAS; coluna++) {
                            tabuleiro[linha][coluna] = CARACTERE_VAZIO;
                        }
                    }

                    while (1) {
                        for (linha = 0; linha < QTD_LINHAS; linha++) {
                            for (coluna = 0; coluna < QTD_COLUNAS; coluna++) {
                                printf("%c ", tabuleiro[linha][coluna]);
                            }
                            printf("\n");
                        }

                        printf("Jogador %c, é sua vez\n", jogador_atual);
                        scanf("%d", &posicao);

                        if (!(posicao >= 1 && posicao <= 9)) {
                            printf("\nPosicao invalida, digite novamente.\n");
                            continue;
                        }

                        // Mapeando a posição digitada para a matriz tabuleiro
                        linha = (posicao - 1) / QTD_COLUNAS;
                        coluna = (posicao - 1) % QTD_COLUNAS;

                        if (tabuleiro[linha][coluna] != CARACTERE_VAZIO) {
                            printf("\nEssa posicao ja esta ocupada, digite novamente.\n");
                            continue;
                        }

                        tabuleiro[linha][coluna] = jogador_atual;

                        // Verificando se houve um vencedor
                        // (Implemente a lógica da verificação do vencedor)

                        cont_jogadas++;
                        if (cont_jogadas == tam_tabuleiro) {
                            printf("Deu Velha!\n");
                            break;
                        }

                        jogador_atual = (jogador_atual == JOGADOR_1) ? JOGADOR_2 : JOGADOR_1;
                    }

                    printf("Deseja jogar novamente? (s/n)\n");
                    char resposta;
                    scanf(" %c", &resposta);
                    if (resposta == 'n')
                        break;
                } while (1);
                break;
            }
            case 2:
                deu_certo = system("clear");
                printf("Resultado\n");
                printf("1o lugar - Jose - 1000\n");
                printf("2o lugar - Maria - 800\n");
                printf("3o lugar - Joao - 600\n");
                printf("4o lugar - Ana - 500\n");
                printf("5o lugar - Bia - 400\n");
                printf("Pressione ENTER para voltar");
                getchar();
                break;
            case 3:
                deu_certo = system("clear");
                printf("Instruções\n");
                printf("Escreva números de 1 a 9 para jogar\n");
                printf("Não esqueça de digitar o número da posição\n");
                printf("Pressione ENTER para voltar");
                getchar();
                break;
            case 4:
                break;
            default:
                printf("Opção inválida! Pressione ENTER para continuar");
                getchar();
        }
    } while (opcao != 4);
    return 0;
}