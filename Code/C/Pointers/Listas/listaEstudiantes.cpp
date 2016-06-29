
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int info;
	struct nodo *next;
} lista;

lista *head = NULL;
/****************************************************************************/
void insert_normal(lista *i) {
	lista *pred, *p;

	p = head;
	pred = NULL;
	while (p != NULL)
	if (p->info <= i->info) {
		pred = p; 
		p = p->next;
	} 
	else {
		if (pred) { /* pred != NULL */
			pred->next = i;
            i->next = p;
			return;
		}
		//i  es el primer elemento   i=1   lista= 1,2,3,4,5 por ejemplo
		head = i;
		i->next = p;
		return;
	} /* else ... */
	if (pred)
		pred->next = i;
	else  // Es el primer elemento
		head = i;
	i->next = NULL;
	return;
} /* insert_normal */

/****************************************************************************/
void invertir(lista *p) {
	if (p->next == NULL)
		head = p;
	else {
		invertir(p->next);
		p->next->next = p;
	}
} /* invertir */
/****************************************************************************/
void showlist(lista *p) {
	printf("\nLISTA\n");
	while (p != NULL) {
		printf(" %d ", p->info);
		p = p->next;
	}
	printf("\n");
} 
/****************************************************************************/
int main() {
	lista *p;
	int inf, opcion = 1;
	int resultado;

	while(opcion) {
		printf("\nIntroduzca info ");
		scanf("%d", &inf);
		printf("\nIntroduzca Opcion (1) Insertar. (2) Eliminar. (3) Invertir. (0) Salir ");
		scanf("%d", &opcion);
		switch (opcion) {
			case 0:
				break;
			case 1:
				p = (lista *) malloc(sizeof(lista));
                p->info = inf;
				insert_normal(p);
				break;
			case 3:
				p = head;
				invertir(p);
				p->next = NULL;
				break;
			default:
				printf("\nOpci¢n no v lida");
		}
		showlist(head);
	} /* while ... */
	return 0;
}
