#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o para registrar os nomes
{
    setlocale(LC_ALL, "Portuguese"); // Sele��o de idioma

    //In�cio da cria��o de vari�veis/strings
    char arquivo[40];
    char nome[40];
    char sobrenome[40];
    char cpf[40];
    char cargo[40];
    //Final da cria��o de vari�veis/strings

    printf("Digite o CPF para cadastro: "); //Coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo

    FILE *file = fopen(arquivo, "w"); // Abre o arquivo para registrar - O "W" significa escrever
    if (file == NULL)
    {
        printf("Erro ao criar o arquivo!\n");
        return -1; // Retorna erro se o arquivo n�o puder ser criado
    }

    // L� os dados do usu�rio
    printf("Digite o nome para cadastro: ");
    scanf("%s", nome);

    printf("Digite o sobrenome para cadastro: ");
    scanf("%s", sobrenome);

    printf("Digite o cargo do novo usu�rio: ");
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

int consulta() //Fun��o para consultar os nomes
{
	setlocale(LC_ALL, "Portuguese"); //Sele��o de idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que gostaria de consultar: ");
	scanf("%s", cpf);
	printf("\n");
	
    FILE *file;
    file = fopen(cpf, "r"); //Abre o arquivo para consultar - O "r" significa ler
	
	if(file == NULL)
	{
		printf("O CPF digitado n�o foi localizado ou n�o existe! \n\n");
		return -1;
	}
	else 
	{
		printf("Arquivo encontardo! Lendo informa��es...");
	}
	
	printf("\n");
	printf("\nEssas s�o as informa��es do usu�rio: \n\n");

	
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

int deletar() //Fun��o para deletar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //Sele��o de idioma
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	printf("\n");
	
	remove(cpf); //Remove o CPF que for escolhido
	
	FILE *file;
	file = fopen(cpf, "r"); //Abre o arquivo para deletar - O "r" significa ler
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n\n");
	}
	
	system("pause");
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //Vari�vel para o loop
	
	for(laco=1;laco=1;) //Loop
    { 
	
	  system("cls"); //Deletar informa��es anteriores
	  
	  setlocale(LC_ALL, "Portuguese"); //Sele��o de idioma
	
	  printf("### Cart�rio da EBAC ###\n\n"); //T�tulo do menu
	  printf("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n"); //Op��o para registrar novos usu�rios
	  printf("\t2 - Consultar os nomes\n"); //Op��o para consultar usu�rios existentes
	  printf("\t3 - Deletar nomes\n\n"); //Op��o para deletar os usu�rios
	  printf("Op��o: "); //Para o usu�rio colocar a op��o desejada em uma interface mais "organizada"
	
	  scanf("%d", &opcao); //Armazenar na vari�vel "opcao" o valor que o usu�rio digitar
	
	  system("cls"); //Deletar informa��es anteriores
	
	  switch(opcao) //In�cio da sele��o do menu
	  {
	  	  case 1:
	  	  	registro(); //Chamada da fun��o Registrar
		  break;
		  
		  case 2:
		  	consulta(); //Chamada da fun��o Consultar
		  break;
		  
		  case 3:
		  	deletar(); //Chamada da fun��o Deletar
		  break;
		  
		  default: //Garantir que n�o ter� erro
		  	printf("Esta op��o n�o existe!\n\n");
		  system("pause");
		  break;
	  }
	
      printf("-Esse software � de Pedro"); //Autor do algoritimo
    }

}
