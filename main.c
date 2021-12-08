#include "jogo.h"
#include "jogador.h"

int main(void){
     // Nome padrão para jogador, caso este não insira um nome
    char jogador1[] = "Jogador1", jogador2[] = "Jogador2";
    int res, opcao;

    do{
        res = menu();
        switch(res){
            case JOGAR:
                opcao = menuPlayer();//1 - Player1 vs Player2\n2 - Player vs CPU\n0 - voltar\n
                if(opcao){
                    if(perguntarNomes(jogador1, jogador2)){// Deseja alterar nome dos jogadores(mostrar nomes padrao)
                        puts("\nNomes alterados com sucesso :)\n");
                        getchar();
                        system("cls");
                    }
                    loopDoGame(jogador1, jogador2);
                    getchar();
                }
                break;
            case CREDITOS:
                printf("\n\tDesenvolvido unicamente por Daniel Korban (c)\n\n\t:) Se quiseres replicar, de os creditos pow!\n");
                getchar();
                break;
            case SAIR:
                puts("\tObrigado por jogar ;)\n");
                getchar();
                break;
                break;
            default:
                printf("\nOpcao invalida\n");
                getchar();
                break;
        }
        system("cls");
    }while(res !=  0);

    return 0;
}
