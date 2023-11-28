#include "avl.hpp"

AVL::AVL() {
    raiz = NULL;
}

AVL::~AVL() {
    limpaRecursivo(raiz);
}

void AVL::limpaRecursivo(Node* no) {
    if (no == NULL) {
        return;
    } else {
        limpaRecursivo(no->esq);
        limpaRecursivo(no->dir);
        delete no;
    }

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

void AVL::imprimiArvore(){
    imprimeRecursivo(raiz);
}

void AVL::imprimeRecursivo(Node *no) {
    if (no == NULL) {
        return;
    } else {
        imprimeRecursivo(no->esq);
        cout << no->chave << ":";
        for (int i = 0; i < no->qtdValores; i++) {
            cout << " ";
            cout << no->valor[i];
        }
        cout << endl;
        imprimeRecursivo(no->dir);
    }
}

void AVL::swap(int* valores, int pos1, int pos2){
    int aux = valores[pos1];
    valores[pos1] = valores[pos2];
    valores[pos2] = aux;
}

void AVL::sort(int* valores, int inicio, int fim) {
    if (inicio >= fim) return;

    int pivot = particao(valores, inicio, fim);

    sort(valores, inicio, pivot - 1);
    sort(valores, pivot + 1, fim);
}

int AVL::particao(int *valores, int inicio, int fim) {
    int i = inicio;

    for ( int j = inicio; j < fim; j++) {
        if (valores[j] < valores[fim]) {
            swap(valores, i++, j);
        }
    }
    swap(valores, i, fim);

    return i;
};

int AVL::contem(int* valores, int tamanho, int valor) {
    int contem = 0;
    for ( int i = 0; i < tamanho; i++ ) {
        if (valores[i] == valor) {
            contem = 1;
            break;
        }
    }
    return contem;
}

void AVL::insere(string chave, int valor) {
    insereRecursivo(&raiz, chave, valor, NULL);
}

void AVL::insereRecursivo(Node **no, string chave, int valor, Node* pai) {
    if (*no == NULL) {
        *no = novoNo(chave, valor);
        (*no)->pai = pai;
        return;
    }

    Node *atual = *no;

    if (chave < atual->chave) {
        insereRecursivo(&(atual->esq), chave, valor, atual);
    } else if (chave > atual->chave) {
        insereRecursivo(&(atual->dir), chave, valor, atual);
    } else {
        if (!contem(atual->valor, atual->qtdValores, valor)){
            atual->valor[atual->qtdValores] = valor;
            sort(atual->valor, 0, atual->qtdValores);
            atual->qtdValores++;
        }
        return;
    }

    atual->altura = 1 + max(altura(atual->esq), altura(atual->dir));
    int balanceamento = fatorBalanciamento(atual);

    if(balanceamento > 1) {
        if (fatorBalanciamento(atual->dir) < 0) {
            rotacaoEsquerda(&atual);
            rotacaoEsquerda(&atual);
            return;
        }
        else {
            rotacaoEsquerda(&atual);
            return;
        }
    }

    if(balanceamento < -1) {
        if (fatorBalanciamento(atual->esq) > 0) {
            rotacaoDireita(&atual);
            rotacaoDireita(&atual);
            return;
        }
        else {
            rotacaoDireita(&atual);
            return;
        }
    }
}

void AVL::rotacaoEsquerda(Node **no) {
    Node *x = *no;
    Node* y = x->dir;
    Node* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    if (T2 != nullptr) {
        T2->pai = x;
    }

    y->pai = x->pai;
    if (x->pai == nullptr) {
        raiz = y;
    } else if (x == x->pai->esq) {
        x->pai->esq = y;
    } else {
        x->pai->dir = y;
    }

    x->pai = y;
    
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
}

void AVL::rotacaoDireita(Node** no) {
    Node *y = *no;
    Node* x = y->esq;
    Node* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    if (T2 != nullptr) {
        T2->pai = y;
    }

    x->pai = y->pai;
    if (y->pai == nullptr) {
        raiz = x;
    } else if (y == y->pai->esq) {
        y->pai->esq = x;
    } else {
        y->pai->dir = x;
    }

    y->pai = x;

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
}

Node* AVL::novoNo(string chave, int valor) {
    Node* no = new Node();
    no->chave = chave;
    no->pai = NULL;
    no->dir = NULL;
    no->esq = NULL;
    no->valor[0] = valor;
    no->qtdValores = 1;
    no->altura = 1;

    return no;
}