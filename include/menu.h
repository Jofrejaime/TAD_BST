#ifndef MENU_H
#define MENU_H
#include "bst.h"
void menu_principal();
void menu_insercao(Node **raiz);
void menu_pesquisar(Node *raiz);
void menu_remover(Node **raiz);
int menu_opcoes();
void eh_um_beco_s_saida();
void menu_altura(Node *raiz);
void limpar_buffer();
#endif
