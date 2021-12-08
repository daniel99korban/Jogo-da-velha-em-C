#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JOGAR 1
#define SAIR 0
#define CREDITOS 2
#define VAZIO '#'
#define XIZ 'x'
#define BOLA 'o'
#define true 1// Evitar exportar biblioteca por utilizar apenas un recurso

struct posTabela{
    int linha;
    int coluna;
};

struct VezJogador{
    int jogador1;
    int jogador2;
};

typedef struct posTabela PosTab;
typedef struct VezJogador vezJogador;

int menu(void);
int menuPlayer(void);
int loopDoGame(char jogado1[], char jogado2[]);
int escolherJogada(PosTab TabelaPosicao , vezJogador* player, char nomeJogador[], char X_OU_O);
int InserirJogada(PosTab TabelaPosicao, char X_OU_O);
void desenharTabuleiro(void);
void imprime_parte(char desenho[5][10], int parte);
int verificarFimDeJogo(char X_ou_O);

#endif