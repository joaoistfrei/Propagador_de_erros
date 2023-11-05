typedef struct Valor {
    float corpo;
    float erro;
}valor;

typedef struct No {
    char opc;
    struct No* prox;
    valor* a;
    valor* b;
    valor* r;
    int p;
    float c;
}no;

typedef struct Lista {
    no *comeco;
    no *final;
} lista;


lista* criar_lista();
no* criar_no(char, valor*, valor*, valor*, int, float);
void insere(lista*, char, valor*, valor*, valor*, int, float);
void imprime_operacao(no*);
void imprime(lista*);
valor* soma(valor*, valor*);
valor* subtracao(valor*, valor*);
valor* produto(valor*, valor*);
valor* produto_constante(valor*, float);
valor* divisao(valor*, valor*);
valor* potencia(valor*, int);