/*
 *singly linked list
 *Name:Adersh A
 *Roll no:2
*/ 







#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
}*HEADER;
struct node *newNode() {
	struct node *newptr = malloc(sizeof(struct node));
	if (newptr == NULL) {
		printf("Memory overflow");
		exit(0);
	}
	return (newptr);
}
int insertNodeFront(int data) {
	struct node *newptr = newNode();
	newptr->next = HEADER->next;
	newptr->data = data;
	HEADER->next = newptr;
	return (0);
}
int insertNodeEnd(int data) {
	struct node *newptr = newNode(), *currentNode = HEADER;

	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}

	newptr->next = currentNode->next;
	newptr->data = data;
	currentNode->next = newptr;
	return (0);
}
int insertNodeAfter(int data, int previousData) {
	struct node *newptr = newNode(), *currentNode = HEADER;
	while (currentNode->data != previousData && currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	if (currentNode->data != previousData) {
		printf("Node not found.\nInsertion Failed\n");
	} else {
		newptr->next = currentNode->next;
		newptr->data = data;
		currentNode->next = newptr;
	}
	return (0);
}

int printLinkedList() {
	struct node *currentNode = HEADER->next;
	printf("\nLinked List\nHEADER->");
	while (currentNode != NULL) {
		printf("%d->", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("NULL\n");
	return (0);
}
int showMenu() {
	char choice='1';
	int data, previousData, nextData;
	while(choice != '0') {
		printf("\n\tLINKED LIST\n");
		printf("1. Insert at Front\n");
		printf("2. Insert at End\n");
                printf("3. Insert after\n");
		printf("4. Print Linked List\n");
		printf("0. Exit\n");
		printf("Enter your choice : ");
		scanf(" %c", &choice);
		printf("\n");
		switch (choice) {
			case '1':
				printf("Enter new data : ");
				scanf("%d", &data);
				insertNodeFront(data);
				break;
			
			case '2':
				printf("Enter new data : ");
				scanf("%d", &data);
				insertNodeEnd(data);
				break;

                        case '3':
				printf("Enter data after which new node is to be created : ");
				scanf("%d", &previousData);
				printf("Enter new data : ");
				scanf("%d", &data);
				insertNodeAfter(data, previousData);
				break;
			case '4':
				printLinkedList();
				break;
			
			case '0':
				exit(0);
				break;
			default:
				break;
		}
	}
	return (0);
}
int main() {
	// initialize Linked List
	HEADER = malloc(sizeof(struct node));
	HEADER->data = 0;
	HEADER->next = NULL;
	// finished initializing Linked List

	showMenu();
	
	
	return (0);
}

