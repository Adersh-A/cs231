#include <stdio.h>

int queue[100], n=100, front=-1, rear=-1;

void enqueueRear() {
	int data;
	if (rear == n-1) {
		printf("Failed: Queue full\n");
	} else {
		printf("Enter data to be entered : ");
		scanf("%d", &data);
		if (front == -1) {
			front = rear = 0;
		} else {
			rear++;
		}
		queue[rear] = data;
	}
}
void enqueueFront() {
    int data;
    if (front == 0) {
        printf("Failed: No space at front\n");
    } else {
        printf("Enter data to be inserted : ");
        scanf("%d", &data);
        if (front == -1) {
            front = rear = 0;
        } else {
            front--;
        }
        queue[front] = data;
    }
}
void dequeueRear() {
    if (rear == -1) {
        printf("Failed: Empty queue\n");
    } else {
        printf("Deleted element : %d\n", queue[rear]);
        if (front == rear) {
            front = rear = -1;
        } else {
            rear--;
        }
    }
}
void dequeueFront() {
	if (front == -1) {
		printf("Failed: Empty queue\n");
	} else {
		printf("Deleted element : %d\n", queue[front]);
		if (front == rear) {
			front = rear = -1;
		} else {
			front++;
		}
	}
}
void printQueue() {
	int i=0;
	if (front == -1) {
		printf("Empty Queue\n");
	} else {
		for (i=front; i<=rear; i++) {
			printf("%d\n", queue[i]);
		}
	}
}
int main() {
	char choice;
	front = rear = -1;
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
