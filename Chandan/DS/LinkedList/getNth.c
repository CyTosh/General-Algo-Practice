#include <stdio.h>
#include <stdlib.h>

#define MEM_ERR 	printf("%s\n", "Memory Error...!!")
#define GET_NODE 	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node))
#define ENDL 		printf("\n")

struct Node {
	int data;
	struct Node *next;
};

void print(struct Node *head){
	while(head){
		printf("%d", head->data);
		head = head->next;
		if(head)
			printf(" --> ");
	}
	ENDL;
}

void insertAtHead(struct Node **head_ref, int data){
	GET_NODE;
	if(!newNode){
		MEM_ERR;
		return;
	}
	newNode->data = data;
	newNode->next = *head_ref;
	*head_ref = newNode;
}

void getNth(struct Node *head, int pos){
	while(pos-- >= 1 && head)
		head = head->next;
	if(!head){
		printf("No Such Position Exit...!!!\n");
		return;
	}

	printf("%d", head->data);
	ENDL;
}

int main(){
	struct Node *head = NULL;
	insertAtHead(&head, 5);
	insertAtHead(&head, 4);
	insertAtHead(&head, 3);
	insertAtHead(&head, 2);
	insertAtHead(&head, 1);
	insertAtHead(&head, 0);
	print(head);
	getNth(head, 0);

	return 0;
}
