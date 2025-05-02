#include <stdio.h>
#include "../include/menu.h"

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
                menu_altura(raiz);
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
	int input_valido;
	
	system("cls");
	printf("\n____MENU DE INSERSAO | DIGITE UM CARACTER PARA PARAR___\n");
	do{
	printf("Valor: ");
    input_valido = scanf("%d", &valor);
	if(input_valido != 1)
	{
		printf("\nFINALIZADO!\n");
		limpar_buffer();
		return;
	}
    if(pesquisar(*raiz, valor) == NULL){
    *raiz = inserir_no(*raiz, valor);
    printf("\nVALOR (%d) INSERIDO NA BST!\n", valor);
	}
	else
	printf("\nO NO JA EXISTE NA BST!\nINSIRA UM VALOR DIFERENTE\n");
	}while(1);

}

void menu_remover(Node **raiz)
{
	int valor;
	int input_valido;
	
	system("cls");
	printf("\nDIGITE UM CARACTER PARA SAIR.");
	printf("\nDigite o valor a remover: ");
    input_valido = scanf("%d", &valor);
	if(input_valido != 1)
	{
		printf("\nFINALIZADO!\n");
		limpar_buffer();
		return;
	}
    *raiz = remover_no(*raiz, valor);
    if(*raiz == NULL)
    	printf("\nELEMENTO INEXISTENTE NA BST!\n");
    else
    	printf("\nNO REMOVIDO DA BST!\n");

}
void menu_pesquisar(Node *raiz)
{
	int valor;
	int input_valido;
	
	system("cls");
	printf("\n____MENU DE PESQUISA | DIGITE UM CARACTER PARA SAIR___");
	do
	{
	
        printf("\nDigite o valor a pesquisar: ");
        input_valido = scanf("%d", &valor);
		if(input_valido != 1)
		{
			printf("\nFINALIZADO!\n");
			limpar_buffer();
			return;
		}
        if (pesquisar(raiz, valor))
        	printf("--Valor encontrado.\n");
        else
            printf("--Valor nao encontrado.\n");
	
	}while(1);
}

void eh_um_beco_s_saida(Node *raiz){
	int valor;
	int input_valido;
	
	printf("\n___VERIFICANDO BECOS SEM SAIDA | DIGITE UM CARACTER PARA SAIR___");
	do{
		printf("\nDigite o valor do no para verificar beco: ");
        input_valido = scanf("%d", &valor);
		if(input_valido != 1)
		{
			printf("\nFINALIZADO!\n");
			limpar_buffer();
			return;
		}
        Node* no = pesquisar(raiz, valor);
        if (no == NULL)
            printf("No nao encontrado na Arvore.\n");
        else if (beco_s_saida(no))
            printf("Beco sem seida!\n");
        else
        printf("Este no nao eh um beco sem saida, possui filhos.\n");
                	
	}while(1);
}
void menu_altura(Node *raiz)
{
	Node *no;
	int valor;
	int input_valido;
	
	system("cls");
	printf("\n__MENU ALTURA | DIGITE UM CARACTER PARA SAIR__\n");
	do{
		printf("\nDigite o valor do no: ");
		input_valido = scanf("%d", &valor);
		if(input_valido != 1)
		{
			printf("\nFINALIZADO!\n");
			limpar_buffer();
			return;
		}
		no = pesquisar(raiz, valor);
		printf("\nA altura da arvore: %d\n", altura_da_arvore(no));
	}while(1);
}

void limpar_buffer()
{
	int ch;
    
	while ((ch = getchar()) != '\n' && ch != EOF);
}
