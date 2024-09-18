#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca que cuida das string

int registrar()
	{
		//Início da criação de variáveis
		char arquivo[40];
		char cpf[40];
		char nome [40];
		char sobrenome [40];
		char cargo [40];
		//Final da criação de variáveis		
		
		printf("Digite o CPF a ser cadastrado: "); 
		scanf("%s",cpf); //Salva o valor na variável
		
		strcpy(arquivo,cpf); //Responsável por copiar os valores das string
		
		FILE *file; //Cria o arquivo
		file = fopen(arquivo,"w"); //Cria o arquivo
		fprintf(file,cpf); //Salva o valor da variável no arquivo
		fclose(file); //Fecha o arquivo
		
		file = fopen(arquivo,"a"); //Abre o arquivo para atualizar
		fprintf(file,","); //Salva o valor no arquivo
		fclose(file); //Fecha o arquivo
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome); //Salva o valor na variável
		
		file = fopen(arquivo,"a"); //Abre o arquivo para atualizar
		fprintf(file,nome); //Salva o valor da variável no arquivo
		fclose(file); //Fecha o arquivo
		
		file = fopen(arquivo,"a"); //Abre o arquivo para atualizar
		fprintf(file,","); //Salva o valor no arquivo
		fclose(file); //Fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome); //Salva o valor na variável
		
		file = fopen(arquivo,"a"); //Abre o arquivo para atualizar
		fprintf(file,sobrenome); //Salva o valor da variável no arquivo
		fclose(file); //Fecha o arquivo
		
		file = fopen(arquivo,"a"); //Abre o arquivo para atualizar
		fprintf(file,","); //Salva o valor no arquivo
		fclose(file); //Fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo); //Salva o valor na variável
		
		file = fopen(arquivo,"a"); //Abre o arquivo para atualizar
		fprintf(file,cargo); //Salva o valor da variável no arquivo
		fclose(file); //Fecha o arquivo
		
		system("pause"); //Pausa o sistema 
	}

int consultar()
	{
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		//Início da criação de variáveis
		char cpf[40];
		char conteudo[200];
		//Final da criação de variáveis	
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf); //Salva o valor na variável
		
		FILE *file;
		file = fopen(cpf,"r"); //Lê o arquivo
		
		if(file == NULL)
		{
			printf("Esse CPF não foi localizado!\n");
		}
		
		while(fgets(conteudo,200,file) != NULL)
		{
			printf("\nEssas são as informeções do usuário consultado: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		fclose(file); //Fecha o arquivo
		system("pause");
	}

int deletar()
	{
		setlocale(LC_ALL, "Portuguese"); 
		
		char cpf[40];
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("\nCPF não encontrado no sistema!\n");
			system("pause");
		}
		
		else if(file != NULL)
		{
			fclose(file); //Fecha o arquivo
			remove(cpf);
			printf("\nCPF deletado com sucesso!\n");
		}
		
		system("pause");
		
	}

int main ()
	{	
	int opcao=0; //Definindo variáveis
	int x=1;

	for(x=1;x=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("O que você deseja fazer?\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//Fim do menu

		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registrar();
			break;
	
			case 2:
			consultar();
			break;
	
			case 3:
			deletar();
			break;
	
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
	
			default:
			printf("Opção inválida\n");
			system("pause");
			break;
		
		}
	
	}
	
	}
