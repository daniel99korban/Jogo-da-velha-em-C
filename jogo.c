#include "jogo.h"
#include "jogador.h"
#include "console.h"

char tabuleiro[3][3] = {
        "###",
        "###",
        "###"
};

int menu(void){
    int res;
    puts("1 - JOGAR\n2 - CREDITOS\n0 - SAIR\n");
    scanf("%d", &res);
    setbuf(stdin, NULL);
    return res;
}

int menuPlayer(void){
    system("cls");
    int res;
    puts("1 - Player1 vs Player2\n2 - Player vs CPU\n0 - voltar\n");
    scanf("%d", &res);
    setbuf(stdin, NULL);
    return res;
}

int loopDoGame(char jogado1[], char jogado2[]){
    // Controlar vez de cada jogador
    vezJogador player;
    player.jogador1 = 1; player.jogador2 = 0;
    PosTab TabelaPosicao;
    int res = 0;

    while(true){
        system("cls");
    
        desenharTabuleiro();

        if(res == 1 || res == 2 ){
            mostrarCampeao(res);// Jogador 1 ou 2
            // Redefinir tabuleiro para reiniciar jogadas
            for(int i=0; i < 3; i++){
                strcpy(tabuleiro[i],"###");
            }
            break;
        }
        if(res == -1){
            puts("\n\tNinguem ganhou, deu velha :(\n");
            break;
        }

        if(player.jogador1 && res != 2){
           res = escolherJogada(TabelaPosicao, &player, jogado1, XIZ);
           if(res == 0) continue;
           res = verificarFimDeJogo(XIZ);
        }
        else if(player.jogador2 && res != 1){
           res = escolherJogada(TabelaPosicao, &player, jogado2, BOLA);
           if(res == 0) continue;
           res = verificarFimDeJogo(BOLA);
        }
    }
    return 0;
}

int escolherJogada(PosTab TabelaPosicao, vezJogador* player, char nomeJogador[], char X_OU_O){
    
    if(player->jogador1)
        textcolor(RED);
    else
        textcolor(WHITE);
    
    printf("\n\n\t%s - eh sua vez :)\n", nomeJogador);
    textcolor(GREEN);
    printf("\tLinha: ");
    scanf("%d", &TabelaPosicao.linha);
    setbuf(stdin, NULL);

    printf("\tColuna: ");
    scanf("%d", &TabelaPosicao.coluna);
    setbuf(stdin, NULL);
    // inseir jogada no tabuleiro
    if(!InserirJogada(TabelaPosicao, X_OU_O)){
        puts("\n\tOcupado :(\n");
        getchar();
        // O Jogo só continua se o jogador da vez escolher uma posição livre
        return 0;
    }
    if(X_OU_O == XIZ){
        player->jogador1 = 0;
        player->jogador2 = 1;
    }else{
        player->jogador2 = 0;
        player->jogador1 = 1;
    }
    return 1;
}

int InserirJogada(PosTab TabelaPosicao, char X_OU_O){// linha, coluna e caracter
    if(tabuleiro[TabelaPosicao.linha -1][TabelaPosicao.coluna -1] == VAZIO){
        tabuleiro[TabelaPosicao.linha-1][TabelaPosicao.coluna-1] = X_OU_O;
        return 1;
    }
    return 0;
}

void desenharTabuleiro(void){

    char Vazio[5][10] = { ".........",
                          ".........",
                          ".........",
                          ".........",
                          "........."};

    char marcarX[5][10] = {"#       #",
                           "  #   #  ",
                           "    #    ",
                           "  #   #  ",
                           "#       #"};

    char marcarO[5][10] = {"  #####  ",
                           " #     # ",
                           " #     # ",
                           " #     # ",
                           "  #####  "};

    char faixalateral[5][10] = {" | ",
                                " | ",
                                " | ",
                                " | ",
                                " | "};

    char faixaBase[1][34] = {"=========   =========   ========="};

    textcolor(WHITE);
    printf("\n            1           2          3\n\n");
    printf("\n\n\n   1   \n\n\n\n\n\n   2\n\n\n\n\n   3");
    gotoxy(1 , 5);
    for(int i = 0; i < 3 ; i++){
        for(int parte = 0; parte < 5 ; parte++){
        printf("\t");
            for(int j = 0; j < 3 ; j++){

                switch (tabuleiro[i][j]){
                    
                    case XIZ:
                        textcolor(RED);
                        imprime_parte(marcarX, parte); 
                        textcolor(GREEN);
                        break;
                    case BOLA:
                        textcolor(WHITE);
                        imprime_parte(marcarO, parte); 
                        textcolor(GREEN);
                        break;
                    case VAZIO:
                        textcolor(BROWN);
                        imprime_parte(Vazio, parte);
                        textcolor(GREEN);
                        break;
                }
                if(j <= 1){
                    textcolor(BROWN);
                    imprime_parte(faixalateral, parte);
                    textcolor(GREEN);
                }
            }
            printf("\n");
        }
        if(i < 2){
            textcolor(BROWN);
            printf("\t%s\n", faixaBase);
            textcolor(GREEN);
        }
    }
}

void imprime_parte(char desenho[5][10], int parte){
    printf("%s", desenho[parte]);
}


int verificarFimDeJogo(char X_ou_O){
    int contarLinha = 0, contarColuna = 0, contarDiagonal1 = 0, contarDiagonal2 = 0;
    int deuVelha = 0, aux = 3;

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            // ver se deu velha
            if(tabuleiro[i][j] != VAZIO)
                deuVelha++;
            // Varer X ou O nas linhas
            if(tabuleiro[i][j] == X_ou_O)
                contarLinha++;
            // Varer X ou O nas colunas
            if(tabuleiro[j][i] == X_ou_O)
                contarColuna++;
            // Varer X ou O nas diagonais...
            if(i==j && tabuleiro[i][j] == X_ou_O)// Diagonal principal
                contarDiagonal1++;

            if(tabuleiro[j][aux] == X_ou_O){// Diagonal secundaria
                contarDiagonal2++;
                aux--;
            }
        }
        if(contarLinha == 3 || contarColuna == 3 || contarDiagonal1 == 3 || contarDiagonal2 == 3){
            if( X_ou_O == XIZ)
                return 1;// Jogador1 Ganhou       
            else
                return 2;// Jogador2 Ganhou       
        }
        if(deuVelha == 9){
            return -1;// Deu velha
        }else{
            contarLinha = 0;
            contarColuna = 0;
            contarDiagonal2 = 0;
        }
    }
    return 0;// O jogo continua.
}