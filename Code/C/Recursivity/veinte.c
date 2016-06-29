#include <stdio.h>

int veintePreguntas(int k, int lim_inf, int lim_sup, int cont);

int main(){
    int numero_intentos;
    numero_intentos=veintePreguntas(81,0,99,1);
    printf("Encontro el valor en %d intentos\n",numero_intentos);
	return 0;
}

int veintePreguntas(int k, int lim_inf, int lim_sup, int cont){

   if (k>lim_sup)
   {
   	printf("El valor de %d fuera de rango\n", k);
   }   
   int guess= (lim_inf+lim_sup)/2;
   printf("guess: %d\n:: cont: %d", guess,cont);
   if (guess==k)
   {
      return cont;
   }
   else if (k>guess) {
   	  lim_inf=guess+1;
   	  cont++;
      veintePreguntas(k,lim_inf,lim_sup, cont);
   }
     else{
     	lim_sup=guess-1;
     	cont++;
     	veintePreguntas(k,lim_inf,lim_sup, cont);
     }
}