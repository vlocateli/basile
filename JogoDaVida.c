#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double getRandomDoubleInRange (double min, double max)
{
	return ((double)rand()/RAND_MAX)* (max-min)+min;
}


void preenche2d (char **v, int r, int c, int chance)
{
	srand(time(NULL));
	
	int i, j, margem = 2;
	float ch = (float)chance/100;
  
  	for (i = 0; i < r+margem; i++)
  	{	
    	for (j = 0; j < c+margem; j++) 
    		
    		if ((i == 0) || (j == 0))

    			v[i][j] = '.';
    		
    		else if ((i == r+margem/2) || (j == c+margem/2))
    		
    			v[i][j] = '.';
			
      		else if (getRandomDoubleInRange(0.0,1.0) <= ch)
	  
	  			v[i][j] = '#';
	  
	  		else
	  
        		v[i][j] = '.';
  	}
  	
}


char **malloc2d (int r, int c)
{
	int i;
	char **t = malloc(r * sizeof(char *));
  
	for (i = 0; i < r; i++)
  
		t[i] = malloc (c * sizeof(char));
        
	return t;
}


void imprime2d (char **v, int r, int c)
{
	int i, j;
  
	for (i = 1; i < r+1; i++)
	{
		for (j = 1; j < c+1; j++)
    
    		printf("%c ", v[i][j]);
      
    printf("\n");
  	}
  
 	printf("\n\n");
}


char **begin (int rows, int columns)
{
	int margem = 2;
	
	char **simulation = malloc2d(rows+margem,columns+margem);
		
	return simulation;
}

char **step (char **v, int r, int c)
{
	int i, j, k, l, count;
	int margem = 2;
	char **novo_jogo = begin(r, c);
	preenche2d (novo_jogo, r, c, 0);
	
	for (i = 0+margem/2; i < r+margem/2; i++)
	{
		for (j = 0+margem/2; j < c+margem/2; j++)
		{	
			count = 0;
			
			for (k = -1; k < 2; k++)
			{
				for (l = -1; l < 2; l++)
				{
					if (v[i+k][j+l] == '#')
					{
						if ((k != 0) || (l != 0))
						
							count++;
					}
				}
			}
			
			if (v[i][j] == '.' && count == 3)
			
				novo_jogo[i][j] = '#';
			
			
			else if (v[i][j] == '#')
			{
				if (count <= 1 || count >= 4)
					
					novo_jogo[i][j] = '.';
			
			else
			
				novo_jogo[i][j] = v[i][j];
				
			}
			
		}
		
	}
	
	free(v);
	return novo_jogo;
}


int main()
{
	int linhas, colunas, chance, timer, selecao;
	
	printf("Insira a quantidade de linhas desejada: ");
	scanf("%d", &linhas);
	
	printf("Insira a quantidade de colunas desejada: ");
	scanf("%d", &colunas);
	
	printf("Insira, em porcentagem, a probabilidade de uma celula inicializar viva: ");
	scanf("%d", &chance);
	
	char **jogo = begin (linhas, colunas);
	preenche2d(jogo, linhas, colunas, chance);
	
	printf("Jogo criado:\n");
	imprime2d(jogo, linhas, colunas);
	
	printf("Digite '1' para rodar um unico passo, ou digite '2' para rodar indefinidamente.\n");
	scanf("%d", &selecao);
	
	printf("Passo seguinte:\n");
	
	while (selecao == 1)
	{
		jogo = step(jogo, linhas, colunas);
		imprime2d(jogo, linhas, colunas);
		
		printf("Digite '1' para rodar um unico passo, ou digite '2' para rodar indefinidamente.\n");
		scanf("%d", &selecao);
		
		printf("Passo seguinte:\n");
	}
	
	while (selecao == 2)
	{
		timer = 0;
		jogo = step(jogo, linhas, colunas);
		
		imprime2d (jogo, linhas, colunas);
		
		while (timer <= 400000000)
			timer++;
			
		printf("Passo seguinte:\n");
	}
	
  	return 0;
}


