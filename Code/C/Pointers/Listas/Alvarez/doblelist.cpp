#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct {
	int coci;
	int exp;
} mono;

struct NODE {
	mono number;
	struct NODE *next;
	struct NODE *prev;
};

int  search_value(struct NODE *llist, int num);
void append_node_next(struct NODE *llist, int CO, int EX);
struct NODE *append_node_prev(struct NODE *llist, int CO, int EX);
void display_list(struct NODE *llist);
void delete_node(struct NODE *llist, int num);
void append_node(struct NODE *llist, int CO, int EX);
void concat_list(struct NODE *llist, struct NODE *llist2, struct NODE *llist3);
void sumar(struct NODE *llist, struct NODE *llist2, struct NODE *llist3);

int main(void) {
	bool status = false;
	char deci='S';
	int input = 1;
	int co = 0, ex = 0;
	struct NODE *llist;
	struct NODE *llist2;
	struct NODE *llist3;
	struct NODE *llist4;
	struct NODE *llist5;

	llist = (struct NODE *)malloc(sizeof(struct NODE));
	llist->number.coci = 0;
	llist->number.exp = 0;
	llist->next = NULL;
	llist->prev = NULL;

	llist2 = (struct NODE *)malloc(sizeof(struct NODE));
	llist2->number.coci = 0;
	llist2->number.exp = 0;
	llist2->next = NULL;
	llist2->prev = NULL;

	llist3 = (struct NODE *)malloc(sizeof(struct NODE));
	llist3->number.coci = 0;
	llist3->number.exp = 0;
	llist3->next = NULL;
	llist3->prev = NULL;

	cout << "Lista 1";
	while (deci == 'S' || deci == 's'){
		cout << "\nQuieres ingresar un monomio(S/N) ?\n";
		cin >> deci;
		if (deci == 'S' || deci == 's'){
			cout << "Dame el valor del cociente ?;";
			cin >> co;
			cout << "\n";
			cout << "Dame el valor del exponente ?;";
			cin >> ex;
			cout << "\n";
			append_node(llist, co, ex);
		}
	}

	deci = 'S';
	cout << "\n\nLista 2";
	while (deci == 'S' || deci == 's') {
		cout << "\nQuieres ingresar un monomio(S/N) ?\n";
		cin >> deci;
		if (deci == 'S' || deci == 's') {
			cout << "Dame el valor del cociente ?:";
			cin >> co;
			cout << "\n";
			cout << "Dame el valor del exponente ?:";
			cin >> ex;
			cout << "\n";
			append_node(llist2, co, ex);
		}
	}
	
	while (input != 0) {
		printf("\n-- Menu --\n");
		printf("0) Salir\n");
		printf("1) Concatenar\n");
		printf("2) Sumar\n");
		printf("3) Multiplicar\n");
		scanf("%d", &input);
		switch (input) {
			case 0:
			default:
				printf("Adios...\n");
				input = 0;
				break;
			case 1:
				printf("Elegiste Concatenar\n");
				concat_list(llist, llist2,llist3);
				cout << "\n";
				display_list(llist);
				cout << "\n";
				display_list(llist2);
				cout << "\n";
				display_list(llist3);
				free(llist3);
				break;
			case 2:
				printf("Elegiste Sumar\n");
				sumar(llist, llist2, llist3);
				cout << "\n";
				display_list(llist);
				cout << "\n";
				display_list(llist2);
				cout << "\n";
				display_list(llist3);
				free(llist3);
				break;
			case 3:
				printf("Elegiste Mulriplicar\n");

				break;

		}
	}

	//llist3 = concatenar(llist, llist2);
	sumar(llist, llist2, llist3);
	cout << "\n";
	display_list(llist);
	cout << "\n";
	display_list(llist2);
	cout << "\n";
	display_list(llist3);
	free(llist);
	return(0);
}


void display_list(struct NODE *llist) {
	
	while (llist->prev != NULL) {
		llist = llist->prev;
	}
	while (llist != NULL) {
		cout << llist->number.coci << "x" << llist->number.exp << " ";
		llist = llist->next;
	}
	
}

void append_node_next(struct NODE *llist, int CO, int EX) {
	while (llist->next != NULL)
		llist = llist->next;

	llist->next = (struct NODE *)malloc(sizeof(struct NODE));
	llist->next->number.coci = CO;
	llist->next->number.exp = EX;
	llist->next->next = NULL;
	llist->next->prev = llist;
}

struct NODE *append_node_prev(struct NODE *llist, int CO, int EX) {
	struct NODE *temp;
	temp= (struct NODE *)malloc(sizeof(struct NODE));
	temp->number.coci = CO;
	temp->number.exp = EX;
	llist->prev = temp;
	temp->next = llist;
	temp->prev = NULL;
	return (llist->prev);

}

void append_node(struct NODE *llist, int CO, int EX) {
	if (llist->next == NULL && llist->number.coci == 0 && llist->number.exp == 0 && llist->prev == NULL) {
		llist->number.coci = CO;
		llist->number.exp = EX;

	}
	else if(EX < llist->number.exp  && llist->next == NULL&& llist->prev == NULL){
		append_node_next(llist, CO, EX);
	}
	else if (EX > llist->number.exp  && llist->next == NULL&& llist->prev == NULL) {
		 llist = append_node_prev(llist, CO, EX);
	}
	else {
		while (llist->prev != NULL) {
			llist = llist->prev;
		}
		if(EX > llist->number.exp){
			llist = append_node_prev(llist, CO, EX); 
		}
		else {
			while (llist->next != NULL) {
				if (EX > llist->number.exp) {
					struct NODE *temp;
					temp = (struct NODE *)malloc(sizeof(struct NODE));
					temp->number.coci = CO;
					temp->number.exp = EX;
					temp->next = llist;
					temp->prev = llist->prev;
					llist->prev->next = temp;
					llist->prev = temp;
					break;
				}
				llist = llist->next;
			}
			if (llist->next == NULL) {
				if (EX > llist->number.exp) {
					struct NODE *temp;
					temp = (struct NODE *)malloc(sizeof(struct NODE));
					temp->number.coci = CO;
					temp->number.exp = EX;
					temp->next = llist;
					temp->prev = llist->prev;
					llist->prev->next = temp;
					llist->prev = temp;
					
				}
				else {
					append_node_next(llist, CO, EX);
				}
			}

		}
	}
}

void concat_list(struct NODE *llist, struct NODE *llist2, struct NODE *llist3) {	
	
	while (llist->next != NULL) {
		llist = llist->next;
	}
	while (llist2->prev != NULL) {
		llist2 = llist2->prev;
	}
	
	llist3->number.coci = llist->number.coci;
	llist3->number.exp = llist->number.exp;
	llist3->prev = llist->prev;
	llist3->next = llist2;
	llist3->prev->next->next = llist3->next;
	
}

void sumar(struct NODE *llist, struct NODE *llist2, struct NODE *llist3) {
	int SUM = 0;
 
	while (llist!=NULL && llist2 != NULL){
		if (llist->number.exp == llist2->number.exp) {
			if ((llist->number.coci + llist2->number.coci) != 0) {
				SUM = llist->number.coci + llist2->number.coci;
				append_node(llist3, (SUM), llist->number.exp);
				llist = llist->next;
				llist2 = llist2->next;
			}
			else{
				llist = llist->next;
				llist2 = llist2->next;
			}
		}
		else {
			if (llist->number.exp > llist2->number.exp){
				append_node(llist3, llist->number.coci, llist->number.exp);
				llist = llist->next;
			}
			else{
				append_node(llist3, llist2->number.coci, llist2->number.exp);
				llist2 = llist2->next;
			}
		}
	}
	while (llist!=NULL){
		append_node(llist3, llist->number.coci, llist->number.exp);
		llist = llist->next;
	}
	while (llist2 != NULL) {
		append_node(llist3, llist2->number.coci, llist2->number.exp);
		llist2 = llist2->next;
	}

}