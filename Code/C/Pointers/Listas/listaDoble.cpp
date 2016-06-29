
#include <stdio.h>
#include <stdlib.h>

/*

PROGRAMA ELABORADO POR JOEL TREJO EL 13 de Noviembre de 2009

*/

typedef struct nodo {
	int info;
	struct nodo *next;
	struct nodo *ant;
} lista;

lista *head = NULL;
lista *last=NULL;
/****************************************************************************/

lista *crear(int valor){
     lista *p;
     p=(lista *) malloc(sizeof(lista));
     p->info=valor;
     p->next=NULL;
     p->ant=NULL;
     return p;
}

/****************************************************************************/
/***Lo voy insertando en la posicion que le corresponda, pero ahora la lista es doblemente ligada***/
void inserta_normal(lista *i){  
     lista *p;
     p=head;
     while (p!=NULL)
       {
         if (p->info <= i->info)
          {
            p=p->next;
          }
          else   // i se inserta entre p->ant y p
          {
              if (!p->ant)  // Es decir i sería el primer elemento
              {
                 head=i;
                 p->ant=i;
                 i->next=p;           
                 i->ant=NULL;
              }
              else
              {
                  i->ant=p->ant;
                  p->ant->next=i;
                  i->next=p;
                  p->ant=i;                                                      
              }   
              return;
          }  
       }    
       if (head==NULL)  // Esto quiere decir que i se insertará al final de una lista vacía
         {
           head=i;
           last=i;
           i->next=NULL;         
         }
       else // quiere decir que i se insertará al final de una lista no vacía
         {
           i->ant=last;
           last->next=i;
           last=i;
           i->next=NULL;
         }
     
}

/****************************************************************************/
/***Borra un elemento de la lista***/

int borra(int valor)
{
    int retorno=-1;
    lista *p;
    p=head;
    while (p!=NULL)
    {
       if (p->info!=valor)
        {
           p=p->next;           
        }    
        else  // se encontro el valor y es P
        {
              // Tengo que checar si es el primero
              if (!p->ant) // Es decir p es el primer valor
              {
                 if (!p->next)  // Este caso es cuando P es el unico valor en la lista
                 {
                   free(p);
                   head=NULL;
                   last=NULL;
                 }          
                 else  // P es el primer elemento y despues de dicho elemento hay algo mas
                 {
                   head=p->next;
                   p->next->ant=NULL;                 
                   free(p);
                 }     

                 return 0;                          
              }
              else // El que borro está entre dos nodos
              {
                 if (!p->next)  // Debo verificar que no sea el ultimo elemento
                 {
                   p->ant->next=NULL;
                   last=p->ant;             
                   free(p);
                 }                    
                 else
                 {
                   p->ant->next=p->next;
                   p->next->ant=p->ant;         
				   //free(p);
                 }        
                 return 0;
              }
        }
    }
  return -1; // NO EXISTE EL ELEMENTO       
}

/****************************************************************************/
/***IMPRIME LOS ELEMENTOS EN ORDEN INVERSO***/
void invertir()
{
     lista *p;
     p=last;
     if (!p)
     {
            printf("\nLISTA VACIA\n");
            return;
     }
     while (p!=NULL){
         printf("%d ->",p->info);
         p=p->ant;
     }     
}

///**LES QUEDA COMO ASIGNACION CORREGIR EL ERROR, DE PORQUE CUANDO IRMPRIMO LA LISTA INVERTIDA, SE QUEDA AL FINAL**///

void showlist()
{
  lista *p;
  p=head;
  if (!p)
   {
     printf("\nLISTA VACIA\n");
     return;
   }
   while (p!=NULL)
   {
      if (p->next)   
         printf("%d ->",p->info);
      else
        printf("%d ",p->info);
       p=p->next;         
   }
}

/****************************************************************************/
int main() {
	lista *p;
	int inf, opcion = 1;
	int resultado;

	while(opcion) {
		printf("\nIntroduzca info ");
		scanf("%d", &inf);
		printf("\nIntroduzca Opcion (1) Insertar. (2) Eliminar. (3) Invertir. (0) Salir.");
		scanf("%d", &opcion);
		switch (opcion) {
			case 0:
				break;
			case 1:
				p = crear(inf);
				inserta_normal(p);
				break;
			case 2:
				resultado = borra(inf);
				if (resultado == -1)
					printf("\nElemento NO encontrado");
				break;
			case 3:
				p = head;
				invertir();
				p->next = NULL;
				break;
			default:
				printf("\nOpci¢n no v lida");
		}
		showlist();
	} /* while ... */
	return 0;
}
