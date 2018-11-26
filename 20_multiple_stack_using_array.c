#include <stdio.h>
#define size 100

int stack[size], begTop=-1, endTop=size;

int begPush(int data) {
	if (begTop == endTop-1) {
		printf("Stack overflow\n");
		return 0;
	} else {
		stack[++begTop] = data;
		return 1;
	}
}
int begPop() {
	if (begTop == -1) {
		printf("Stack underflow\n");
		return 0;
	} else {
		printf("Popped element is %d\n", stack[begTop]);
		begTop--;
		return 1;
	}
}
int begDisplay() {
	int i;
	printf("\n\nStack contents\n");
	if (begTop == -1) {
		printf("Empty stack\n");
	} else {
		for (i=begTop; i>=0; i--) {
			printf("%d\n", stack[i]);
		}
	}
	printf("\n");
}
int endPush(int data) {
	if (begTop == endTop-1) {
		printf("Stack overflow\n");
		return 0;
	} else {
		stack[--endTop] = data;
		return 1;
	}
}
int endPop() {
	if (endTop == size) {
		printf("Stack underflow\n");
		return 0;
	} else {
		printf("Popped element is %d\n", stack[endTop]);
		endTop++;
		return 1;
	}
}
int endDisplay() {
	int i;
	printf("\n\nStack contents\n");
	if (endTop == size) {
		printf("Empty stack\n");
	} else {
		for (i=endTop; i<size; i++) {
			printf("%d\n", stack[i]);
		}
	}
	printf("\n");
}
int main() {
	char ans;
	int data;
	do {
		printf("\n\n\tTwo Stack Using array\n");
		printf("\tBeg Stack\n1. Beg Push\n2. Beg Pop\n3. Beg Display\n");
    printf("\tEnd Stack\n4. End Push\n5. End Pop\n6. End Display\n");
    printf("7. Exit\nEnter your choice : ");
		scanf(" %c", &ans);
		switch (ans) {
			case '1':
				printf("Enter data to be pushed : ");
				scanf(" %d", &data);
				begPush(data);
				break;
			case '2':
				begPop();
				break;
			case '3':
				begDisplay();
				break;
			case '4':
				printf("Enter data to be pushed : ");
				scanf(" %d", &data);
				endPush(data);
				break;
			case '5':
				endPop();
				break;
			case '6':
				endDisplay();
				break;
      case '7':
        break;
			default:
				printf("Invalid choice.\n");
		}
	} while (ans != '7');
}
