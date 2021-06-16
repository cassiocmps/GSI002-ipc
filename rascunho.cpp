struct viagem{
	char destino[20], ida[10], retorno[10];
	int custo, id;
	bool aprov;
};

struct servidor{
	char nome[20], cpf[11];
	viagem viagens[NUM_VIAG];
};
