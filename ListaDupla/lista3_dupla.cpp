#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "util.h"

CelulaD *popular(CelulaD *lista, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        lista = inserirListaDupla(rand() % 100, lista);
    }
    return lista;
}

int main() {
    CelulaD *lista = NULL;
    lista = popular(lista, 10);
    inserirListaDupla(2, lista);
    exibirListaDupla(lista);
    

    //removerListaDupla(2,lista);
    removerRepetidosListaDupla(2, lista);
    exibirListaDupla(lista);

    // lista = destruirListaDupla(lista);
    // cout << "Lista destruida......\n";
    // exibirListaDupla(lista);

    return 1;
}