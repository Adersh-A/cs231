#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
}*HEADER;
int deleteAll() {
	struct node *currentNode = HEADER->next, *previousNode;
	while (currentNode != HEADER) {
		previousNode = currentNode;
		currentNode = currentNode->next;
		free(previousNode);
	}
	HEADER->next = NULL;
	free(HEADER);
	return (0);
}
int deleteNode(int data) {
	struct node *currentNode = HEADER, *previousNode;
	while (currentNode->next != HEADER && currentNode->data != data) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode->data == data) {
		previousNode->next = currentNode->next;
		free(currentNode);
	} else {
		printf("Deletion failed. Node not found\n");
	}
	return (0);
}
int deleteLastNode() {
	struct node *currentNode = HEADER->next, *previousNode;
	while (currentNode->next != HEADER) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode == HEADER) {
		printf("Deletion failed. Empty linked list\n");
	} else {
		previousNode->next = currentNode->next;
		free(currentNode);
	}
	return (0);
}
int deleteFirstNode() {
	struct node *currentNode = HEADER->next;
	if (currentNode == HEADER) {
		printf("Deletion failed. Empty linked list");
	} else {
		HEADER->next = currentNode->next;
		free(currentNode);
	}
	return (0);
}
struct node* newNode() {
	struct node *new = malloc(sizeof(struct node));
	if (new == NULL) {
		printf("Memory Overflow");
		deleteAll();
		exit(0);
	}
	new->data = 0;
	new->next = NULL;
	return (new);
}
int insertNodeFront(int data) {
	struct node *new = newNode();
	new->data = data;
	new->next = HEADER->next;
	HEADER->next = new;
	return (0);
}
int insertNodeEnd(int data) {
	struct node *new = newNode(), *currentNode=HEADER;
	while (currentNode->next != HEADER) {
		currentNode = currentNode->next;
	}
	new->data = data;
	new->next = HEADER;
	currentNode->next = new;
	return (0);
}
int insertNodeAfter(int data, int previousData) {
	struct node *new = newNode(), *currentNode=HEADER->next;
	while (currentNode != HEADER && currentNode->data != previousData) {
		currentNode = currentNode->next;
	}
	if (currentNode == HEADER) {
		printf("Insertion failed. Node not found\n");
	} else {
		new->data = data;
		new->next = currentNode->next;
		currentNode->next = new;
	}
	return (0);
}
int insertNodeBefore(int data, int nextData) {
	struct node *new = newNode(), *currentNode=HEADER->next, *previousNode=HEADER;
	while (currentNode != HEADER && currentNode->data != nextData) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode == HEADER) {
		printf("Insertion failed. Node not found\n");
	} else {
		new->data = data;
		new->next = previousNode->next;
		previousNode->next = new;
	}
	return (0);
}
int printAll() {
	struct node *currentNode = HEADER->next;
	printf("HEADER->");
	while (currentNode != HEADER) {
		printf("%d->", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("HEADER\n");
	return (0);
}
int showMenu() {
	char choice;
	int data, previousData, nextData;
	while (1) {
		printf("\n\n\tCIRCULAR SINGLY LINKED LIST\n");
		printf("1. Insert at front\n");
		printf("2. Insert before\n");
		printf("3. Insert after\n");
		printf("4. Insert at end\n");
		printf("5. Print all\n");
		printf("6. Delete first\n");
		printf("7. Delete node\n");
		printf("8. Delete last\n");
		printf("9. Delet all\n");
		printf("0. Exit\n");
		printf("Enter your choice : ");
		scanf(" %c", &choice);
		switch(choice) {
			case '1':
				printf("Enter new data : ");
				scanf("%d", &data);
				insertNodeFront(data);
				break;
			case '2': 
				printf("Enter new data : ");
				scanf("%d", &data);
				printf("Enter data of the node before which new node is to be created : ");
				scanf("%d", &nextData);
				insertNodeBefore(data, nextData);
				break;
			case '3': 
				printf("Enter new data : ");
				scanf("%d", &data);
				printf("Enter data of the node after which new node is to be created : ");
				scanf("%d", &previousData);
				insertNodeAfter(data, previousData);
				break;
			case '4':
				printf("Enter new data : ");
				scanf("%d", &data);
				insertNodeEnd(data);
				break;
			case '5':
				printAll();
				break;
			case '6':
				deleteFirstNode();
				break;
			case '7':
				printf("Enter data of the node to be deleted : ");
				scanf("%d", &data);
				deleteNode(data);
				break;
			case '8':
				deleteLastNode();
				break;
			case '9':
				deleteAll();
				break;
			case '0':
				deleteAll();
				exit(0);
				break;
		}
	}
}
int main() {
	// Initialize linked list
	HEADER = malloc(sizeof(struct node));
	HEADER->data = 0;
	HEADER->next = HEADER;

	showMenu();

	return(0);
}
