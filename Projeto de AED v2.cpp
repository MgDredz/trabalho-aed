ASDFGHJKL�



SDSADF



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

typedef struct clientes CLI; //Cria STRUCT para armazenar dados de um evento e define o nome, capacidade de deixar a palavra "struct" ao declarar vari�veis desse tipo
struct clientes{               
	long Codigo; //Codigo Num�rico do cliente e numero de conta 
	char NomeDeCliente[100];  //Nome do cliente
	char Localidade[100];  //Localidade do cliente   
	float Saldo; //Saldo Global do cliente
	char Contas [5];
};

typedef struct conta CON;
struct conta{               
	long int Codigo; //Codigo da conta  
	float Saldo; //Saldo da conta
	char TipoDeConta; //Tipo de Conta
};


void CriarCliente(){

CLI tte;

cabecalho();

printf("Introduza uma variavel: ");
scanf("%d", &tte.Codigo);

fflush(stdin);
printf("Introduza o nome do cliente: ");
gets(tte.NomeDeCliente);

getch();

}

void ClientesMenu(){
int opcao;	
	
	do{
		cabecalho();
		printf("\n1 -  Adicionar novo cliente\n");
		printf("2 - Editar cliente\n");
		printf("3 - Consultar cliente\n");
		printf("4 - Remover cliente\n");
		printf("5 - Listar clientes\n");
		printf("0 - Voltar ao menu\n\n");
		scanf("%d", &opcao);
		
	switch(opcao){
		case 1: 	
			CriarCliente();
		break;
	
		case 2: 
				
		break;
			
		case 3: 
		
		break;
			
		case 4: 
			
		break;
			
		case 5: 
				
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
	
	setlocale(LC_ALL, "Portuguese");
	
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
				ClientesMenu();
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

