#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

	int var1, var2, var3;
	
	printf("Esta parte do c�digo foi executada serialmente ...\n");
	
	#pragma omp parallel private(var1, var2) shared(var3) 
	{
		printf("Esta parte do c�digo esta paralelizada ...\n");	
	
	}
	printf("Esta parte do c�digo foi executada serialmente ...\n");
	
	return 0;
}

