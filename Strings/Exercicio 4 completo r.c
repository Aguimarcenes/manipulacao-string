/*Fa�a um editor de texto usando uma matriz de 25 linhas e 70 colunas que forne�a as
seguintes fun��es:
a. O texto do usu�rio deve ser lido at� que uma linha em branco seja digitada.
b. O usu�rio pode reimprimir seu texto digitando i.
c. O usu�rio pode trocar duas linhas de lugar digitando t onde o editor pergunta
os n�meros das linhas a serem trocadas entre si.
d. O usu�rio pode redigitar uma linha digitando r, onde o editor pergunta o
n�mero da linha a ser redigitada.
e. O usu�rio pode sair do editor digitando s.
f. Se o usu�rio digitar um comando que n�o se encaixe em nenhum caso acima,
o editor avisa que o comando n�o existe.*/

#define LINHAS 25
#define COLUNAS 70

void main()
{
	char texto[LINHAS][COLUNAS], alt, operador;
	int i, j, linhas=0, linha1=0, linha2=0, redigita;
	
	printf("#> Digite o texto: \n\n");
	for(i=0; i<LINHAS; i++)
	{
		printf("%d : ", i+1); 
		for(j=0; j<COLUNAS; j++) 
		{
			scanf("%c", &texto[i][j]);
			if(texto[i][j] == '\n') 
			{
				texto[i][j] = '\0'; 
				break; 
			}
		}
		if(texto[i][0] == '\0') 
			break; 
		linhas++; 
	}
	
	do{
		do{
			printf(" \n\n\n -         Painel do Texto          - \n");
			printf(" | Mostrar texto digitado (tecla i) | \n");
			printf(" | Trocar duas linhas (tecla t)     | \n");
			printf(" | Redigitar uma linha (tecla r)    | \n");
			printf(" | Sair do programa (tecla s)       | \n");
			printf("\t\nDigite o Comando desejado: \n");
			_flushall();
			scanf("%c", &operador);
		
			if(operador != 'i' && operador !='t' && operador != 'r' && operador !='s')
				printf("\tValor invalido. Digite novamente!\n");
		}while(operador != 'i' && operador !='t' && operador != 'r' && operador !='s');
		
		switch (operador)
			{
			case 'i':
				printf("----------------------\n");
				printf("O texto digitado foi:\n");
				printf("----------------------\n\n");
				for(i=0; i<linhas; i++)
				{
					for(j=0; texto[i][j] != '\0'; j++)
						printf("%c", texto[i][j]);
				
					printf("\n");
				}
			break;
				 
			case 't':
				printf("----------------------\n");
				printf("Qual a primeira linha deseja trocar?\n");
				scanf("%d", &linha1);
				printf("Qual a segunda linha deseja trocar?\n");
				scanf("%d", &linha2);
				printf("----------------------\n\n");
				if(linha1-1 || linha2-1 > linhas-1)
				{
					printf("----------------------\n");
					printf("Voce digitou uma linha invalida!\n");
					printf("----------------------\n\n");
				}
				else
				{
					for(j=0; j<COLUNAS; j++)
					{
						alt = texto[linha1-1][j];
	 					texto[linha1-1][j] = texto[linha2-1][j];
	 					texto[linha2-1][j] = alt;
	 				}
				}
			break;
			
			case 'r':
				do{
					printf("----------------------\n");
					printf(" \nQual a linha deseja redigitar?\n");
					scanf("%d", &redigita);
					printf("----------------------\n\n");
					if(redigita <=0 || redigita > linhas)
						printf("Voce digitou uma linha invalida!\n");
				}while(redigita <=0 || redigita > linhas);
				
				printf("%d : ", redigita);
				_flushall();
				for(j=0; j<COLUNAS; j++) 
				{	
					scanf("%c", &texto[redigita-1][j]);
					if(texto[redigita-1][j] == '\n') 
					{
						texto[redigita-1][j] = '\0'; 
						break; 
					}
				}
			break;
					
			default:
				printf("----------------------\n");
				printf("Voce encerrou o programa!\n");
				printf("----------------------\n\n");	
		}
	}while(operador != 's');
}
