#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// livro struct
typedef struct livro{
    int id;
    char nome[30];
    bool islea;
    bool isdoado;
    // n� para a outra estrutura
    struct livro *nextLivro;
 } livro; 

// firstLivro e LastLivro
 livro *firstLivro = NULL;
 livro *lastLivro = NULL;

// criando uma nova lista
void createNewList(){
     livro *newlivro = ( livro *) malloc( sizeof ( livro));

    newlivro->nextLivro = NULL;

    printf("digite o nome do livro: \n");
    scanf("%s",&newlivro->nome);
    printf("adicionado o livro: %s",&newlivro->nome);
    newlivro->isdoado = false;
    newlivro->islea = false;
    firstLivro = lastLivro = newlivro;

}
// sa�da de todos os livros
void outLivroData(){
     livro *livroViews = firstLivro;
    printf("iniciando novo produto \n");
    while(livroViews != NULL ){
        printf("o livro : %s  \n com id: %i \n", livroViews->nome, livroViews->id);
        livroViews = livroViews->nextLivro;
    }
}

// input novo livro
void inputNewLivro(){

    if(firstLivro ==  NULL){

        createNewList();

    } else {
        // node for list
         livro *newlivro = ( livro *) malloc( sizeof ( livro));
        printf("digite o nome do livro: \n");
        scanf("%s",&newlivro->nome);
        printf("adicionado o livro: %s",&newlivro->nome);
        newlivro->isdoado = false;
        newlivro->islea = false;
        newlivro->id = lastLivro->id + 1;

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
//  identificar o livro;
 livro *findLivro(int id){
     livro *curd;
    for (curd = firstLivro; curd ; curd=curd->nextLivro ){
        if(curd->id == id){
            return curd;
        } 
        
    }
    return NULL;
}

int editLivro( int id, bool lido, bool doado){
    livro *livroedit = findLivro(id);
    if(!livroedit){
        return 1;
    }
    livroedit->isdoado = doado;
    livroedit->islea = lido;
    return 0;
}


int main()
{
    /*
        cria��o do menu do sistema
    */

    printf("bem-vindo! ao livrosUP... \n");
    char* header = "======= LIVROS UP ======= \n";
    printf("%s",header);
    bool running = true;
    while(running)
    {
        // criando vari�vel de op��es
        int opc;
        printf("escolha uma das op��es: \n 0 - fechar \n 1 - ver lista \n 2 - adicionar livro \n 3 - colocar novo livro \n");
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
            printf("editar  v�lida \n");
            system("cls");
        }
    }
    return 0;
}
