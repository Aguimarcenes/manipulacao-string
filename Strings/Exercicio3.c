/*Defina uma matriz de caracteres para guardar um texto de no
máximo 100 linhas de 80 caracteres cada para fazer um editor de texto que leia as várias
linhas dadas pelo usuário e quando este digitar uma linha em branco, reescreva o texto do
usuário e imprima as seguintes estatísticas do texto: número de caracteres digitados, número
de espaços em branco e número de linhas.*/


#define LINHAS 100
#define COLUNAS 80

void main()
{
	char texto[LINHAS][COLUNAS];
	int i=0, j=0, caracteres=0, brancos=0, linhas=0;
	
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
			
			caracteres++;
			if(isspace(texto[i][j]))
				brancos++;
		}
		
		if(texto[i][0] == '\0')
			break;
		linhas++;
	}
	
	printf("  \nO texto digitado foi: \n");
	printf("========================= \n\n");
	
	for(i=0; i<linhas ; i++)
	{
		for(j=0; texto[i][j] != '\0'; j++)
			printf("%c", texto[i][j]);
		printf("\n");
	}
	
	printf("\n\n\n");
	printf("O Texto digitado tem %d caracteres em %d linhas!\n", caracteres, linhas);
	printf("Dos caracteres digitados, %d caracteres sao espacos em branco! \n", brancos);
}
