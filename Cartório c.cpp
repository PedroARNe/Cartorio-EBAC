#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função para registrar os nomes
{
    setlocale(LC_ALL, "Portuguese"); // Seleção de idioma

    //Início da criação de variáveis/strings
    char arquivo[40];
    char nome[40];
    char sobrenome[40];
    char cpf[40];
    char cargo[40];
    //Final da criação de variáveis/strings

    printf("Digite o CPF para cadastro: "); //Coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo

    FILE *file = fopen(arquivo, "w"); // Abre o arquivo para registrar - O "W" significa escrever
    if (file == NULL)
    {
        printf("Erro ao criar o arquivo!\n");
        return -1; // Retorna erro se o arquivo não puder ser criado
    }

    // Lê os dados do usuário
    printf("Digite o nome para cadastro: ");
    scanf("%s", nome);

    printf("Digite o sobrenome para cadastro: ");
    scanf("%s", sobrenome);

    printf("Digite o cargo do novo usuário: ");
    scanf("%s", cargo);

    // Escreve os dados no arquivo
    fprintf(file, "CPF: %s\n", cpf);
    fprintf(file, "Nome: %s %s\n", nome, sobrenome);
    fprintf(file, "Cargo: %s\n", cargo);

    printf("\n");
    fclose(file); // Fecha o arquivo
    printf("Cadastro realizado com sucesso!\n");

    system("pause");
    return 0; // Retorna sucesso
}

int consulta() //Função para consultar os nomes
{
	setlocale(LC_ALL, "Portuguese"); //Seleção de idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que gostaria de consultar: ");
	scanf("%s", cpf);
	printf("\n");
	
    FILE *file;
    file = fopen(cpf, "r"); //Abre o arquivo para consultar - O "r" significa ler
	
	if(file == NULL)
	{
		printf("O CPF digitado não foi localizado ou não existe! \n\n");
		return -1;
	}
	else 
	{
		printf("Arquivo encontardo! Lendo informações...");
	}
	
	printf("\n");
	printf("\nEssas são as informações do usuário: \n\n");

	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	getchar();
	
	fclose(file);
	printf("\n\n");
	
	getchar();
	
	return 0;
}

int deletar() //Função para deletar os usuários
{
	setlocale(LC_ALL, "Portuguese"); //Seleção de idioma
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	printf("\n");
	
	remove(cpf); //Remove o CPF que for escolhido
	
	FILE *file;
	file = fopen(cpf, "r"); //Abre o arquivo para deletar - O "r" significa ler
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n\n");
	}
	
	system("pause");
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1; //Variável para o loop
	
	for(laco=1;laco=1;) //Loop
    { 
	
	  system("cls"); //Deletar informações anteriores
	  
	  setlocale(LC_ALL, "Portuguese"); //Seleção de idioma
	
	  printf("### Cartório da EBAC ###\n\n"); //Título do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n"); //Opção para registrar novos usuários
	  printf("\t2 - Consultar os nomes\n"); //Opção para consultar usuários existentes
	  printf("\t3 - Deletar nomes\n\n"); //Opção para deletar os usuários
	  printf("Opção: "); //Para o usuário colocar a opção desejada em uma interface mais "organizada"
	
	  scanf("%d", &opcao); //Armazenar na variável "opcao" o valor que o usuário digitar
	
	  system("cls"); //Deletar informações anteriores
	
	  switch(opcao) //Início da seleção do menu
	  {
	  	  case 1:
	  	  	registro(); //Chamada da função Registrar
		  break;
		  
		  case 2:
		  	consulta(); //Chamada da função Consultar
		  break;
		  
		  case 3:
		  	deletar(); //Chamada da função Deletar
		  break;
		  
		  default: //Garantir que não terá erro
		  	printf("Esta opção não existe!\n\n");
		  system("pause");
		  break;
	  }
	
      printf("-Esse software é de Pedro"); //Autor do algoritimo
    }

}
