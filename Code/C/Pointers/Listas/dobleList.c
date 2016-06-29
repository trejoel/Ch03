#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int number;
	struct NODE *next;
	struct NODE *prev;
};


int  search_value(struct NODE *llist, int num);
void append_node_next(struct NODE *llist, int num);
void append_node_prev(struct NODE *llist, int num);
void display_list(struct NODE *llist);
void delete_node(struct NODE *llist, int num);



int main(void) {
	int num = 0;
	int input = 1;
	int retval = 0;
	struct NODE *llist;
	
	
	llist = (struct NODE *)malloc(sizeof(struct NODE));
	llist->number = 0;
	llist->next = NULL;
	llist->prev=NULL;
	
	while(input != 0) {
		printf("\n-- Menu Selection --\n");
		printf("0) Quit\n");
		printf("1) Insert at END\n");
		printf("2) Delete\n");
		printf("3) Search\n");
		printf("4) Display\n");
		printf("5) Insert FIRST\n");
		scanf("%d", &input);
		
		switch(input) {
			case 0: 
			default:
				printf("Goodbye ...\n");
				input = 0;
				break;
			case 1:
				printf("Your choice: `Insertion END'\n");
				printf("Enter the value which should be inserted: ");
				scanf("%d", &num);
				append_node_next(llist, num);
				break;
			case 2:
				printf("Your choice: `Deletion'\n");
				printf("Enter the value which should be deleted: ");
				scanf("%d", &num);
				delete_node(llist, num);
				break;
			case 3:
				printf("Your choice: `Search'\n");
				printf("Enter the value you want to find: ");
				scanf("%d", &num);
				if((retval = search_value(llist, num)) == -1)
					printf("Value `%d' not found\n", num);
				else
					printf("Value `%d' located at position `%d'\n", num, retval);
				break;
			case 4:
				printf("You choice: `Display'\n");
				display_list(llist);
				break;
			case 5:
				printf("Your choice: `Insertion FIRST'\n");
				printf("Enter the value which should be inserted: ");
				scanf("%d", &num);
				append_node_prev(llist, num);
				llist=llist->prev;
				printf("Primer elemento:%d\n",llist->number);
				break;		
		} /* switch */
	} /* while */
	
	free(llist);
	return(0);
}


void display_list(struct NODE *llist) {
	while(llist->next != NULL) {
		printf("%d ", llist->number);
		llist = llist->next;
	}
	
	printf("%d", llist->number);
}

void append_node_next(struct NODE *llist, int num) {
	while(llist->next != NULL)
		llist = llist->next;
	
	llist->next = (struct NODE *)malloc(sizeof(struct NODE));
	llist->next->number = num;
	llist->next->next = NULL;
	llist->next->prev = llist;
}

void append_node_prev(struct NODE *llist, int num){
	llist->prev = (struct NODE *)malloc(sizeof(struct NODE));
	llist->prev->number = num;
	llist->prev->next = llist;
		
	//printf("Primer elemento:%d\n",llist->number);
	//printf("Segundo elemento:%d\n",llist->next->number);
}

void delete_node(struct NODE *llist, int num) {
	struct NODE *temp;
	temp = (struct NODE *)malloc(sizeof(struct NODE));
	
	if(llist->number == num) {
		/* remove the node */
		temp = llist->next;
		free(llist);
		llist = temp;
		llist->prev=NULL;
	} else {
		while(llist->next->number != num)
			llist = llist->next;
		
		temp = llist->next->next;
		temp->prev=llist;
		free(llist->next);
		llist->next = temp;
	}   
}

int search_value(struct NODE *llist, int num) {
	int retval = -1;
	int i = 1;
	
	while(llist->next != NULL) {
		if(llist->next->number == num)
			return i;
		else
			i++;
		
		llist = llist->next;
	}
	
	return retval;
}
