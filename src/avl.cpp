#include "avl.hpp"

AVL::AVL() {
    raiz = NULL;
}

AVL::~AVL() {

}

int AVL::max(int v1, int v2) {
    if (v1 > v2) {
        return v1;
    }
    return v2;
}

int AVL::altura(Node* node) {
    if (node == nullptr) return 0;
    return node->altura;
}

int AVL::fatorBalanciamento(Node *no) {
    if (no == NULL) return 0;

    int balance = altura(no->dir) - altura(no->esq);

    return balance;
}

string AVL::pesquisaRecursivo(Node *no, string chave) {
    
    if ( no == NULL ) {
        return "";
    }
    if ( chave < no->chave) {
        return pesquisaRecursivo(no->esq, chave);
    } else if ( chave > no->chave) {
        return pesquisaRecursivo(no->dir, chave);
    } else {
        return no->valor;
    }
}

void AVL::insere(string chave) {
    raiz = insereRecursivo(raiz, chave);
}

Node* AVL::insereRecursivo(Node *no, string chave) {
    if (no == NULL) {
        return novoNo(chave);
    }

    if ( chave < no->chave) {
        return insereRecursivo(no->esq, chave);
    } else if ( chave > no->chave) {
        return insereRecursivo(no->dir, chave);
    } else {
        return no;
    }

    no->altura = 1 + max(altura(no->esq), altura(no->dir));
    int balanceamente = fatorBalanciamento(no);

    if (balanceamente > 1 && chave < no->esq->chave) {
        return rotacaoDireita(no);
    }

    if (balanceamente < -1 && chave > no->dir->chave) {
        return rotacaoEsquerda(no);
    }

    if (balanceamente > 1 && chave > no->esq->chave) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    if (balanceamente < -1 && chave < no->dir->chave) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    return no;
}

Node* AVL::rotacaoEsquerda(Node *x) {
    Node* y = x->dir;
    Node* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    if (T2 != NULL) {
        T2->pai = x;
    }

    if (x != NULL) {
        x->pai = y;
    }

    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

Node* AVL::rotacaoDireita(Node* y) {
    Node* x = y->esq;
    Node* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    if (T2 != nullptr) {
        T2->pai = y;
    }

    if (y != nullptr) {
        y->pai = x;
    }

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

Node* AVL::novoNo(string chave) {
    Node* no = new Node();
    no->chave = chave;
    no->pai = NULL;
    no->dir = NULL;
    no->esq = NULL;
    no->altura = 1;

    return no;
}