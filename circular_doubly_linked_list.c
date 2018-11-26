#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* prev;
}*HEADER;

int deleteAll() {
	struct node *currentNode = HEADER, *previousNode;
	while (currentNode != HEADER) {
		previousNode = currentNode;
		currentNode = currentNode->next;
		free(previousNode);
	}
	HEADER->next = HEADER;
    HEADER->prev = HEADER;
	return (0);
}
struct node* newNode() {
	struct node* newptr = malloc(sizeof(struct node));
	if (newptr == NULL) {
		printf("Memory overflow\n");
		deleteAll();
		exit(0);
	}
	return (newptr);
}
int insertNodeFront (int data) {
	struct node *new = newNode();
	new->data = data;
	new->prev = HEADER;
	new->next = HEADER->next;
	HEADER->next = new;
    new->next->prev = new;
	return (0);
}
int insertNodeBefore(int data, int nextData) {
	struct node *new = newNode(), *currentNode=HEADER;
	new->data = data;
	while (currentNode->next != HEADER && currentNode->data != nextData) {
		currentNode = currentNode->next;
	}
	if (currentNode->data == nextData) {
		new->next = currentNode;
		new->prev = currentNode->prev;
		currentNode->prev = new;
        new->prev->next = new;
	} else {
		printf("Insertion failed. Element not found\n");
	}
	return (0);
}
int insertNodeAfter(int data, int prevData) {
	struct node *new = newNode(), *currentNode=HEADER->next;
	new->data = data;
	while (currentNode != HEADER && currentNode->data != prevData) {
		currentNode = currentNode->next;
	}
	if (currentNode->data != prevData) {
		printf("Insertion failed. Element not found\n");
	} else {
		new->prev = currentNode;
		new->next = currentNode->next;
		currentNode->next = new;
        new->next->prev = new;
	}
	return (0);
}
int insertNodeBack (int data) {
	struct node *new = newNode(), *currentNode=HEADER;
	while (currentNode->next != HEADER) {
		currentNode = currentNode->next;
	}
	new->data = data;
	new->next = HEADER;
	new->prev = currentNode;
	currentNode->next = new;
	return (0);
}
int deleteFirstNode () {
	struct node *currentNode = HEADER->next;
	if (HEADER->next == HEADER) {
		printf("Empty linked list\n");
	} else {
		HEADER->next = HEADER->next->next;
		HEADER->next->prev = HEADER;
		free(currentNode);
	}
	return (0);
}
int deleteLastNode () {
	struct node *currentNode = HEADER;
	while (currentNode->next != HEADER) {
		currentNode = currentNode->next;
	}
	if (currentNode == HEADER) {
		printf ("Empty linked list");
	} else {
		currentNode->prev->next = HEADER;
		free(currentNode);
	}
	return (0);
}
int deleteNode(int data) {
	struct node *currentNode = HEADER;
	while (currentNode->next != HEADER && currentNode->data != data) {
		currentNode = currentNode->next;
	}
	if (currentNode->data != data) {
		printf("Deletion failed. Node with matching data not found\n");
	} else {
		currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
		free(currentNode);
	}
	return (0);
}
int printAll() {
	struct node* currentNode = HEADER->next;
    if (HEADER->next == HEADER) {
        printf("Empty\n");
    } else {
        printf("HEADER<->");
        while (currentNode->next != HEADER) {
            printf("%d<->", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("%d->HEADER\n", currentNode->data);
    }
	return (0);
}
int showMenu() {
	char choice;
	int data, previousData, nextData;
	while (1) {
		printf("\n\n\tDoubly Linked List\n");
		printf("1. Insert at Front\n");
		printf("2. Insert before\n");
		printf("3. Insert after\n");
		printf("4. Insert at End\n");
		printf("5. Print Linked List\n");
		printf("6. Delete first node\n");
		printf("7. Delete node\n");
		printf("8. Delete last node\n");
		printf("9. Delete all\n");
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
				insertNodeBack(data);
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
	return (0);
}
int main() {
	// Initialise Linked list
	HEADER = malloc(sizeof(struct node));
	HEADER->data = 0;
	HEADER->next = HEADER;
	HEADER->prev = HEADER;
	
	// Menu
	showMenu();
	return (0);
}
