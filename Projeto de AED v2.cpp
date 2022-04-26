#include <stdio.h> //Declara��es de fun��es �teis para entrada e sa�da de dados 
#include <conio.h> // fun��es para entrada/sa�da do consola
#include <locale.h> // adapta�ao do idioma 
#include <stdlib.h> // define vari�veis e fun��es.
#include <string.h> //define fun��es para manipular matrizes de caracteres.

void cabecalho(){
	system ("cls"); //limpa a tela de sa�da de programa que � executado
	printf("||--------------------------------||\n");
    printf("||         banco do VSKI          ||\n");
	printf("||--------------------------------||\n");
}

typedef struct conta{               
	long int Codigo; //Codigo da conta  
	float Saldo; //Saldo da conta
	char TipoDeConta[]; //Tipo de Conta (prazo ou poupan�a)
}conta;

typedef struct clientes{               
	long Codigo; //Codigo Num�rico do cliente e numero de conta 
	char NomeDeCliente[100];  //Nome do cliente
	char Localidade[100];  //Localidade do cliente   
	float Saldo; //Saldo Global do cliente
	struct conta CON[5]; //Contas pertencentes ao cliente
	struct clientes *proximo;
}clientes;
 

typedef struct Lista{
    clientes *inicio, *fim;
    int tam;
} Lista;


void CriarCliente(Lista *lista){
	
	clientes *novo = (clientes*)malloc(sizeof(clientes)); // cria um novo n�
    
	if(lista->inicio == NULL) { // a lista est� vazia
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    } else { // a lista n�o est� vazia
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    lista->tam++;
    printf("NOme: \n", novo->NomeDeCliente);
	scanf("%s", &novo->NomeDeCliente);
	printf("Insira o saldo: \n", novo->Saldo);
	scanf("%f", &novo->Saldo);
    
	clientes *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL) {
        printf("%.2f \t", inicio->Saldo);
        printf("%s\n", inicio->NomeDeCliente);
        inicio = inicio->proximo;
    }
    printf("\n\n");
	getch();
}





void Imprimir(Lista *lista) { 
	clientes *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL) {
        printf("%.2f \t", inicio->Saldo);
        printf("%s\n", inicio->NomeDeCliente);
        inicio = inicio->proximo;
    }
    printf("\n\n");
    getch();
}


void RemoverCliente(Lista *lista) {
    clientes *inicio = lista->inicio; // ponteiro para o in�cio da lista
    clientes * noARemover = NULL; // ponteiro para o n� a ser removido

float valor;
printf("Saldo a remover: ");
scanf("%f", &valor);
    if(inicio != NULL && lista->inicio->Saldo == valor) { // remover 1� elemento
        
		noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
        if(lista->inicio == NULL)
            lista->fim = NULL;
    } else { // remo��o no meio ou no final
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->Saldo != valor) {
            inicio = inicio->proximo;
        }
        if(inicio != NULL && inicio->proximo != NULL) {
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;
            if(inicio->proximo == NULL) // se o �ltimo elemento for removido
                lista->fim = inicio;
        }
    }
    if(noARemover) {
        free(noARemover); // libera a mem�ria do n�
        lista->tam--; // decrementa o tamanho da lista
    }
}


void ClientesMenu(Lista *lista){
int opcao;	
	
	do{
		cabecalho();
		printf("\n1 - Adicionar novo cliente\n");
		printf("2 - Editar cliente\n");
		printf("3 - Consultar cliente\n");
		printf("4 - Remover cliente\n");
		printf("5 - Listar clientes\n");
		printf("0 - Voltar ao menu\n\n");
		scanf("%d", &opcao);
		
	switch(opcao){
		case 1: 	
			CriarCliente(lista);
		break;
	
		case 2: 
				
		break;
			
		case 3: 
		
		break;
			
		case 4: 
			RemoverCliente(lista);
		break;
			
		case 5: 
			Imprimir(lista);
		break;	
				
		case 0: 
			return;
		break;
			
		default:
			printf("Opcao inv�lida! \n");
			getch();
		}
			
	}while(opcao != 0);

}



int main () {
	int opcao;
	Lista lista;


	setlocale(LC_ALL, "Portuguese");
	
	lista.inicio = NULL;
    lista.fim = NULL;
    lista.tam = 0;
    
	do{ 
		cabecalho();
		printf("\n1 - Gerir conta de clientes do Banco\n"); /* - permita gerir (criar, editar, consultar, remover e listar) as contas dos clientes; */
		printf("2 - Gerir clientes do Banco\n"); /* - permita gerir (criar, editar, consultar, remover e listar) os clientes do banco && - permita registar movimentos nas contas */
		printf("3 - Consulta geral\n"); /* - permita consultar */////////*Criar novo Cliente*/
		printf("0 - Sair\n\n");
		printf("Escolha uma op��o: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: 	
				
			break;
			
			case 2: 
				ClientesMenu(&lista);
			break;
			
			case 3: 
				
			break;
					
			case 0: 
				printf("\nObrigado pela sua visita!\n");
				getch();
			break;
			
			default:
				printf("Opcao inv�lida! \n");
				getch();
		}		
	}while(opcao != 0);
		
return 0;
}

