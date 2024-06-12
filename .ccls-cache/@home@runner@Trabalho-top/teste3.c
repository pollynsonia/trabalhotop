#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Para usar a função isdigit()
#include <string.h> // Para manipulação de strings

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

// Definição da estrutura Jogador
struct Jogador {
    char nome[31];
    int vitorias;
    int derrotas;
    int empates;
};

// Declaração das variáveis dos jogadores
struct Jogador jogador1 = {.nome = "", .vitorias = 0, .derrotas = 0, .empates = 0};
struct Jogador jogador2 = {.nome = "", .vitorias = 0, .derrotas = 0, .empates = 0};

void limpar_buffer() {
    while (getchar() != '\n'); // Limpar buffer do teclado
}

void inicializar_tabuleiro(char tabuleiro[QTD_LINHAS][QTD_COLUNAS]) {
    for (linha = 0; linha < QTD_LINHAS; linha++) {
        for (coluna = 0; coluna < QTD_COLUNAS; coluna++) {
            tabuleiro[linha][coluna] = CARACTERE_VAZIO;
        }
    }
}

void imprimir_tabuleiro(char tabuleiro[QTD_LINHAS][QTD_COLUNAS]) {
    for (linha = 0; linha < QTD_LINHAS; linha++) {
        for (coluna = 0; coluna < QTD_COLUNAS; coluna++) {
            printf("%c ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

int verificar_vencedor(char tabuleiro[QTD_LINHAS][QTD_COLUNAS], char jogador) {
    // Verificar linhas
    for (linha = 0; linha < QTD_LINHAS; linha++) {
        if (tabuleiro[linha][0] == jogador && tabuleiro[linha][1] == jogador && tabuleiro[linha][2] == jogador) {
            return 1;
        }
    }
    // Verificar colunas
    for (coluna = 0; coluna < QTD_COLUNAS; coluna++) {
        if (tabuleiro[0][coluna] == jogador && tabuleiro[1][coluna] == jogador && tabuleiro[2][coluna] == jogador) {
            return 1;
        }
    }
    // Verificar diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1;
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1;
    }
    return 0;
}

void atualizar_estatisticas(struct Jogador *vencedor, struct Jogador *perdedor) {
    vencedor->vitorias++;
    perdedor->derrotas++;
}

void exibir_estatisticas(struct Jogador jogador) {
    printf("Jogador: %s\n", jogador.nome);
    printf("Vitórias: %d\n", jogador.vitorias);
    printf("Derrotas: %d\n", jogador.derrotas);
    printf("Empates: %d\n", jogador.empates);
}

int main(int argc, char const *argv[]) {
    int opcao = 0;
    do {
        system("clear"); // Limpa o terminal
        printf("               H A S H T A G    \n");
        printf("                  \033[1;31mX vs O\033[0m    \n");
        printf("\n");
        printf("1 - Iniciar\n"); 
        printf("2 - Resultados\n");
        printf("3 - Instruções\n");
        printf("4 - Sair\n");
        printf("\n");
        printf("Escolha uma opção => ");
        scanf("%i", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: {
                system("clear");
                printf("Nome do Jogador 1: ");
                scanf(" %[^\n]s", jogador1.nome);
                limpar_buffer();
                printf("Nome do Jogador 2: ");
                scanf(" %[^\n]s", jogador2.nome);
                limpar_buffer();

                printf("Olá %s e %s\n", jogador1.nome, jogador2.nome);
                printf("Pressione ENTER para iniciar\n");
                getchar();

                do {
                    char tabuleiro[QTD_LINHAS][QTD_COLUNAS];
                    inicializar_tabuleiro(tabuleiro);
                    cont_jogadas = 0;
                    jogador_atual = JOGADOR_1;

                    while (1) {
                        system("clear");
                        imprimir_tabuleiro(tabuleiro);

                        printf("Jogador %c (%s), é sua vez (1-9 ou 0 para sair): ", jogador_atual, (jogador_atual == JOGADOR_1) ? jogador1.nome : jogador2.nome);
                        if (scanf("%d", &posicao) != 1 || (posicao != 0 && !(posicao >= 1 && posicao <= 9))) {
                            printf("Entrada inválida. Digite novamente.\n");
                            limpar_buffer();
                            printf("Pressione ENTER para continuar...");
                            getchar(); // Pausa para permitir a leitura da mensagem de erro
                            continue;
                        }

                        limpar_buffer();

                        if (posicao == 0) {
                            printf("Você escolheu sair do jogo. Pressione ENTER para continuar");
                            getchar();
                            break;
                        }

                        linha = (posicao - 1) / QTD_COLUNAS;
                        coluna = (posicao - 1) % QTD_COLUNAS;

                        if (tabuleiro[linha][coluna] != CARACTERE_VAZIO) {
                            printf("\nEssa posição já está ocupada, digite novamente.\n");
                            printf("Pressione ENTER para continuar...");
                            getchar();
                            continue;
                        }

                        tabuleiro[linha][coluna] = jogador_atual;

                        if (verificar_vencedor(tabuleiro, jogador_atual)) {
                            system("clear");
                            imprimir_tabuleiro(tabuleiro);
                            printf("Jogador %c (%s) venceu!\n", jogador_atual, (jogador_atual == JOGADOR_1) ? jogador1.nome : jogador2.nome);
                            if (jogador_atual == JOGADOR_1) {
                                atualizar_estatisticas(&jogador1, &jogador2);
                            } else {
                                atualizar_estatisticas(&jogador2, &jogador1);
                            }
                            break;
                        }

                        cont_jogadas++;
                        if (cont_jogadas == tam_tabuleiro) {
                            system("clear");
                            imprimir_tabuleiro(tabuleiro);
                            printf("Deu Velha!\n");
                            jogador1.empates++;
                            jogador2.empates++;
                            break;
                        }

                        jogador_atual = (jogador_atual == JOGADOR_1) ? JOGADOR_2 : JOGADOR_1;
                    }

                    printf("Deseja jogar novamente? (s/n)\n");
                    char resposta;
                    scanf(" %c", &resposta);
                    limpar_buffer();
                    if (resposta == 'n')
                        break;
                } while (1);
                break;
            }
            case 2:
                system("clear");
                printf("Resultados\n");
                exibir_estatisticas(jogador1);
                printf("\n");
                exibir_estatisticas(jogador2);
                printf("Pressione ENTER para voltar");
                getchar();
                break;
            case 3:
                system("clear");
                printf("Instruções\n");
                printf("Escreva números de 1 a 9 para jogar\n");
                printf("Não esqueça de digitar o número da posição\n");
                printf("Digite 0 caso queira sair no meio da partida\n");
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
