#include <stdio.h>
#include <stdlib.h>
struct node {
	int exponent;
	int coefficient;
	struct node *next;
}*Polynomial;
int deleteAll() {
	struct node *ptr = Polynomial, *prevPtr;
	while (ptr != NULL) {
		prevPtr = ptr;
		ptr = ptr->next;
		free(prevPtr);
	}
	Polynomial->next = NULL;
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
int insertNodeEnd(int exponent, int coefficient) {
	struct node *newptr = newNode(), *currentNode = Polynomial;

	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}

	newptr->next = currentNode->next;
	newptr->exponent = exponent;
	newptr->coefficient = coefficient;
	currentNode->next = newptr;
	return (0);
}

int printPolynomial() {
	struct node *currentNode = Polynomial->next;
	printf("\nF(p) = ");
	while (currentNode != NULL) {
		if (currentNode->coefficient != 0) {
			if (currentNode->coefficient != 1) {
				printf("%d", currentNode->coefficient);
			}
			if (currentNode->exponent != 0) {
				printf("p^%d", currentNode->exponent);
			}
			if (currentNode->next != NULL) {
				if (currentNode->next->coefficient != 0)
					printf(" + ");
			}
		}
		currentNode = currentNode->next;
	}
	printf("\n");
	return (0);
}
int showMenu() {
	char choice;
	int coefficient, exponent;
	do {
		printf("Enter coefficient : ");
		scanf("%d", &coefficient);
		printf("Enter exponent : ");
		scanf("%d", &exponent);
		insertNodeEnd(exponent, coefficient);
		printf("\n1. Add more terms\n");
		printf("2. Print and exit\n");
		printf("Enter your choice : ");
		scanf(" %c", &choice);
		printf("\n");
	} while (choice != '2');
	return(0);
}
int main() {
	Polynomial = malloc(sizeof(struct node));
	Polynomial->coefficient = 0;
	Polynomial->exponent = 0;
	Polynomial->next = NULL;
	showMenu();
	printPolynomial();
	deleteAll();
	return (0);
}
