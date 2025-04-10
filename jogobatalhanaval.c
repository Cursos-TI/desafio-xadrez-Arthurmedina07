#include <stdio.h>
#include <string.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Funções auxiliares para criar matrizes de habilidade
void criarMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    memset(matriz, 0, sizeof(int) * TAM_HABILIDADE * TAM_HABILIDADE);
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = meio - i; j <= meio + i; j++) {
            if (j >= 0 && j < TAM_HABILIDADE) {
                matriz[i][j] = 1;
            }
        }
    }
}

void criarMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    memset(matriz, 0, sizeof(int) * TAM_HABILIDADE * TAM_HABILIDADE);
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        matriz[i][meio] = 1;
        matriz[meio][i] = 1;
    }
}

void criarMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    memset(matriz, 0, sizeof(int) * TAM_HABILIDADE * TAM_HABILIDADE);
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i <= meio; i++) {
        for (int j = meio - i; j <= meio + i; j++) {
            if (j >= 0 && j < TAM_HABILIDADE) {
                matriz[i][j] = 1;
                matriz[TAM_HABILIDADE - i - 1][j] = 1;
            }
        }
    }
}

// Função para sobrepor a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemX, int origemY) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int x = origemX + i - offset;
            int y = origemY + j - offset;
            if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO && habilidade[i][j] == 1) {
                tabuleiro[x][y] = 5; // Marca área afetada
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    tabuleiro[2][2] = 3; // Exemplo de navio

    int matrizCone[TAM_HABILIDADE][TAM_HABILIDADE];
    int matrizCruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int matrizOctaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criarMatrizCone(matrizCone);
    criarMatrizCruz(matrizCruz);
    criarMatrizOctaedro(matrizOctaedro);

    aplicarHabilidade(tabuleiro, matrizCone, 4, 4);
    aplicarHabilidade(tabuleiro, matrizCruz, 6, 6);
    aplicarHabilidade(tabuleiro, matrizOctaedro, 7, 2);

    printf("Tabuleiro com habilidades:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
