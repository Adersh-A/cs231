#include <stdio.h>
#include <stdlib.h>

const int size=100;
int binaryTree[100];

void initialise() {
	int i=0;
	for (i=0; i<size; i++)
		binaryTree[i] = -1;
}
void inorder(int root) {
	int left, right;
	if (root<size) {
		if (binaryTree[root] != -1) {
			left = root*2+1;
			right = root*2+2;
			if (left<size)
				if (binaryTree[left] != -1)
					inorder(left);
			printf(" %d", binaryTree[root]);
			if (right<size)
				if (binaryTree[right] != -1)
					inorder(right);
		}
	}
}
		
int search(int key) {
	int i=0;
	for (i=0; i<size; i++)
		if (binaryTree[i]==key) return i;
	return -1;
}
void insert() {
	int index, data, key, left, right;
	char child;
	if (binaryTree[0] == -1) {
		printf("Enter data to be inserted : ");
		scanf("%d", &data);
		binaryTree[0] = data;
		printf("Successfully inserted\n");
	} else {
		printf("Enter data of the parent node : ");
		scanf("%d", &key);
		index = search(key);
		if (index == -1) {
			printf("Key not found");
		} else {
			printf("Enter data to be inserted : ");
			scanf("%d", &data);
			printf("Where do you want to enter the data (L/R): ");
			scanf(" %c", &child);
			left=2*index+1;
			right=2*index+2;
			if (child == 'l' || child == 'L')
				if (left<size) {
					if (binaryTree[left] == -1) {
						binaryTree[left] = data;
						printf("Successfully inserted\n");
					} else {
						printf("Node not empty. Insertion failed\n");
					}
				}
				else
					printf("Out of memory. Cannot insert\n");
			else
				if (right<size) {
					if (binaryTree[left] == -1) {
						binaryTree[right] = data;
						printf("Successfully inserted\n");
					} else {
						printf("Node not empty. Insertion failed\n");
					}
				}
				else
					printf("Out of memory. Cannot insert\n");
		}
	}
}

void delete() {
	int data, index, i;
	printf("Enter data of the node to be deleted : ");
	scanf("%d", &data);
	index=search(data);
	if (index==-1) {
		printf("Node not found\n");
	} else {
		for (i=size-1; i>=0; i--)
			if (binaryTree[i] !=-1)
				break;
		binaryTree[index] = binaryTree[i];
		binaryTree[i] = -1;
		printf("Successfully deleted\n");
	}
}
int showMenu() {
	char choice;
	int key, index;
	do {
		printf("\n\tBinary Tree\n");
		printf("1. Insert\n");
		printf("2. Search\n");
		printf("3. Delete\n");
		printf("4. Print\n");
		printf("5. Exit\n");
		printf("Enter your choice : ");
		scanf(" %c", &choice);
		switch (choice) {
			case '1':
				insert();
				break;
			case '2':
				printf("Enter data to be searched : ");
				scanf("%d", &key);
				index = search(key);
				if (index==-1)
					printf("Element not found\n");
				else
					printf("Node found\n");
				break;
			case '3':
				delete();
				break;
			case '4':
				inorder(0);
				break;
			case '5':
				break;
			default:
				printf("Invalid option\n");
				break;
		}
	} while(choice!='5');
}
int main() {
	initialise();
	showMenu();
}
