#include <iostream>
#include <string>
#include "avl.hpp"

using namespace std;
int main() {
    AVL avl = AVL();
    string palavra;
    int pagina;

    int lim = 100;
    int contador = 0;
    while (contador < lim){
        cin >> palavra >> pagina;
        avl.insere(palavra, pagina);
        contador++;
    }
    avl.imprimiArvore();
    return 0;
}
