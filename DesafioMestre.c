#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define ALCANCE 3


int main() {

char linha [LINHAS]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int coluna [COLUNAS]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int tabuleiro[LINHAS][COLUNAS];
for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
        tabuleiro[i][j] = 0;
    }
}

int x1 = 7, y1 = 3;  // Coordenadas 1 (cone)
int x2 = 2, y2 = 3;  // Coordenadas 2 (cruz)
int x3 = 1, y3 = 7;  // Coordenadas 3 (octaedro)


// Verifica e posiciona do 1 = cone
for (int i = 0; i < ALCANCE; i++) {
    int current_row = x1 + i;
    if (current_row >= LINHAS) {
        break; // Sai do loop se ultrapassar o limite inferior do tabuleiro
    }
    for (int j = -i; j <= i; j++) {
        int current_col = y1 + j;
        if (current_col >= 0 && current_col < COLUNAS) {
            tabuleiro[current_row][current_col] = 3;
        }
    }
}

// Verifica e posiciona do 2 = cruz
// Vertical
for (int i = -1; i <= 1; i++) {
    int current_row = x2 + i;
    if (current_row < 0 || current_row >= LINHAS) continue;
    tabuleiro[current_row][y2] = 3;
}
// Horizontal
for (int j = -2; j <= 2; j++) {
    int current_col = y2 + j;
    if (current_col < 0 || current_col >= COLUNAS) continue;
    tabuleiro[x2][current_col] = 3;
}

// Verifica e posiciona do 3 = (octaedro)
// Vertical
for (int i = -1; i <= 1; i++) {
    int current_row = x3 + i;
    if (current_row < 0 || current_row >= LINHAS) continue;
    tabuleiro[current_row][y3] = 3;
}
// Horizontal
for (int j = -1; j <= 1; j++) {
    int current_col = y3 + j;
    if (current_col < 0 || current_col >= COLUNAS) continue;
    tabuleiro[x3][current_col] = 3;
}

// Imprime cabeçalho das colunas
printf("Tabuleiro de Batalha Naval:\n");
printf("   ");
for (int i = 0; i < LINHAS; i++){
    printf("%c ", linha[i]);
}
printf("\n");

for (int i = 0; i < LINHAS; i++) {
    printf("%2d ", coluna[i]);
    for (int j = 0; j < COLUNAS; j++) {
        printf("%d ", tabuleiro[i][j]);
}
    printf("\n");
}

return 0;
}