#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "livro.h"




int main()
{
    /*
        criação do menu do sistema
    */

    printf("bem-vindo! ao livrosUP... \n");
    char* header = "======= LIVROS UP ======= \n";
    printf("%s",header);
    bool running = true;
    while(running)
    {
        // criando variável de opções
        int opc;
        printf("escolha uma das opções: \n 0 - fechar \n 1 - ver lista \n 2 - adicionar livro \n 3 - colocar novo livro \n");
        scanf("%d",&opc);
        if(opc == 0){
            printf("fechando programa...");
            running = false;
        }
        if( opc == 1){
            system("cls");
            printf("verificando lista de livros : \n");
            system("pause");
        }
        else {
            printf("escolha uma opção válida \n");
            system("cls");
        }
    }
    return 0;
}
