#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TorreDeHanoi(int n, char x, char y, char aux);

int main(){
	int n;
	scanf("%d",&n);
	TorreDeHanoi(n,'A','C','B');
	return 0;
}

void TorreDeHanoi(int n, char x, char y, char aux)
{
	if(n==1){ 
		printf("Disco 1 do pino %c para o pino %c\n", x, y);
		return;
	}
	TorreDeHanoi(n-1, x, aux, y);
	printf("Disco %d do pino %c para o pino %c\n",n, x, y);
	TorreDeHanoi(n-1, aux, y, x);
}