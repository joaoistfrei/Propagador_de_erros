#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "propagadorerro.h"

int main() {
    int flag = 1;
    lista *l = criar_lista();
    while(flag){
        int foi = 0;
        printf("-----PROPAGADOR DE ERROS-----\n");
        printf("Escolha a opcao desejada:\n");
        printf("A - adicao;\n");
        printf("S - subtracao;\n");
        printf("M - multiplicacao\n");
        printf("C - multiplicacao por constante\n");
        printf("D - divisao;\n");
        printf("P - potencia;\n");
        printf("H - consultar historico;\n");
        printf("OBS: insira os numeros em modulo e da forma 'valor +- incerteza'!\n\n");
        char opc;
        opc = getch();
        valor *r = (valor*)calloc(1, sizeof(valor));
        valor *a = (valor*)calloc(1, sizeof(valor));
        valor *b = (valor*)calloc(1, sizeof(valor));
        float c;
        int p;
        switch (opc)
        {
        case 'A':
            printf("\nOPCAO: soma");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Segundo valor: ");
            scanf("%f +- %f", &b->corpo, &b->erro);
            r = soma(a, b);
            insere(l, opc, a, b, r, p, c);
            break;
        case 'a':
            printf("\nOPCAO: soma");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Segundo valor: ");
            scanf("%f +- %f", &b->corpo, &b->erro);
            r = soma(a, b);
            insere(l, 'A', a, b, r, p, c);
            break;
        case 'S':
            printf("\nOPCAO: subtracao");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Segundo valor: ");
            scanf("%f +- %f", &b->corpo, &b->erro);
            r = subtracao(a, b);
            insere(l, opc, a, b, r, p, c);
            break;
        case 's':
            printf("\nOPCAO: subtracao");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Segundo valor: ");
            scanf("%f +- %f", &b->corpo, &b->erro);
            r = subtracao(a, b);
            insere(l, 'S', a, b, r, p, c);
            break;
        case 'M':
            printf("\nOPCAO: multiplicacao");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Segundo valor: ");
            scanf("%f +- %f", &b->corpo, &b->erro);
            r = produto(a, b);
            insere(l, opc, a, b, r, p, c);
            break;
        case 'm':
            printf("\nOPCAO: multiplicacao");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Segundoo valor: ");
            scanf("%f +- %f", &b->corpo, &b->erro);
            r = produto(a, b);
            insere(l, 'M', a, b, r, p, c);
            break;
        case 'C':
            printf("\nOPCAO: multiplicacao por constante");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Constante: ");
            scanf("%f", &c);
            r = produto_constante(a, c);
            insere(l, opc, a, b, r, p, c);
            break;
        case 'c':
            printf("\nOPCAO: multiplicacao por constante");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Constante: ");
            scanf("%f", &c);
            r = produto_constante(a, c);
            insere(l, 'C', a, b, r, p, c);
            break;
        case 'D':
            printf("\nOPCAO: divisao");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Segundo valor: ");
            scanf("%f +- %f", &b->corpo, &b->erro);
            r = divisao(a, b);
            insere(l, opc, a, b, r, p, c);
            break;
        case 'd':
            printf("\nOPCAO: divisao");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Segundo valor: ");
            scanf("%f +- %f", &b->corpo, &b->erro);
            r = divisao(a, b);
            insere(l, 'D', a, b, r, p, c);
            break;
        case 'P':
            printf("\nOPCAO: potencia");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Potencia: ");
            scanf("%d", &p);
            r = potencia(a, p);
            insere(l, opc, a, b, r, p, c);
            break;
        case 'p':
            printf("\nOPCAO: potencia");
            printf("\nPrimeiro valor: ");
            scanf("%f +- %f", &a->corpo, &a->erro);
            printf("Potencia: ");
            scanf("%d", &p);
            r = potencia(a, p);
            insere(l, 'P', a, b, r, p, c);
            break;
        case 'H':
            imprime(l);
            foi = 1;
            break;
        case 'h':
            imprime(l);
            foi = 1;
            break;
        default:
            printf("Essa opcao nao existe!");
            foi = 1;
            break;
        }
        if(foi == 0)
        printf("\nO resultado e: %.5f +- %.5f", r->corpo, r->erro);
        printf("\n\n");
        printf("Deseja continuar calculando?\n");
        printf("'s' ou 'n'\n\n");
        char sair = 'q';
        while(sair != 's') {
            sair = getch();
            if(sair == 'n')
            return 0;
        }
        fflush(stdin);
    }


    return 0;
}