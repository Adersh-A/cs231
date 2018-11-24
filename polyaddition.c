#include <stdio.h>
#include <stdlib.h>
struct node {
	int exponent;
	int coefficient;
	struct node *next;
}*polynomial1, *polynomial2, *polynomial3;
int deleteAll(struct node *polynomial) {
	struct node *ptr = polynomial, *prevPtr;
	while (ptr != NULL) {
		prevPtr = ptr;
		ptr = ptr->next;
		free(prevPtr);
	}
	polynomial->next = NULL;
	return (0);
}
struct node *newNode() {
	struct node *newptr = malloc(sizeof(struct node));
	if (newptr == NULL) {
		printf("Memory overflow");
		deleteAll(polynomial1);
		deleteAll(polynomial2);
		deleteAll(polynomial3);
		exit(0);
	}
	return (newptr);
}
int insertNodeEnd(struct node *polynomial, int exponent, int coefficient) {
	struct node *newptr = newNode(), *currentNode = polynomial;

	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}

	newptr->next = currentNode->next;
	newptr->exponent = exponent;
	newptr->coefficient = coefficient;
	currentNode->next = newptr;
	return (0);
}
int addPolynomial(struct node *a, struct node *b, struct node *sum) {
	struct node *ca=a->next, *cb=b->next;
	while (ca != NULL && cb !=NULL) {
		if (ca->exponent > cb->exponent) {
			insertNodeEnd(sum, ca->exponent, ca->coefficient);
			ca=ca->next;
		} else if (ca->exponent < cb->exponent) {
			insertNodeEnd(sum, cb->exponent, cb->coefficient);
			cb=cb->next;
		} else {
			insertNodeEnd(sum, ca->exponent, ca->coefficient+cb->coefficient);
			ca=ca->next;
			cb=cb->next;
		}
	}
	while (ca != NULL) {
		insertNodeEnd(sum, ca->exponent, ca->coefficient);
		ca=ca->next;
	}
	while (cb != NULL) {
		insertNodeEnd(sum, cb->exponent, cb->coefficient);
		cb=cb->next;
	}
}
int printPolynomial(struct node *polynomial, char polynomialName) {
	struct node *currentNode = polynomial->next;
	printf("%c(x) = ", polynomialName);
	while (currentNode != NULL) {
		if (currentNode->coefficient != 0) {
			if (currentNode->coefficient != 1) {
				printf("%d", currentNode->coefficient);
			}
			if (currentNode->exponent != 0) {
				printf("x^%d", currentNode->exponent);
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
int populatePolynomial(struct node *polynomial) {
	char choice;
	int coefficient, exponent;
	do {
		printf("Enter coefficient : ");
		scanf("%d", &coefficient);
		printf("Enter exponent : ");
		scanf("%d", &exponent);
		insertNodeEnd(polynomial, exponent, coefficient);
		printf("\n1. Add more terms\n");
		printf("2. Continue\n");
		printf("Enter your choice : ");
		scanf(" %c", &choice);
		printf("\n");
	} while (choice != '2');
	return(0);
}
int main() {
	polynomial1 = malloc(sizeof(struct node));
	polynomial1->coefficient = 0;
	polynomial1->exponent = 0;
	polynomial1->next = NULL;
	printf("\tPolynomial 1\n");
	populatePolynomial(polynomial1);

	polynomial2 = malloc(sizeof(struct node));
	polynomial2->coefficient = 0;
	polynomial2->exponent = 0;
	polynomial2->next = NULL;
	printf("\tPolynomial 2\n");
	populatePolynomial(polynomial2);

	polynomial3 = malloc(sizeof(struct node));
	polynomial3->coefficient = 0;
	polynomial3->exponent = 0;
	polynomial3->next = NULL;

	printf("\nAdding polynomials\n");
	printPolynomial(polynomial1, 'P');
	printPolynomial(polynomial2, 'Q');
	printf("Sum\n");
	addPolynomial(polynomial1, polynomial2, polynomial3);
	printPolynomial(polynomial3, 'R');

	deleteAll(polynomial1);
	deleteAll(polynomial2);
	deleteAll(polynomial3);
	return (0);
}
