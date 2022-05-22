//Agenda de clientes

// incluindo bibliotecas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tam 6 //definindo o tamanho do vetor

//declarando a struct (registro)

struct contatos
{
	char nome[50], telefone[14], endereco[100];	
};


int main ()
{

//declaranda vari�veis

	int escolha, contador, i;//contador � a posi��o no vetor; i � o contador para o la�o do case 2
	struct contatos lista[tam];//a agenda permite o cadastro de 5 pessoas por meio de um vetor de 6 posi��es, n-1 utiliz�veis(?).

	setlocale (LC_ALL, "Portuguese");
	contador = 1;
	
	do
	{

//processamento na agenda	

//Recebendo a escolha do usu�rio:
		printf ("\n");
		printf ("Senhor usu�rio, escolha 1 pra cadastrar um nome na agenda!\n");
		printf ("Senhor usu�rio, escolha 2 pra listar os dados inseridos na agenda!\n");
		printf ("Senhor usu�rio, escolha 0 pra encerrar a agenda!\n");
		scanf ("%d", &escolha);
		fflush (stdin);//serve para limpar o buffer do teclado
//definindo o funcionamento do programa a partir da escolha do usu�rio
		switch (escolha)
		{
			case 1:
				printf ("Cadastro de novo contato\n");
					if (contador>5)
					{
						printf ("A agenda est� lotada!\n");
					}
					else
					{
						printf ("Cadastro n�: %d\n", contador);//c�digo gerado a partir do contador
//dados que ser�o solicitados ao usu�rio: nome, telefone e endere�o				
						printf ("Digite o Nome a ser cdastrado na agenda:\n ");
						fgets (lista[contador].nome, 50, stdin);//fgets (string, tamanho, stdin) - lembrando que o scanf n�o l� espa�os; o gets n�o limita o tamanho. 
						fflush (stdin);
						
						printf ("Digite o Telefone da pessoa cadastrada:\n ");
						fgets (lista[contador].telefone, 14, stdin);
						fflush (stdin);
						
						printf ("Digite o Endere�o da pessoa cadastrada: \n ");
						fgets (lista[contador].endereco, 100, stdin);
						fflush (stdin);
						
						printf("\n");
						
						contador++;
					}
			break;
			case 2:
				printf ("Lista de contatos cadastrados\n");
					if (contador == 1)
					{
						printf ("A agenda est� vazia!\n");
					}
					else
					{
						for (i=1; i<contador; i++)
							{
							printf("Cadastro n�: %d\n", i);
							printf("Nome: %s", lista[i].nome);
							printf("Telefone: %s", lista[i].telefone);
							printf("Endere�o: %s\n", lista[i].endereco);
							}	
					}
			break;
			case 0:
				printf ("Agenda encerrada!\n");
			break;
			default:
				printf ("Op��o inv�lida!\n");
		}		
	}
	while (escolha != 0);
	return(0);
}

