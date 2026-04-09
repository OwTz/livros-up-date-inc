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

// criando uma nova lista
void createNewList(){
    struct livro *newlivro = (struct livro *) malloc( sizeof (struct livro));

    newlivro->nextLivro = NULL;

    printf("digite o nome do livro: \n");
    scanf("%s",&newlivro->nome);
    printf("adicionado o livro: %s",&newlivro->nome);
    newlivro->isdoado = false;
    newlivro->islea = false;

    firstLivro = lastLivro = newlivro;

}
// saída de todos os livros
void outLivroData(){
    struct livro *livroViews = firstLivro;
    printf("iniciando novo produto \n");
    while(livroViews != NULL ){
        printf("o livro : %s \n", livroViews->nome);
        livroViews = livroViews->nextLivro;
    }
}

// input novo livro
void inputNewLivro(){

    if(firstLivro ==  NULL){

        createNewList();

    } else {

        struct livro *newlivro = (struct livro *) malloc( sizeof (struct livro));
        printf("digite o nome do livro: \n");
        scanf("%s",&newlivro->nome);
        printf("adicionado o livro: %s",&newlivro->nome);
        newlivro->isdoado = false;
        newlivro->islea = false;

        if(firstLivro == lastLivro){

            firstLivro->nextLivro = newlivro;
            lastLivro = newlivro;
            newlivro->nextLivro = NULL;
        } else {
            lastLivro->nextLivro = newlivro;
            newlivro->nextLivro = NULL;
            lastLivro = newlivro;
        }
    }

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
            outLivroData();
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
