#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// livro struct
typedef struct livro{
    int id;
    char nome[30];
    bool islea;
    bool isdoado;
    // node para a outra estrutura
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
    newlivro->id = 0;
    newlivro->isdoado = false;
    newlivro->islea = false;
    firstLivro = lastLivro = newlivro;

}
// sa�da de todos os livros
void outLivroData(){
    printf("======== Lista de livros no sistema ======== \n");
    livro *livroViews = firstLivro;
    while(livroViews != NULL ){

        printf("o livro : %s  \n com id: %i \n foi Lido? %d \n foi daodo? %d \n", livroViews->nome, livroViews->id, livroViews->islea, livroViews->isdoado);
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

void removeLivrosDoados(){
    printf("removendo livros doados...");
    livro *prev = NULL;
    livro *current = firstLivro;
    while (current != NULL) {
        if (current->isdoado == 1) {
            livro *to_free = current;
            current = current->nextLivro;
            if (prev == NULL) {
                firstLivro = current;
            } else {
                prev->nextLivro = current;
            }
            if (current == NULL) {
                lastLivro = prev;
            }
            free(to_free);
        } else {
            prev = current;
            current = current->nextLivro;
        }
    }
    // FIX se o livro for NULL
    if (firstLivro != NULL && lastLivro != NULL && lastLivro->nextLivro != NULL) {
        lastLivro = firstLivro;
        while (lastLivro->nextLivro != NULL) {
            lastLivro = lastLivro->nextLivro;
        }
    } else if (firstLivro == NULL) {
        lastLivro = NULL;
    }
}

int main()
{
    /*
        criacaoo do menu do sistema
    */

    printf("bem-vindo! ao livrosUP... \n");
    char* header = "======= LIVROS UP ======= \n";
    printf("%s",header);
    bool running = true;
    while(running)
    {
        // criando vari�vel de op��es
        int opc;
        printf("escolha uma das op��es: \n 0 - fechar \n 1 - ver lista \n 2 - adicionar livro \n 3 - editar livro \n 4 - remover livros dados \n");
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
            system("cls");
            printf("%s",header);
            printf("vamos adicionar um novo livro \n");
            inputNewLivro();
        }
        if( opc == 3){

            system("cls");
            printf("Vamos modificar o livro");
            int idlivro, doado,lido;

            printf("digite o ID do livro que deseja modificar \n");
            scanf("%d", &idlivro);

            printf("digite o valor se o livro foi doado: \n valores: 1 - SIM  0 - NÃO : \n");
            scanf("%d", &doado);
            printf("digite o valor se o livro foi lido: \n valores: 1 - SIM  0 - NÃO : \n");
            scanf("%d", &lido);

            int edicao = editLivro(idlivro,lido,doado);
            if(edicao == 1){
                printf("livro não encontrado... \n tente novamente.\n");
                system("pause");
            }
            
        }
        if ( opc == 4){
            system("cls");

            removeLivrosDoados();
            system("pause");
        }

        else {
            printf("Valor inválido, tente novamente com um valor válido \n");
            system("cls");
        }
    }
    return 0;
}
