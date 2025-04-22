#include <stdio.h>

#define TAMANHO_TABULEIRO 10     // Tamanho fixo do tabuleiro
#define TAMANHO_NAVIO 3          // Tamanho fixo dos navios
#define AGUA 0                   // Representa água no tabuleiro
#define NAVIO 3                  // Representa parte do navio no tabuleiro

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];  // Matriz que representa o tabuleiro

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais do navio horizontal (linha, coluna)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    // Validação para garantir que o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Posiciona o navio horizontal no tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1; // Encerra o programa com erro
    }

    // Coordenadas iniciais do navio vertical (linha, coluna)
    int linha_vertical = 5;
    int coluna_vertical = 6;

    // Validação para garantir que o navio vertical cabe no tabuleiro
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;

        // Verifica se há sobreposição com outro navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio vertical no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
            }
        } else {
            printf("Erro: Navios não podem se sobrepor.\n");
            return 1; // Encerra o programa com erro
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1; // Encerra o programa com erro
    }

    // Exibe o tabuleiro no console
    printf("\nTabuleiro Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da célula seguido de espaço
        }
        printf("\n"); // Quebra de linha ao fim de cada linha do tabuleiro
    }

    return 0; // Indica que o programa foi executado com sucesso
}
