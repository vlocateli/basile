//TODO REVER O VIDEO PARA ACHAR O ERRO


#include<stdlib.h>
#include<stdio.h>
void begin(int rows,int columns);
char * create(int rows,int columns);
double getRandomDoubleInRange(double min, double max);
void display(int rows,int columns,char*simulation);




int main(int argc, char* argv [] )
{	
	int rows = atoi(argv[1]);
	if(rows <= 0 )
	{
		printf("Quantidade de linhas deve ser maior que zero. A quantidade lida foi de %02d\n",rows);
		return -1;
	
	}
	
	
	
	int columns= atoi(argv[2]);
	if(columns<= 0 )
	{
		printf("Quantidade de colunas deve ser maior que zero. A quantidade lida foi de %02d\n",columns);
		return -1;
	
	}

	begin(rows,columns);


}
void display(int rows,int columns, char* simulation){
	printf("\033[H\033\[J"); //limpa tela
	for (int y=0;y<rows;y++){

		for (int x=0;x<columns;x++){
			printf("%c ",*(simulation+y*columns+x));


		}
		printf("\n");
	}


}
void begin(int rows, int columns){
	puts("Inciando programa");
	printf("Linhas = %02d\n",rows);
	printf("Colunas = %02d\n",columns);
	char*simulation=create(rows,columns);
	if(simulation==NULL)
		return;
	display(rows,columns,simulation);
	
 	
	



	}
double getRandomDoubleInRange(double min, double max){

	return ((double)rand()/RAND_MAX)* (max-min)+min;



}


char* create(int rows,int columns){
			char* simulation =(char*) calloc(rows*columns,sizeof(char));
			if(simulation==NULL){
				return NULL;
			}
			for(int y =0; y<rows;y++){
					for(int x=0;x<columns;x++){
						if(getRandomDoubleInRange(0.0,1.0)<= 0.35)
						{
							*(simulation+y*columns+x)="#";
						}
						
						else
						{
							*(simulation+y*columns+x)=".";
						}




					}




			}	
	return simulation;

}
