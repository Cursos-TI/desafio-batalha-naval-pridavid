#include <stdio.h>

#define TAM 10           // Tamanho do tabuleiro
#define TAM_HAB 5        // Tamanho das matrizes de habilidade
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Inicializa o tabuleiro com água
void inicializar_tabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função genérica para sobrepor uma matriz de habilidade no tabuleiro
void aplicar_habilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origem_l, int origem_c) {
    int centro = TAM_HAB / 2; // Centro da matriz de habilidade

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha_tabuleiro = origem_l + (i - centro);
            int coluna_tabuleiro = origem_c + (j - centro);

            // Verifica se está dentro dos limites do tabuleiro
            if (linha_tabuleiro >= 0 && linha_tabuleiro < TAM &&
                coluna_tabuleiro >= 0 && coluna_tabuleiro < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linha_tabuleiro][coluna_tabuleiro] == AGUA) {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = HABILIDADE;
                }
            }
        }
    }
}

// Cria a forma de cone apontando para baixo
void criar_cone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i) && i <= TAM_HAB / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Cria a forma de cruz
void criar_cruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Cria a forma de octaedro (losango)
void criar_octaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Exibe o tabuleiro com caracteres distintos
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro com Habilidades:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf("~ ");  // Água
            else if (tabuleiro[i][j] == NAVIO)
                printf("# ");  // Navio
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("* ");  // Habilidade
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializar_tabuleiro(tabuleiro);

    // Posicionando manualmente alguns navios (exemplo)
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;

    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][6] = NAVIO;
    tabuleiro[8][6] = NAVIO;

    // Matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    criar_cone(cone);
    criar_cruz(cruz);
    criar_octaedro(octaedro);

    // Aplicando as habilidades em posições do tabuleiro
    aplicar_habilidade(tabuleiro, cone, 1, 2);       // Posição central do cone
    aplicar_habilidade(tabuleiro, cruz, 5, 5);       // Centro da cruz
    aplicar_habilidade(tabuleiro, octaedro, 8, 2);   // Centro do octaedro

    // Exibe o tabuleiro com água (~), navios (#) e habilidades (*)
    exibir_tabuleiro(tabuleiro);

    return 0;
}
