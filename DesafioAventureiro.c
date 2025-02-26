#include <stdio.h>


int main() {

    char linha [10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coluna [10]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    int x1 = 2, y1 = 3;  // Coordenadas do primeiro navio (horizontal)
    int x2 = 5, y2 = 8;  // Coordenadas do segundo navio (vertical)
    int x3 = 1, y3 = 7;  // Terceiro navio (diagonal principal)
    int x4 = 5, y4 = 5;  // Quarto navio (diagonal secundária)
    
    // Verifica e posiciona o primeiro navio
    if (y1 + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[x1][y1 + i] = 3;
            }
        }
        
    // Verifica e posiciona o segundo navio
    if (x2 + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[x2 + i][y2] = 3;
        }
    }

    // Verifica e posiciona o terceiro navio
    if (x3 + 3 <= 10 && y3 + 2 >= 0) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[x3 + i][y3 + i] = 3;
        }
    }

    // Verifica e posiciona o terceiro navio
    if (x4 + 3 <= 10 && y4 - 2 >= 0) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[x4 + i][y4 - i] = 3;
        }
    }



    // Imprime cabeçalho das colunas
    printf("Tabuleiro de Batalha Naval:\n");
    printf("   ");
    for (int i = 0; i < 10; i++){
        printf("%c ", linha[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", coluna[i]);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
    }
        printf("\n");
    }
    
    return 0;
}