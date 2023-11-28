#include <iostream>
#include <string>
#include "avl.hpp"

using namespace std;
int main() {
    AVL avl = AVL();
    string palavra;
    int pagina;

    int lim = 1000;
    int contador = 0;
    while (contador < lim){
        cin >> palavra >> pagina;
        avl.insere(palavra, pagina);
        contador++;
    }

    // while (!feof(stdin)){
    //     cin >> palavra >> pagina;
    //     avl.insere(palavra, pagina);
    // }
    avl.imprimiArvore();
    return 0;
}
