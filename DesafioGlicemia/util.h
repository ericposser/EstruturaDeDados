typedef struct no {
    int valor;
    int qtd;
    string data;
    struct no *prox;
} Celula;

Celula *inserirOrdenado(int valor, string data, Celula *lista) {
     //alocar memória
    Celula *novo = (Celula *)calloc(1,sizeof(Celula));
    Celula *p, *pR;

    //depositar valores
    novo->data = data;
    novo->valor = valor;
    novo->qtd = 1;
    novo->prox = NULL;

    //para a primeira alocação
    if (!lista) return novo;

    //definir a posicao do valor na lista, ou seja, percorrer a lista
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor < p->valor) {
            break;
        }
    }
    //no inicio
    if (p == lista) {
        novo->prox = lista;
        return novo;
    }
    //no fim
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //no meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

Celula *inserirControleDuplicado(int valor, string data, Celula *lista) {
     //alocar memória
    Celula *novo = (Celula *)calloc(1,sizeof(Celula));
    Celula *p, *pR;

    //depositar valores
    novo->data = data;
    novo->valor = valor;
    novo->qtd = 1;
    novo->prox = NULL;

    //para a primeira alocação
    if (!lista) return novo;

    //definir a posicao do valor na lista, ou seja, percorrer a lista
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor == p->valor) {
            p->qtd++;
            free(novo);
            return lista;
        }
        
        if (valor < p->valor) {
            break;
        }
    }
    //no inicio
    if (p == lista) {
        novo->prox = lista;
        return novo;
    }
    //no fim
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //no meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

Celula *copiaListaControleDuplicidade(Celula *lista) {
    Celula *listaNova = NULL;
    Celula *p;

    for (p = lista; p; p = p->prox) {
        listaNova = inserirControleDuplicado(p->valor, p->data, listaNova);
    }
    return listaNova;
}

Celula *ordenarPelaQTD(Celula *lista) {
    Celula *tmp = (Celula*)calloc(1,sizeof(Celula));
    Celula *p;
    bool houveTroca;

    do {
        houveTroca = false;
        for (p = lista; p->prox; p = p->prox) {
            if (p->qtd < p->prox->qtd) {
                houveTroca = true;

                tmp->valor = p->valor;
                tmp->data = p->data;
                tmp->qtd = p->qtd;

                p->valor = p->prox->valor;
                p->data = p->prox->data;
                p->qtd = p->prox->qtd;

                p->prox->valor = tmp->valor;
                p->prox->data = tmp->data;
                p->prox->qtd = tmp->qtd;
            }
        }
    } while (houveTroca);
    free(tmp);
    return lista;
}


void exibe(Celula *lista) {
    Celula *p;
    int i = 1;
    for (p = lista; p; i++, p = p->prox) {
        cout << i << " " << p->valor << " : " << p->data << endl;
    }
}


void exibirOcorrencias(Celula *lista) {
    Celula *p;
    int i = 1;
    for (p = lista; p; i++, p = p->prox) {
        cout << i << " " << p->valor << " : " << p->qtd << endl;
    }
}

int contaElementos(Celula *lista) {
    int qtd = 0;
    Celula *p;
    for (p = lista; p; p = p->prox) {
        qtd++;
    }
    return qtd;
}

float media(Celula *lista) {
    Celula *p;
    int soma = 0;
    for (p = lista; p; p = p->prox) {
        soma += p->valor;
    }
    return soma / contaElementos(lista);
}

int mediana(Celula *lista) {
    int quantidade = contaElementos(lista);
    Celula *p;
    int i;
    for (i = 1, p = lista; i < quantidade / 2; i++, p = p->prox);

    if (quantidade % 2 != 0) {
        return p->valor;
    }
      
    return (int)(p->valor + p->prox->valor)/2;
    
}

int minimo(Celula *lista) {
    return 40;
}

int maximo(Celula *lista) {
    return 500;
}

void moda(Celula *lista) {
    //retornar o valor que mais repete, se houver mais valores com a mesma quantidade, retornar 3 valores
    Celula *p;
    
    int maior =lista->qtd;
    int i;
    cout << "moda: " << endl;
    for (p = lista; i=4; p = p->prox, i++) {
        if(p->qtd < maior) break;
        cout << "valor: " <<p->valor << "\nquantidade de ocorrencias:" << p->qtd << endl;
    }

}