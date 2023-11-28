#ifndef AVL_HEADER
#define AVL_HEADER
#include <iostream>
#include <string>

using namespace std;

typedef struct node {
    string chave;
    int valor[100];
    int altura;
    int qtdValores;
    struct node *esq;
    struct node *dir;
    struct node *pai;
} Node;

class AVL {
    private:
        Node *raiz;
        int fatorBalanciamento(Node *no);
        int max(int v1, int v2);
        int altura(Node *no);
        int* pesquisaRecursivo(Node *no, string chave);
        void insereRecursivo(Node **no, string chave, int valor);
        void rotacaoEsquerda(Node **x);
        void rotacaoDireita(Node **x);
        Node* novoNo(string chave, int valor);
        void imprimeRecursivo(Node *no);
        void sort(int* valores, int inicio, int fim);
        int particao(int *valores, int inicio, int fim);
        void swap(int* valores, int pos1, int pos2);
        int contem(int* valores, int tamanho, int valor);
        void limpaRecursivo(Node* no);
    public:
        void imprimiArvore();
        void insere(string chave, int valor);
        AVL();
        ~AVL();
};

#endif