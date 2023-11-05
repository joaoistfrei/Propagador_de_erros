#include <stdio.h>
#include <stdlib.h>
#include "propagadorerro.h"

lista *criar_lista() {
    lista *p = (lista*) calloc(1, sizeof(lista));
    p->comeco = NULL;
    p->final = NULL;

    return p;
}

no *criar_no(char opc, valor* a, valor* b, valor* r, int p, float c) {
    no *novo = (no*) calloc(1, sizeof(no));
    novo->a = a;
    novo->b = b;
    novo->opc = opc;
    novo->p = p;
    novo->c = c;
    novo->r = r;
    novo->prox = NULL;
    return novo;
}

void insere(lista* l, char opc, valor* a, valor* b, valor* r, int p, float c) {
    no* novo = criar_no(opc, a, b, r, p, c);
    if(l->comeco == NULL) {
        l->comeco = novo;
        l->final = novo;
    }
    else{
        no* ref = l->final;
        ref->prox = novo;
        l->final = novo;
    }
}

void imprime_operacao(no* n){
    switch(n->opc) {
        case 'A':
            printf("(%.3f +- %.3f) + (%.3f +- %.3f) = (%.3f +- %.3f)", n->a->corpo, n->a->erro, n->b->corpo, n->b->erro, n->r->corpo, n->r->erro);
            break;
        case 'S':
            printf("(%.3f +- %.3f) - (%.3f +- %.3f) = (%.3f +- %.3f)", n->a->corpo, n->a->erro, n->b->corpo, n->b->erro, n->r->corpo, n->r->erro);
            break;
        case 'M':
            printf("(%.3f +- %.3f) x (%.3f +- %.3f) = (%.3f +- %.3f)", n->a->corpo, n->a->erro, n->b->corpo, n->b->erro, n->r->corpo, n->r->erro);
            break;
        case 'C':
            printf("(%.3f +- %.3f) x %.3f = (%.3f +- %.3f)", n->a->corpo, n->a->erro, n->c, n->r->corpo, n->r->erro);
            break;
        case 'D':
            printf("(%.3f +- %.3f) / (%.3f +- %.3f) = (%.3f +- %.3f)", n->a->corpo, n->a->erro, n->b->corpo, n->b->erro, n->r->corpo, n->r->erro);
            break;
        case 'P':
            printf("(%.3f +- %.3f) ^ %d = (%.3f +- %.3f)", n->a->corpo, n->a->erro, n->p, n->r->corpo, n->r->erro);
            break;
        default:
            printf("Comando desconhecido!");
            break;
    }
}

void imprime(lista* l) {
    printf("==================================================================\n");
    printf("Historico:\n");
    no* ref = l->comeco;
    while(ref != NULL){
        printf("\n");
        imprime_operacao(ref);
        ref = ref->prox;
    }
    printf("\n");
    printf("==================================================================\n");
}

valor* soma(valor* a, valor* b) {
    valor* r = (valor*)malloc(sizeof(valor));
    r->corpo = a->corpo + b->corpo;
    r->erro = a->erro + b->erro;
    return r;
}

valor* subtracao(valor* a, valor* b) {
    valor* r = (valor*)malloc(sizeof(valor));
    r->corpo = a->corpo - b->corpo;
    r->erro = a->erro + b->erro;
    return r;
}

valor* produto(valor* a, valor* b) {
    valor* r = (valor*)malloc(sizeof(valor));
    r->corpo = a->corpo * b->corpo;
    r->erro = a->corpo*b->erro + b->corpo*a->erro;
    return r;
}

valor* produto_constante(valor* a, float c) {
    valor* r = (valor*)malloc(sizeof(valor));
    r->corpo = a->corpo*c;
    r->erro = a->erro*c;
    return r;
}

valor* divisao(valor* a, valor* b) {
    valor* r = (valor*)malloc(sizeof(valor));
    if(b->corpo > 0.000000000001) {
        r->corpo = a->corpo / b->corpo;
        r->erro = (a->corpo * b->erro + b->corpo * a->erro) / (b->corpo * b->corpo);
    }
    else{
        printf("\n\nDivisao por 0 nao da ne rei...\n\n");
    }
    return r;
}

valor* potencia(valor* a, int p) {
    valor* r = (valor*)malloc(sizeof(valor));
    if(p == 0) {
        r->corpo = 1;
        r->erro = 0;
    }
    else {
        r->corpo = a->corpo;
        for(int i = 1; i < p; i++) {
            r->corpo *= a->corpo;
        }
        r->erro = a->erro;
        for(int i = 0; i < p-1; i++) {
            r->erro *= a->corpo;
        }  
    }
    r->erro *= p;
    return r;
}



