#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca d alocação de espaço em memória
#include <locale.h> //bilbioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema

{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da criação de variáveis/string
	printf("Digite o CPF a ser cadastrado: "); //coletabdi informação do usuáruio
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

int consulta() //função responsável por consultar os usuários no sistema
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
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //função responsável por deletar os usuários no sistema
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir o arquivo pra leitura
	
	
	if(file == NULL) //se o file está null
	{
		printf("Não foi possível deletar pois o CPF não foi encontrado!\n");
		system("pause");
	}
	
	else
	{
		fclose(file); //fecha o arquivo, pois ele existe
		remove(cpf); // agora você pode remover o arquivo
		printf("Usuário deletado com sucesso!  \n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
        system("cls");  
		  	
	    setlocale(LC_ALL, "Portuguese"); //setando o idioma
	
	    printf("###Cartório da EBAC###\n\n"); //trazer textos para o usuáruio
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opção: "); //fim do menu
	
	    scanf("%d", &opcao); //armazenar variável
	
	    system("cls"); //limpar tela
	    
	    switch(opcao) //inicio da seleção
	    {
	    	case 1:
	        registro(); //chamada de funções
		    
		    
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
		    printf("Essa opção não está disponível\n"); 
	    	system("pause");
	    	break; //fim da seleção
		    	
		}
	    
	
   }  

	
}
