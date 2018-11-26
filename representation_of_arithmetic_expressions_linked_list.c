#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
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

int printLinkedList() {
	struct node *currentNode = HEADER->next;
	while (currentNode != NULL) {
		printf("%c", currentNode->data);
		currentNode = currentNode->next;
	}
  printf("\n");
	return (0);
}

int main() {
  char infix[100], buffer;
  int i=0;
	// initialize Linked List
	HEADER = malloc(sizeof(struct node));
	HEADER->data = 0;
	HEADER->next = NULL;
	// finished initializing Linked List

  printf("Enter arithmatic expression : ");
  scanf("%s", infix);
  for (i=0; infix[i]!='\0'; i++) {
    insertNodeEnd(infix[i]);
  }
  printf("Entered experssion : ");
  printLinkedList();

	deleteAll();
	
	return (0);
}
