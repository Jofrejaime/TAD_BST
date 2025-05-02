#include <stdio.h>
#include "./include/menu.h"

void menu_principal()
{
 Node* raiz = NULL;
    int opcao;

    do 
	{
		opcao = menu_opcoes(); 
		switch(opcao) 
		{
            case 1:
                menu_insercao(&raiz);
                break;
            case 2:
              	menu_remover(&raiz);
                break;
            case 3:
				menu_pesquisar(raiz);	
				break;
            case 4:
            	
                printf("\nArvore em ordem: ");
                imprimir_em_order(raiz);
                printf("\n");
                               
                break;
            case 5:
                printf("A altura da arvore: %d\n", altura_da_arvore(raiz));
                
                break;
            case 6:
            	eh_um_beco_s_saida(raiz);
                break;
            case 0:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 0);
}

int menu_opcoes()
{
	int opcao;

	printf("\n--- MENU BST ---\n");
    printf("1. Inserir\n");
    printf("2. Remover\n");
	printf("3. Pesquisar\n");
    printf("4. Imprimir em ordem\n");
    printf("5. Altura da Arvore\n");
    printf("6. Verificar beco sem saida\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

void menu_insercao(Node **raiz)
{
	int valor;
	system("cls");
	printf("____MENU DE INSERSAO DIGITE (-3) PARA PARAR___\n");
	do{
	printf("Valor: ");
    scanf("%d", &valor);
    if(valor == -3)
    return;
    if(pesquisar(*raiz, valor) == NULL){
    *raiz = inserir_no(*raiz, valor);
    printf("\nVALOR (%d) INSERIDO NA BST!\n", valor);
	}
	else
	printf("\nO NO JA EXISTE NA BST!\nINSIRA UM VALOR DIFERENTE\n");
	}while(valor != -3);

}

void menu_remover(Node **raiz)
{
	int valor;
	system("cls");
	printf("Digite o valor a remover: ");
    scanf("%d", &valor);
    if(valor == -3)
    return;
    *raiz = remover_no(*raiz, valor);
    if(*raiz == NULL)
    	printf("\nELEMENTO INEXISTENTE NA BST!\n");
    else
    	printf("\nNO REMOVIDO DA BST!\n");

}
void menu_pesquisar(Node *raiz)
{
	int valor;
	system("cls");
	printf("\n____MENU DE PESQUISA DIGITE (-3) PARA PARAR___");
	do
	{
	
        printf("\nDigite o valor a pesquisar: ");
        scanf("%d", &valor);
        if(valor == -3)
        return;
        if (pesquisar(raiz, valor))
        	printf("--Valor encontrado.\n");
        else
            printf("--Valor nao encontrado.\n");
	
	}while(valor != -3);
}

void eh_um_beco_s_saida(Node *raiz){
	int valor;
	printf("\n___VERIFICANDO BECOS SEM SAIDA DIGITE (-3) PARA SAIR___");
	do{
	
		printf("\nDigite o valor do no para verificar beco: ");
        scanf("%d", &valor);
        if(valor == -3)
		return;
        Node* no = pesquisar(raiz, valor);
        if (no == NULL)
            printf("No nao encontrado na Arvore.\n");
        else if (beco_s_saida(no))
            printf("Beco sem seida!\n");
        else
        printf("Este no ainda pode ter filhos.\n");
                	
	}while(valor != -3);
}
