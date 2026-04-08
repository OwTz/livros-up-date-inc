#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// node for list


// livro struct
struct livro{
    char nome[30];
    bool islea;
    bool isdoado;

    // nó para a outra estrutura
    struct livro *nextLivro;
};

// firstLivro e LastLivro

struct livro *firstLivro = NULL;
struct livro *lastLivro = NULL;

// input novo livro
void inputNewLivro(){
    struct livro *newlivro = (struct livro *) malloc( sizeof (struct livro));
    printf("digite o nome do livro: \n");
    scanf("%s",&newlivro->nome);

    printf("adicionado o livro: %s",&newlivro->nome);


}

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
        if( opc == 2){
            printf("%s",header);
            printf("vamos adicionar um novo livro \n");
            inputNewLivro();
        }
        else {
            printf("escolha uma opção válida \n");
            system("cls");
        }
    }
    return 0;
}
