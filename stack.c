#include <stdio.h>
#include <stdlib.h>

int stack[100], n=100, top;

int push(int data) {
	if (top >= n-1) {
		printf("Stack overflow\n");
		return 0;
	} else {
		stack[++top] = data;
		return 1;
	}
}
int pop() {
	if (top == -1) {
		printf("Stack underflow\n");
		return 0;
	} else {
		printf("Popped element is %d\n", stack[top]);
		top--;
		return 1;
	}
}
int display() {
	int i;
	printf("\n\nStack contents\n");
	if (top == -1) {
		printf("Empty stack\n");
	} else {
		for (i=top; i>=0; i--) {
			printf("%d\n", stack[i]);
		}
	}
	printf("\n");
}
int main() {
	top = -1;
	char ans;
	int data;
	do {
		printf("\n\n\tStack Using array\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice : ");
		scanf(" %c", &ans);
		switch (ans) {
			case '1':
				printf("Enter data to be pushed : ");
				scanf(" %d", &data);
				push(data);
				break;
			case '2':
				pop();
				break;
			case '3':
				display();
				break;
			case '4':exit(0);
                        default :printf("invalid choice");
                                 exit(0);
			
		}
	} while (1);
}
