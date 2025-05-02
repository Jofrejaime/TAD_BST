
#include <stdio.h>
#include <stdlib.h>
#include "../include/bst.h"
typedef struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
} Node;

Node* novo_no(int valor) {
    Node* no = (Node*)malloc(sizeof(Node));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

Node* inserir_no(Node* raiz, int valor) {
    if (raiz == NULL) return novo_no(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserir_no(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir_no(raiz->direita, valor);
    return raiz;
}

Node* pesquisar(Node* raiz, int chave) {
    if (raiz == NULL || raiz->valor == chave) return raiz;
    if (chave < raiz->valor)
        return pesquisar(raiz->esquerda, chave);
    return pesquisar(raiz->direita, chave);
}

Node* valor_minimo(Node* no) {
    while (no && no->esquerda != NULL)
        no = no->esquerda;
    return no;
}

Node* remover_no(Node* raiz, int chave) {
    if (raiz == NULL) return raiz;
    if (chave < raiz->valor)
        raiz->esquerda = remover_no(raiz->esquerda, chave);
    else if (chave > raiz->valor)
        raiz->direita = remover_no(raiz->direita, chave);
    else {
        if (raiz->esquerda == NULL) {
            Node* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            Node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        Node* temp = valor_minimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover_no(raiz->direita, temp->valor);
    }
    return raiz;
}

void imprimir_em_order(Node* raiz) {
    if (raiz != NULL) {
        imprimir_em_order(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_em_order(raiz->direita);
    }
}

int altura_da_arvore(Node* raiz) {
    if (raiz == NULL) return -1;
    int altE = altura_da_arvore(raiz->esquerda);
    int altD = altura_da_arvore(raiz->direita);
    return (altE > altD ? altE : altD) + 1;
}

int beco_s_saida(Node* no) {
    if (no == NULL) return 0;
    return (no->esquerda != NULL || no->direita != NULL) ? 0 : 1;
}
