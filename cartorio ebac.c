#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca d aloca��o de espa�o em mem�ria
#include <locale.h> //bilbioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema

{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da cria��o de vari�veis/string
	printf("Digite o CPF a ser cadastrado: "); //coletabdi informa��o do usu�ruio
	scanf("%s", cpf); //%s = string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //%a = atualizar
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //pausa a tela
	
	
	
	
	
	
	
}

int consulta() //fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir o arquivo pra leitura
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //fun��o respons�vel por deletar os usu�rios no sistema
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir o arquivo pra leitura
	
	
	if(file == NULL) //se o file est� null
	{
		printf("N�o foi poss�vel deletar pois o CPF n�o foi encontrado!\n");
		system("pause");
	}
	
	else
	{
		fclose(file); //fecha o arquivo, pois ele existe
		remove(cpf); // agora voc� pode remover o arquivo
		printf("Usu�rio deletado com sucesso!  \n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
        system("cls");  
		  	
	    setlocale(LC_ALL, "Portuguese"); //setando o idioma
	
	    printf("###Cart�rio da EBAC###\n\n"); //trazer textos para o usu�ruio
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Op��o: "); //fim do menu
	
	    scanf("%d", &opcao); //armazenar vari�vel
	
	    system("cls"); //limpar tela
	    
	    switch(opcao) //inicio da sele��o
	    {
	    	case 1:
	        registro(); //chamada de fun��es
		    
		    
		    case 2: 
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
		    return 0;
		    break;
		    
		    default:
		    printf("Essa op��o n�o est� dispon�vel\n"); 
	    	system("pause");
	    	break; //fim da sele��o
		    	
		}
	    
	
   }  

	
}
