#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "util.h"


Celula *popularListaOrdenadaArquivo(Celula *lista) {
    ifstream procurador;
    string linha;
    string data;
    int valor; 

    //o ideal seria o usuario informar o nome do arquivo com os dados de glicemia
    cout << "Populando a lista...\n";
    procurador.open("dados.txt");
    do {
        getline(procurador, linha);    
        data = linha.substr(0, linha.find(" "));
        valor = stoi(linha.substr(linha.find(" "), 100));
        lista = inserirOrdenado(valor, data, lista);     
    } while (!procurador.eof());


    procurador.close();
    return lista;
}

int main() {
    Celula *listaOrdenada = NULL; //nao precisa guardar a ocorrencia (0)
    Celula *listaControleOcorrencia = NULL; //nao precisa guardar a data (NULL)


    listaOrdenada = popularListaOrdenadaArquivo(listaOrdenada);
    cout << "lista com os valores glicemicos ordenados por valor\n";
    exibe(listaOrdenada);
    cout << "amostras: " << contaElementos(listaOrdenada) << endl;

    cout << "media glicemica: " << media(listaOrdenada) << endl;
    cout << "mediana glicemica: " << mediana(listaOrdenada) << endl;


    listaControleOcorrencia = copiaListaControleDuplicidade(listaOrdenada);
    listaControleOcorrencia = ordenarPelaQTD(listaControleOcorrencia);
    cout << "lista sem valores duplicados\n";
    exibirOcorrencias(listaControleOcorrencia);
    moda(listaControleOcorrencia);
    
    return 1;
}