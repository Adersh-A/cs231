/*
 *Sequential search
 *Name:Adersh A
 *Roll no:2
*/ 

#include <stdio.h>

int seqSearch(int array[], int n, int ele) {
	int i;

	for (i=0; i<n; i++) {
		if (array[i] == ele) {
			return (i+1);
		}
	}
	return (0);
}
int main() {
	int i=0, flag=0, array[100], size, element;

	printf("Enter number of elements : ");
	scanf("%d", &size);

	printf("Enter elements\n");
	for (i=0; i<size; i++) {
		scanf("%d", &array[i]);
	}

	printf("Enter element to search : ");
	scanf("%d", &element);

	flag = seqSearch(array, size, element);

	if (flag) {
		printf("Element found at position %d\n", flag);
	} else {
		printf("Element not found\n");
	}
}
