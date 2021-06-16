#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SERV 2

struct viagem{
	char destino[20], ida[10], retorno[10];
	int custo, id;
	bool aprov;
};

struct servidor{
	char nome[20], cpf[11];
	viagem viagens[2];
};

void cadServidor(servidor *servidores){
	char cadastrar='s', valido='n', nomeE[20]={}, cpfE[11]={};
	int tamanho, comparacao;
			
	while(cadastrar=='s'){
		system("clear");
		printf("*---------------------------*\n");
    	printf("|  Cadastrar novo servidor  |\n");
    	printf("*---------------------------*\n");

		printf("Nome: ");
		scanf("%s", nomeE);

		// while(valido=='n'){
		printf("CPF (somente números): ");
		scanf("%s", cpfE);
		
		tamanho=strlen(cpfE);
		if(tamanho<11){
			printf("\nCPF inválido. É necessário 11 digitos. Retornando ao menu principal.\n");
			cadastrar='n';
		}

		for(int i=0; i<NUM_SERV; i++){
			comparacao=strcmp(servidores[i].cpf,cpfE);
			if (comparacao==0){ //cpf já existente
				printf("Servidor já cadastrado. ");
				cadastrar='n';
				break;
			}
			else if (strlen(servidores[i].cpf)==0){ // encontrando o indice vazio
				strcpy(servidores[i].nome, nomeE);
				strcpy(servidores[i].cpf, cpfE);
				printf("\nServidor %s cadastrado com sucesso! (posição %d)\n", servidores[i].nome, i);
				cadastrar='n';
				break;
			}
			else if(i==NUM_SERV-1){ // sem espaço vazio fecha o cadastro
				printf("\nNúmero máximo de servidores atingido.\n");
				cadastrar='n';
				break;
			}
		}
		// }
	cadastrar='n';
		// printf("\nCadastrar outro? (s/n) ");
		// scanf("%s", &cadastrar);
	}

}

// void novoPedido(servidor *servidores){
// 	int cpfE;

// 	system("clear");
// 	printf("*---------------------------*\n");
//    	printf("|  Cadastrar novo servidor  |\n");
//    	printf("*---------------------------*\n");

// 	printf("\nDigite o CPF do servidor:");
// 	scanf("%d", cpfE);

// 	for(int i=0; i<NUM_SERV; i++){
// 		if (servidores[i].cpf==cpfE){
// 			printf("\nInsira os dados da viagem: ");
// 			printf("\nDestino: ");
// 			scanf("%s",servidores[i].viagens.destino);
// 			printf("\nData de ida: ");
// 			scanf("%s",servidores[i].viagens.ida);
// 			printf("\nData de retorno: ");
// 			scanf("%s",servidores[i].viagens.retorno);
// 			printf("\nEstimativa de custo total: ");
// 			scanf("%d",servidores[i].viagens.custo);
// 			printf("\n");
// 			scanf("%s",);
// 			break;
// 		}
// 		else if (servidores[i].cpf==0){
// 			strcpy(servidores[i].nome, nomeE);
// 			servidores[i].cpf = *cpfE;
// 			printf("Servidor %s cadastrado com sucesso! (posição %d)\n", servidores[i].nome, i);
// 			valido='s';
// 			break;
// 		}
// 		else if(i==NUM_SERV){
// 			printf("\nNúmero máximo de servidores atingido.\n");
// 			break;
// 		}
// 	}



// }

void menu(){
	int opcao;
	servidor servidores[NUM_SERV]={};	
			char a[3]={'a', 'b', 'c'};
		int x = strcmp (a,servidores[0].cpf);

		printf("%d", x);

	while(1){
		printf("\nBem vindo ao Sistema de registro e controle de aprovação de pedido de viagem dos servidores da UFU.\n");
		printf("\n1- Cadastrar novo servidor");
		printf("\n2- Novo pedido");
		printf("\n3- Aprovar pedido");
		printf("\n4- Revogar pedido");
		printf("\n5- Listar servidores");
		printf("\n6- Listar pedidos de um servidor");
		printf("\n7- Listar pedidos de um mês");
		printf("\n8- Sair ");
		printf("\n\nDigite opção: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) cadServidor(servidores);
		// if(opcao == 2) novoPedido(servidores);
		
		
	}
}


int main(){
	
	menu();
}