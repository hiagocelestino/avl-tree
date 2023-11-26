#ifndef AVL_HEADER
#define AVL_HEADER
#include <iostream>

using namespace std;

typedef struct node {
    string chave;
    string valor;
    int altura;
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
        string pesquisaRecursivo(Node *no, string chave);
        void insere(string chave);
        Node* insereRecursivo(Node *no, string chave);
        Node* rotacaoEsquerda(Node *x);
        Node* rotacaoDireita(Node *x);
        Node* novoNo(string chave);
    public:
        AVL();
        ~AVL();
};

#endif