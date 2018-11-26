#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
}*HEADER;
int deleteAll() {
	struct node *ptr = HEADER, *prevPtr;
	while (ptr != NULL) {
		prevPtr = ptr;
		ptr = ptr->next;
		free(prevPtr);
	}
	HEADER->next = NULL;
	return (0);
}
struct node *newNode() {
	struct node *newptr = malloc(sizeof(struct node));
	if (newptr == NULL) {
		printf("Memory overflow");
		deleteAll();
		exit(0);
	}
	return (newptr);
}
void enqueueRear() {
	int data;
  printf("Enter data : ");
  scanf("%d", &data);
	struct node *newptr = newNode(), *currentNode = HEADER;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	newptr->next = currentNode->next;
	newptr->data = data;
	currentNode->next = newptr;
}
void enqueueFront() {
  int data;
  printf("Enter data : ");
  scanf("%d", &data);
	struct node *newptr = newNode();
	newptr->next = HEADER->next;
	newptr->data = data;
	HEADER->next = newptr;
}
void dequeueRear() {
	struct node *currentNode = HEADER->next, *previousNode=HEADER;
	if (currentNode == NULL) {
		printf("Empty linked list.\nDeletion failed.\n");
	} else {
		while (currentNode->next != NULL) {
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		previousNode->next = NULL;
		free (currentNode);
	}
}
void dequeueFront() {
	struct node *currentNode = HEADER->next;
	if (currentNode == NULL) {
		printf("Empty linked list.\nDeletion failed.\n");
	} else {
		HEADER->next = currentNode->next;
		free(currentNode);
	}
}
void printQueue() {
	struct node *currentNode = HEADER->next;
	printf("\nLinked List\nHEADER->");
	while (currentNode != NULL) {
		printf("%d->", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("NULL\n");
}
int main() {
	char choice;
	HEADER = malloc(sizeof(struct node));
	HEADER->data = 0;
	HEADER->next = NULL;
	do {
		printf("\n\tQueue using array\n");
        printf("1.Enqueue Front\n");
        printf("2.Enqueue Rear\n");
        printf("3.Dequeue Front\n");
        printf("4.Dequeue Rear\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter your choice : ");
		scanf(" %c", &choice);
		switch(choice) {
			case '1':
				enqueueFront();
				break;
			case '2':
				enqueueRear();
				break;
			case '3':
				dequeueFront();
				break;
			case '4':
				dequeueRear();
				break;
			case '5':
				printQueue();
				break;
		}
	} while(choice != '6');
}
