#include <stdio.h>

#define TAMANHO_TABULEIRO 10     // Tamanho do tabuleiro (10x10)
#define TAMANHO_NAVIO 3          // Tamanho fixo de cada navio (3 células)
#define AGUA 0                   // Valor para representar água no tabuleiro
#define NAVIO 3                  // Valor para representar parte do navio no tabuleiro

// Função para verificar se há sobreposição nas coordenadas onde será posicionado o navio
int verificar_sobreposicao(int tabuleiro[10][10], int linha, int coluna, int direcao_linha, int direcao_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * direcao_linha;
        int c = coluna + i * direcao_coluna;
        if (tabuleiro[l][c] != AGUA) {
            return 1; // Retorna 1 se houver sobreposição
        }
    }
    return 0; // Retorna 0 se estiver livre
}

// Função para posicionar um navio no tabuleiro
void posicionar_navio(int tabuleiro[10][10], int linha, int coluna, int direcao_linha, int direcao_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * direcao_linha;
        int c = coluna + i * direcao_coluna;
        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    // Declara o tabuleiro e inicializa todas as posições com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // =============================
    // POSICIONAMENTO DOS NAVIOS
    // =============================

    // Navio 1 - Horizontal (linha fixa, coluna crescente)
    int l1 = 1, c1 = 2;
    if (c1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        !verificar_sobreposicao(tabuleiro, l1, c1, 0, 1)) {
        posicionar_navio(tabuleiro, l1, c1, 0, 1);
    }

    // Navio 2 - Vertical (coluna fixa, linha crescente)
    int l2 = 4, c2 = 7;
    if (l2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        !verificar_sobreposicao(tabuleiro, l2, c2, 1, 0)) {
        posicionar_navio(tabuleiro, l2, c2, 1, 0);
    }

    // Navio 3 - Diagonal Principal (linha++, coluna++)
    int l3 = 0, c3 = 0;
    if (l3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        c3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        !verificar_sobreposicao(tabuleiro, l3, c3, 1, 1)) {
        posicionar_navio(tabuleiro, l3, c3, 1, 1);
    }

    // Navio 4 - Diagonal Secundária (linha++, coluna--)
    int l4 = 6, c4 = 8;
    if (l4 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        c4 - (TAMANHO_NAVIO - 1) >= 0 &&
        !verificar_sobreposicao(tabuleiro, l4, c4, 1, -1)) {
        posicionar_navio(tabuleiro, l4, c4, 1, -1);
    }

    // =============================
    // EXIBIR O TABULEIRO
    // =============================
    printf("\nTabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o conteúdo da célula
        }
        printf("\n"); // Nova linha ao fim de cada linha da matriz
    }

    return 0; // Fim do programa
}

