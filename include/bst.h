#ifndef BST_H
#define BST_H
typedef struct Node Node;
Node* novo_no(int valor);
Node* inserir_no(Node* raiz, int valor);
Node* pesquisar(Node* raiz, int chave);
Node* valor_minimo(Node* no);
Node* remover_no(Node* raiz, int chave);
void imprimir_em_order(Node* raiz);
int altura_da_arvore(Node* raiz);
int beco_s_saida(Node* no);
#endif
