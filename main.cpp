#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#define MAX 50
using namespace std;

//Struct Personagem e suas caracteristicas
struct Personagem{
  int id;
  char nome[MAX];
  char criador[MAX];
  char titulo[MAX];
  char relacoes[MAX];
};

//Função que fornece informação para a função ordenar, essa função trabalha com esquema de pesos, para ordenar o vetor
int compara(const void *a, const void *b){
    if((*(struct Personagem*)a).id == 
       (*(struct Personagem*)b).id)
        return 0;
    else 
    if((*(struct Personagem*)a).id < 
       (*(struct Personagem*)b).id)
        return -1;
    else
        return 1;
}

//Função apenas para criar um personagem com as entradas do usuário
Personagem criarPersonagem(){
    Personagem des;
    cout << "\nInsira o ID do personagem: ";
    cin >> des.id;
    getchar();
    cout << "\nInsira o nome do personagem: ";
    fgets(des.nome,MAX,stdin);
    setbuf(stdin, 0);
    cout << "\nInsira o nome do criador(a) do personagem: ";
    fgets(des.criador,MAX,stdin);
    cout << "\nInsira o titulo do personagem: ";
    fgets(des.titulo,MAX,stdin);
    cout << "\nInsira a relação: "; 
    fgets(des.relacoes,MAX,stdin);
    return des;
}

//Função que inclui um personagem no vetor de personagems
void incluir(Personagem array[],Personagem des, int tamanho){
    array[tamanho]=des;
}

//Função para realizar a exclusão de um personagem, utilizando o flag de exclusão
void excluir(Personagem array[],int tamanho, int id){
    for(int i=0; i<tamanho; i++){
        if(array[i].id = id){
            array[i].id=0;
            strcpy(array[i].nome,"None");
            strcpy(array[i].criador,"None");
            strcpy(array[i].titulo,"None");
            strcpy(array[i].relacoes,"None");
        }
    }

}

//Função que altera todos os campos do personagem
void alterar(Personagem array[],int tamanho, int id){
    for(int i=0; i<tamanho; i++){
        if(array[i].id = id){
                cout << "\nInsira o nome do personagem: ";
                fgets(array[i].nome,MAX,stdin);
                cout << "\nInsira o nome do criador(a) do personagem: ";
                fgets(array[i].criador,MAX,stdin);
                cout << "\nInsira o titulo do personagem: ";
                fgets(array[i].titulo,MAX,stdin);
                cout << "\nInsira a relação: "; 
                fgets(array[i].relacoes,MAX,stdin);
        }
    }
    
}

//Função que ordena o vetor de estruturas
void ordenar(Personagem array[],int tamanho){
    qsort(array,tamanho,sizeof(Personagem),compara);
}


int main(){
Personagem aux;
int option=9,id;
int tamanho=0;
Personagem *lista = (Personagem*) malloc(5*sizeof(Personagem));


//While com switch dentro, para realizar a chamada dos subprogramas
while(option!=0){
cout << "\n------------ Selecione uma ação ------------\nOpções:";
cout << "\n1 para incluir personagem";
cout << "\n2 para excluir personagem";
cout << "\n3 para alterar personagem";
cout << "\n4 para ordenar personagens";
cout << "\n5 para listar personagens";
cout << "\n0 para sair";
cout << "\nOpção: ";
cin >> option;
switch(option){
//Inclui um personagem
    case 1:
        aux = criarPersonagem();
        incluir(lista,aux,tamanho);
        ++tamanho; 
        lista = (Personagem*) realloc(lista,(tamanho+1+(tamanho*1/5)*sizeof(Personagem)));
        break;
//Exclui um personagem
    case 2:
        cout << "Qual o ID do personagem que deseja excluir: ";
        cin >> id;
        getchar();
        excluir(lista,tamanho,id);
        break;
//Altera um personagem
    case 3:
        cout << "Qual o ID do personagem que deseja alterar: ";
        cin >> id;
        getchar();
        alterar(lista,tamanho,id);
        break;
//Ordena o vetor de personagems
    case 4:
        ordenar(lista,tamanho);
        break;
//Lista os personagems
    case 5: 
        for(int i=0; i<tamanho; i++)
        {
            if(lista[i].id!=0){
                cout << "\n__________________________\n";
                cout <<"Id: " << lista[i].id <<endl;
                cout <<"Nome: " <<lista[i].nome <<endl;
                cout <<"Criador: " <<lista[i].criador <<endl;
                cout <<"Titlo: " <<lista[i].titulo <<endl;
                cout <<"Relacoes: " <<lista[i].relacoes <<endl;
            }
        }
        break;
    case 0:
        cout << "\n ----------Saindo----------\n"; 
        option = 0;
        break;
    }
}
//Libera o que foi alocado para lista
free(lista); 
}