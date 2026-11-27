#include <stdio.h>
#define tam 3
#define tam_max 9

int main() {
char tabuleiro [tam][tam];
char jogador = 'x';
int linha, coluna;
int jogadas = 0;
int vitoria = 0;

printf("Jogo da Velha\n");

printf("   0   1   2\n");

for (int i =0; i<tam; i++){     //percorrer as linhas vazias
    printf("%d ", i);  

    for (int j = 0; j<tam; j++){   //percorrer as colunas 
        //atribuir um espaço vazio
        tabuleiro[i][j] = ' ';
        printf(" %c ", tabuleiro[i][j]);
         
        // separador de colunas
        if (j<tam -1){
            printf("|");}
    
        if (i<tam -1 && j==tam-1){
            printf("\n  ---+---+---");
        }
    }
    printf("\n");
}
// O jogo continua enquanto o tabuleiro
    // nao estiver cheio e ninguem tiver vencido
while (jogadas < tam_max && vitoria == 0){

    printf("Vez do jogador %c\n", jogador);
    printf("Digite a linha e a coluna para jogar, Comecando com (X) (ex: 0 1):\n");
    scanf("%d %d", &linha, &coluna);
    // Verifica se a linha e coluna estao dentro do tabuleiro
        // e se a posicao escolhida esta vazia
    if (linha >= 0 && linha < tam && coluna >=0 && coluna < tam && tabuleiro[linha][coluna] == ' '){
       // Atribui o simbolo do jogador na posicao escolhida
        tabuleiro[linha][coluna] = jogador;
      // Incrementa o numero de jogadas
        jogadas++;

    
            // VERIFICAR LINHAS HORIZONTAIS
            for (int i = 0; i < tam; i++) {

                if (tabuleiro[i][0] == tabuleiro[i][1] &&
                    tabuleiro[i][1] == tabuleiro[i][2] &&
                    tabuleiro[i][0] != ' ') {

                    vitoria = 1;
                }
            }

            // VERIFICAR COLUNAS VERTICAIS
            for (int j = 0; j < tam; j++) {

                if (tabuleiro[0][j] == tabuleiro[1][j] &&
                    tabuleiro[1][j] == tabuleiro[2][j] &&
                    tabuleiro[0][j] != ' ') {

                    vitoria = 1;
                }
            }

            // VERIFICAR DIAGONAL PRINCIPAL
            // (do canto superior esquerdo ao inferior direito)
            if (tabuleiro[0][0] == tabuleiro[1][1] &&
                tabuleiro[1][1] == tabuleiro[2][2] &&
                tabuleiro[0][0] != ' ') {

                vitoria = 1;
            }

            // VERIFICAR DIAGONAL SECUNDARIA
            // (do canto superior direito ao inferior esquerdo)
            if (tabuleiro[0][2] == tabuleiro[1][1] &&
                tabuleiro[1][1] == tabuleiro[2][0] &&
                tabuleiro[0][2] != ' ') {

                vitoria = 1;
            }

            // Se alguem venceu, mostra a mensagem
            if (vitoria == 1) {
                printf("\nJogador %c venceu!\n", jogador);
            }

            // Se nao houve vitoria e o tabuleiro
            // ainda nao esta cheio, troca o jogador
            else if (jogadas < tam_max) {

                if (jogador == 'x') {
                    jogador = 'o';
                } else {
                    jogador = 'x';
                }
            }

        } else {

            // se a jogada for invalida, mostra a mensagem
             printf("Jogada invalida! Tente novamente.\n");
        }

        // MOSTRAR O TABULEIRO ATUALIZADO
        printf("\n   0   1   2\n");

        for (int i = 0; i < tam; i++) {

            printf("%d ", i);

            for (int j = 0; j < tam; j++) {

                printf(" %c ", tabuleiro[i][j]);

                if (j < tam - 1) {
                    printf("|");
                }
            }

            printf("\n");

            if (i < tam - 1) {
                printf("  ---+---+---\n");
            }
        }

    } // Fim do while

    // Se o tabuleiro estiver cheio e ninguem venceu,
    // significa que houve empate
    if (vitoria == 0 && jogadas == tam_max) {
        printf("\nEmpate! Ninguem venceu.\n");
    }

    return 0;
}
