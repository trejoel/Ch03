#include <iostream>
#include <new>
using namespace std;

int cuantos(int *p);
int *positivos(int *p);



int main ()
{
  int i,n;
  int * p;
  cout << "Cuantos valores?\n";
  cin >> n;
  p= new (nothrow) int[n]; //Porque se usa la función nothrow?
  if (p == NULL)
    cout << "Error: No se puede asignar memoria";
  else
  {
    for (i=0; i<n; i++)
    {
      cout << "valor: ";
      cin >> p[i];
    }
  int *pos=positivos(p);  
  int cont=cuantos(pos);
  for (i=0; i<cont; i++)
    {
      cout << "Valor: "<<pos[i]<<"\n";      
    }
    delete[] p;
  }
  return 0;
}

int cuantos(int *p){
  int cont=0;

  *p=p[0];
  while (*p != NULL){
    cont++;     
    p++;   
  }
  return cont;
}

int *positivos(int *p)
{ 
   int *positivos;
   int cuant=0;
   int n=cuantos(p);
   for (int i=0; i<n; i++)
   {
      if (p[i]>0){
         cuant++; 
      }
   }
   positivos = new (nothrow) int[cuant];
   if (p==NULL){
     cout << "Error: No se puede asignar memoria";
     return p;        
   }   
   cuant=0;
   for (int i=0; i<n; i++)
   {
      if (p[i]>0){
         positivos[cuant]=p[i];         
         cuant++;
      }
   }
   return positivos;   
}