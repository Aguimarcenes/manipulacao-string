/*Faça um programa que leia uma frase de até 80 caracteres, e duas
letras quaisquer do usuário. A seguir, troque na frase todas as ocorrências da primeira letra
fornecida pela segunda e imprima a nova frase.*/

#define TAMANHO 80

void main()
{
	char frase[TAMANHO], trocar, por;
	int i;
	
	do{
		printf("Qual a frase? ");
		gets(frase);
	}while (frase[0] == '\0');
	
	printf("Trocar...");
	_flushall();
	scanf("%c", &trocar);
	
	printf("Por...");
	_flushall();
	scanf("%c", &por);
	
	for(i=0; i<TAMANHO && frase[i] != '\0'; i++)
	{
		if(frase[i] == trocar)
			frase[i] = por;	
	}	
	
	printf("A nova frase eh: %s\n", frase);
}
