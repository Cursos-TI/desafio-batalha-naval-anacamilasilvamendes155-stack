#include <stdio.h>

#define TAM_TAB 10
#define NAVIO 3
#define HABILIDADE 5

int main() {

    int tabuleiro[TAM_TAB][TAM_TAB] = {0}; 

    tabuleiro[0][0] = NAVIO;
    tabuleiro[0][1] = NAVIO;
    tabuleiro[0][2] = NAVIO;

    tabuleiro[2][5] = NAVIO;
    tabuleiro[3][5] = NAVIO;
    tabuleiro[4][5] = NAVIO;

    tabuleiro[6][0] = NAVIO;
    tabuleiro[7][1] = NAVIO;
    tabuleiro[8][2] = NAVIO;

    tabuleiro[9][7] = NAVIO;
    tabuleiro[8][8] = NAVIO;
    tabuleiro[7][9] = NAVIO;


    int cone[5][5] = {0};  
    int cruz[5][5] = {0};    
    int octaedro[5][5] = {0};

    for (int i = 0; i < 5; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            if (j >=0 && j < 5) {
                cone[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1; 
        cruz[i][2] = 1; 
    }

    for (int i = 0; i < 5; i++) {
        int start = (i <= 2) ? 2 - i : i - 2;
        int end   = (i <= 2) ? 2 + i : 6 - i;
        for (int j = start; j <= end; j++) {
            octaedro[i][j] = 1;
        }
    }

    int origConeLinha = 0, origConeColuna = 5;  
    int origCruzLinha = 5, origCruzColuna = 2;   
    int origOctLinha = 7, origOctColuna = 7;     

    void aplicarHabilidade(int matriz[5][5], int linOrig, int colOrig) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (matriz[i][j] == 1) {
                    int linTab = linOrig + i - 2; 
                    int colTab = colOrig + j - 2;
                    if (linTab >= 0 && linTab < TAM_TAB && colTab >= 0 && colTab < TAM_TAB) {
                        if (tabuleiro[linTab][colTab] == 0) 
                            tabuleiro[linTab][colTab] = HABILIDADE;
                    }
                }
            }
        }
    }

    aplicarHabilidade(cone, origConeLinha, origConeColuna);
    aplicarHabilidade(cruz, origCruzLinha, origCruzColuna);
    aplicarHabilidade(octaedro, origOctLinha, origOctColuna);

    printf("=== Tabuleiro com Habilidades ===\n\n");
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            if (tabuleiro[i][j] == 0) printf("~ ");      // água
            else if (tabuleiro[i][j] == NAVIO) printf("N "); // navio
            else if (tabuleiro[i][j] == HABILIDADE) printf("H "); 
        }
        printf("\n");
    }

    printf("\nLegenda: ~ = agua, N = navio, H = area de habilidade\n");

    return 0;
}
