#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jogador.h"

int perguntarNomes(char jogador1[], char jogador2[]){
    char nome1[20], nome2[20];

    puts("Nome do jogador1: ");
    scanf("%s", nome1);
    puts("\nNome do jogador2: ");
    scanf("%s", nome2);
    setbuf(stdin, NULL);

    char res;
    puts("\nDeseja mesmo salvar alteracoes?\n SIM(s) NAO(n)\n");
    scanf("%c", &res);
    setbuf(stdin, NULL);
    
    res = tolower(res);
    if(res == 's'){
        setNomePadrao(jogador1, nome1);
        setNomePadrao(jogador2, nome2);
        return 1;
    }else{
        /* Os nomes serao resetados em uma segunda partida
           redefinir padrão caso o jogador confirme que não deseja salvar alterações*/
        setNomePadrao(jogador1, "Jogador1");
        setNomePadrao(jogador2, "Jogador2");
        
    }
    return 0;
}

void setNomePadrao(char* string_destino, const char* string_origem){
    strcpy(string_destino, string_origem);
}

void mostrarCampeao(int ganhador){
    if(ganhador == 1)
        puts("\n\tParabens ao Jogador X :)\n");
    else
        puts("\n\tParabens ao Jogador O :)\n");
}