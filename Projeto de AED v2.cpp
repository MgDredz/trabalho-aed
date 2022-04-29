#include <stdio.h> //Declara��es de fun��es �teis para entrada e sa�da de dados 
#include <conio.h> // fun��es para entrada/sa�da do consola
#include <locale.h> // adapta�ao do idioma 
#include <stdlib.h> // define vari�veis e fun��es.
#include <string.h> //define fun��es para manipular matrizes de caracteres.
#include <ctime>

void cabecalho(){
	system ("cls"); //limpa a tela de sa�da de programa que � executado
	printf("||--------------------------------||\n");
    printf("||         UMinho Bank          ||\n");
	printf("||--------------------------------||\n");
}

typedef struct conta{               
	long int Codigo; //Codigo da conta  
	float Saldo; //Saldo da conta
	char TipoDeConta[]; //Tipo de Conta (prazo ou poupan�a)
}conta;

typedef struct clientes{               
	long int Codigo; //Codigo Num�rico do cliente e numero de conta 
	char NomeDeCliente[100];  //Nome do cliente
	char Localidade[100];  //Localidade do cliente   
	float SaldoGlobal; //Saldo Global do cliente
	struct conta CON[5]; //Contas pertencentes ao cliente
	int nmrContas=0;
	struct clientes *proximo;
}clientes;
 

typedef struct Lista{
    clientes *inicio, *fim;
    int tam;
} Lista;

long int totalClientes=1;
int totalContas=1;




/*CriarConta(Lista *lista){
	
	
	float valor;
	printf("Saldo a remover: ");
	scanf("%f", &valor);
    if(inicio != NULL && lista->inicio->SaldoGlobal == valor) { // remover 1� elemento
        
		noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
        if(lista->inicio == NULL)
            lista->fim = NULL;
    } else { // remo��o no meio ou no final
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->SaldoGlobal != valor) {
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

*/

void CriarCliente(Lista *lista){
	system("cls");
	cabecalho();
//	printf("||--------------------------------||\n");
    printf("||         CRIAR CLIENTE          ||\n");
	printf("||--------------------------------||\n");
	
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
    printf("Insira o nome: \n", novo->NomeDeCliente);
	scanf("%s", &novo->NomeDeCliente);
	printf("Insira a morada: \n", novo->Localidade);
	scanf("%s", &novo->Localidade);
	novo->SaldoGlobal=0;
    novo->Codigo=totalClientes;
}


void Imprimir(Lista *lista) { 
	
	cabecalho();
	
	clientes *inicio = lista->inicio;
    printf("N�mero de clientes: %d\n\n", lista->tam);
    while(inicio != NULL) {
        printf("Nome: %s\t", inicio->NomeDeCliente);
		printf("Cliente %.6ld\n", inicio->Codigo);
		printf("Saldo Global: %.2f \n", inicio->SaldoGlobal);
    	printf("Morada: %s\n", inicio->Localidade);
    	printf("Numero de contas abertas: %d\n", inicio->nmrContas);
        inicio = inicio->proximo;
    }
    printf("\n\n");
    getch();
    printf("Prima qualquer but�o para continuar...");
}


void RemoverCliente(Lista *lista) {
    
	cabecalho();
	
	clientes *inicio = lista->inicio; // ponteiro para o in�cio da lista
    clientes * noARemover = NULL; // ponteiro para o n� a ser removido

	long int valor;
	printf("C�digo num�rico do cliente a remover: ");
	scanf("%ld", &valor);
    if(inicio != NULL && lista->inicio->Codigo == valor) { // remover 1� elemento
        
		noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
        if(lista->inicio == NULL)
            lista->fim = NULL;
    } else { // remo��o no meio ou no final
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->Codigo != valor) {
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

void ContasMenu(Lista *lista){
int opcao;	
	
	do{
		cabecalho();
		printf("\n1 - Adicionar nova conta\n");
	/*	printf("2 - Editar cliente\n");
		printf("3 - Consultar cliente\n");
		printf("4 - Remover cliente\n");
		printf("5 - Listar clientes\n");
		printf("0 - Voltar ao menu\n\n");*/
		scanf("%d", &opcao);
		
	switch(opcao){
		case 1: 	
		//	CriarConta(lista);
		break;
	
	/*	case 2: 
				
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
		break;*/
			
		default:
			printf("Opcao inv�lida! \n");
			getch();
		}
			
	}while(opcao != 0);

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
		printf("Escolha uma op��o: ");
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
		printf("\n1 - Gerir clientes\n"); /* - permita gerir (criar, editar, consultar, remover e listar) as contas dos clientes; */
		printf("2 - Gerir contas\n"); /* - permita gerir (criar, editar, consultar, remover e listar) os clientes do banco && - permita registar movimentos nas contas */
		printf("3 - Consulta geral\n"); /* - permita consultar */////////*Criar novo Cliente*/
		printf("0 - Sair\n\n");
		printf("Escolha uma op��o: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: 	
				ClientesMenu(&lista);
			break;
			
			case 2: 
				ContasMenu(&lista);
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

