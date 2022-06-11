/* Complete o programa abaixo para que leia uma frase
de at� 80 caracteres e, a seguir, imprima:
a. Quantos caracteres foram digitados.
b. Quantos espa�os brancos existem na frase.
c. Quantos desses caracteres s�o min�sculos e quantos s�o mai�sculos.
d. Quantos desses caracteres s�o d�gitos.
e. Quantos desses caracteres s�o de pontua��o.*/


#define TAMANHO 80

void main()
{
	char frase[TAMANHO], letra;
	int i=0, tamanho=0, branco=0, maiusc=0, minusc=0, digitos=0, pontuacao=0;
	
	printf("Qual a frase? ");
	while((letra = getchar()) != '\n' && i < TAMANHO)
	{
		frase[i] = letra;
		i++;
	}
	
	for(i=0; i<TAMANHO && frase[i] != '\0'; i++)
	{
		tamanho++;
		if(isspace(frase[i]))
			branco++;
			
		if(islower(frase[i]))
			minusc++;
			
		if(isupper(frase[i]))
			maiusc++;
		
		if(isdigit(frase[i]))
			digitos++;
			
		if(ispunct(frase[i]))
			pontuacao++;
	}
	
	printf(" A frase contem %d caractres\n", tamanho);
	printf("O numero de espacos em branco eh de: %d\n", branco);
	printf("O numero de caracteres minusculos eh de: %d\n", minusc);
	printf("O numero de caracteres maiusculos eh de: %d\n", maiusc);
	printf("O numero de digitos eh de: %d\n", digitos);
	printf("O numero de caracteres especiais eh de: %d\n", pontuacao);
}
