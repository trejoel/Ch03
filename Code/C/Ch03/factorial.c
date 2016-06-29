#include <stdio.h>

void factorial(int x);

int main(){
   
   factorial(5);
}

void factorial(int x){
   int i,prod=1;
   for (i=x;i>=1;i--)
   {
      prod=prod*i;
   }

   printf("El valor del factorial de %d es= %d",x,prod);
}