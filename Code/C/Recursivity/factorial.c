#include <stdio.h>

int factorial (int n);


int main()	{
	unsigned int x,fact;
	printf("Ingrese un valor entero positivo\n");
	scanf("%d",&x);
	fact=factorial(x);
    printf("El factorial de %d es %d\n",x,fact);
    return 0;
}

int factorial(int n){

	if (n<2)
		return 1;
	else 
		return n*factorial(n-1);
}