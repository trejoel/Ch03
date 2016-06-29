#include <iostream>
#include <new>
using namespace std;

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
    cout << "El orden de los valores que introdujiste es: ";
    for (i=0; i<n; i++)
      cout << p[i] << ", ";
    delete[] p;
  }
  return 0;
}