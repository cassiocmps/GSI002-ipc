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
	char cadastrar='s', valido='n', nomeE[20], cpfE[11];
	int tamanho, comparacao;
			
	// system("clear");
	printf("*---------------------------*\n");
    printf("|  Cadastrar novo servidor  |\n");
    printf("*---------------------------*\n");

	printf("CPF (somente números): ");
	scanf("%s", cpfE);
	
	tamanho=strlen(cpfE);
	if(tamanho!=11){
		printf("\nCPF inválido. É necessário 11 digitos. Retornando ao menu principal.\n");
		cadastrar='n';
	}

	for(int i=0; i<NUM_SERV; i++){
		comparacao=strcmp(servidores[i].cpf,cpfE);
		if (comparacao==0){ //cpf já existente
			printf("Servidor já cadastrado. Retornando...\n");
			cadastrar='n';
			break;
		}
		else if (strlen(servidores[i].cpf)==0){ // encontrando o indice vazio
			printf("\nNome: ");
			scanf("%s", servidores[i].nome);
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
}

void novoPedido(servidor *servidores){
	char cpfE[11], destinoE[20], idaE[10], retornoE[10];
	int tamanho, custoE, id;
	bool aprovE;

	// system("clear");
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
				if ((strcmp(servidores[i].cpf, cpfE))==0){ // registra as entradas quando encontra um indice de viagem vazio
				printf("\nServidor %s", servidores[i].nome);
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

				return;
				}
			}
		}
			
		
	}


}

void aprovarPedido(struct servidor *servidores){
	char cpfE[11], resposta;
	int idE;
	
	printf("\nDigite o CPF do servidor: ");
	scanf("%s",cpfE);

	for (int i=0; i<NUM_SERV; i++){
		if((strcmp(servidores[i].cpf, cpfE))==0){
			printf("\nDigite o id da viagem: ");
			scanf("%d", &idE);
			for (int j=0; j<NUM_VIAG; j++){				
				if ((servidores[i].viagens[j].id)==idE){
					printf("\nDestino: %s", servidores[i].viagens[j].destino);
					printf("\nData de ida: %s", servidores[i].viagens[j].ida);
					printf("\nData de volta: %s", servidores[i].viagens[j].retorno);
					printf("\nOrçamento: %d", servidores[i].viagens[j].custo);
					if (servidores[i].viagens[j].aprov==true) {
						printf("\nSituação: Aprovado\nRetornando...");
						return;
					}
					if (servidores[i].viagens[j].aprov==false) {
						printf("\nSituação: Negado\nAprovar? (s/n)");
						fflush(stdin);
						fflush(stdout);
						scanf(" %c", &resposta);
						if (resposta=='s'){
							servidores[i].viagens[j].aprov=true;
							printf("\nAprovado com sucesso! Retornando...");
							return;
						}
						if (resposta=='n'){
							printf("\nRetornando...");
							return;
						}
					}					
				}
				else if(j==NUM_VIAG-1){
					printf("\nId de viagem inválido. Retornando...");
					return;
				}
			}

		}
		else if (i==NUM_SERV-1){
			printf("\nServidor não encontrado. Retornando...");
			return;
		}
	}

}


void listarServ(struct servidor *servidores){
	char vazio[5]={};
	for (int i = 0; i < NUM_SERV; i++){
		if (strcmp(servidores[i].nome, vazio)==0){return;}
		printf("\n\nNome: %s",servidores[i].nome);
		printf("\nCPF: %s", servidores[i].cpf);
	}
	
}

void listarViagens(struct servidor *servidores){
	char vazio[5]={};

	for (int i = 0; i < NUM_SERV; i++){
		if (strcmp(servidores[i].nome, vazio)==0){return;}
		printf("\n\nNome: %s",servidores[i].nome);
		printf("\nCPF: %s", servidores[i].cpf);
		printf("\nViagens:");
		for(int j=0; j<NUM_VIAG; j++){
			if (servidores[i].viagens[j].id==0){break;}
			printf("\nId: %d", servidores[i].viagens[j].id);
			printf("\n	Destino: %s", servidores[i].viagens[j].destino);
			printf("\n	Data de ida: %s", servidores[i].viagens[j].ida);
			printf("\n	Data de volta: %s", servidores[i].viagens[j].retorno);
			printf("\n	Orçamento: %d", servidores[i].viagens[j].custo);
			printf("\n	Aprovado: %d", servidores[i].viagens[j].aprov);
		}
	}	
}


void listarTudo(struct servidor *servidores){
	char vazio[5]={};

	for (int i = 0; i < NUM_SERV; i++){
		if (strcmp(servidores[i].nome, vazio)==0){return;}
		printf("\n\nNome: %s",servidores[i].nome);
		printf("\nCPF: %s", servidores[i].cpf);
		printf("\nViagens:");
		for(int j=0; j<NUM_VIAG; j++){
			if (servidores[i].viagens[j].id==0){break;}
			printf("\nId: %d", servidores[i].viagens[j].id);
			printf("\n	Destino: %s", servidores[i].viagens[j].destino);
			printf("\n	Data de ida: %s", servidores[i].viagens[j].ida);
			printf("\n	Data de volta: %s", servidores[i].viagens[j].retorno);
			printf("\n	Orçamento: %d", servidores[i].viagens[j].custo);
			printf("\n	Aprovado: %d", servidores[i].viagens[j].aprov);
		}
	}	
}

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
		printf("\n7- Listar tudo");
		printf("\n8- Sair ");
		listarTudo(servidores);
		printf("\n\nDigite opção: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) cadServidor(servidores);
		if(opcao == 2) novoPedido(servidores);
		if(opcao == 3) aprovarPedido(servidores);
		if(opcao == 5) listarServ(servidores);
		if(opcao == 7) listarTudo(servidores);

		if(opcao == 8) return;	
		
	}
}


int main(){
	
	menu();
}