#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SERV 2
#define NUM_VIAG 2

struct viagem{
	char destino[20], ida[10], retorno[10];
	int custo, id;
	bool aprov;
};

struct servidor{
	char nome[20], cpf[11];
	viagem viagens[NUM_VIAG];
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
		if(tamanho!=11){
			printf("\nCPF inválido. É necessário 11 digitos. Retornando ao menu principal.\n");
			cadastrar='n';
			break;
		}

		for(int i=0; i<NUM_SERV; i++){
			comparacao=strcmp(servidores[i].cpf,cpfE);
			if (comparacao==0){ //cpf já existente
				printf("Servidor já cadastrado. Retornando...\n");
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

void novoPedido(servidor *servidores){
	char cpfE[11], destinoE[20], idaE[10], retornoE[10];
	int tamanho, custoE, id;
	bool aprovE;

	system("clear");
	printf("*---------------------------*\n");
   	printf("|   Novo pedido de viagem   |\n");
   	printf("*---------------------------*\n");

	printf("\nDigite o CPF do servidor:");
	scanf("%s", cpfE);

	tamanho=strlen(cpfE);
	if(tamanho!=11){
		printf("\nCPF inválido. É necessário 11 digitos. Retornando ao menu principal.\n");
	}

	else {
		for(int i=0; i<NUM_SERV; i++){ //percorre o vetor de servidores
			for (int j=0; j<NUM_VIAG; j++){ // percorre o vetor de viagens em cada servidor
				if (strcmp(servidores[i].cpf, cpfE)){ // registra as entradas quando encontra um indice de viagem vazio
				printf("\nServidor %s", *servidores[i].nome);
				printf("\nInsira os dados da viagem: ");
				
				printf("\nDestino: ");
				scanf("%s", destinoE);
				strcpy(servidores[i].viagens[j].destino, destinoE);
				
				printf("\nData de ida: ");
				scanf("%s", idaE);
				strcpy(servidores[i].viagens[j].ida, idaE);
				
				printf("\nData de retorno: ");
				scanf("%s", retornoE);
				strcpy(servidores[i].viagens[j].retorno, retornoE);
				
				printf("\nEstimativa de custo total (sem centavos): ");
				scanf("%d", &custoE);
				servidores[i].viagens[j].custo=custoE;
				
				servidores[i].viagens[j].aprov=false;
				servidores[i].viagens[j].id=j+1;

				printf("\nServidor: %s", servidores[i].nome);
				printf("\nCPF: %s", servidores[i].cpf);
				printf("\nDestino: %s", servidores[i].viagens[j].destino);
				printf("\nData de ida: %s", servidores[i].viagens[j].ida);
				printf("\nData de volta: %s", servidores[i].viagens[j].retorno);
				printf("\nOrçamento: %d", servidores[i].viagens[j].custo);
				printf("\nId da viagem: %d", servidores[i].viagens[j].id);

				break;
				}
			}
		}
			
		
	}


}
// }

void menu(){
	int opcao;
	servidor servidores[NUM_SERV]={};	

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
		if(opcao == 2) novoPedido(servidores);
		
		
	}
}


int main(){
	
	menu();
}