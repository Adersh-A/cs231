/*
 *Selection sort
 *Name:Adersh A
 *Roll no:2
*/ 

#include <stdio.h>

int selSort(int array[], int n) {
	int i, j, pos, temp;
	for (i=0; i<n; i++) {
		pos = i;

		for (j=i; j<n; j++) {
			if (array[j] < array[pos]) {
				pos =j;
			}
		}
		if (i != pos) {
			temp = array[i];
			array[i] = array[pos];
			array[pos] = temp;
		}
	}
}

int main() {
	int i, j, pos, array[100], temp, size;

	printf("Enter number of elements in the array : ");
	scanf("%d", &size);

	printf("Enter the array\n");
	for (i=0; i<size; i++) {
		scanf("%d", &array[i]);
	}
	
	selSort(array, size);

	printf("Sorted array \n");
	for (i=0; i<size; i++) {
		printf("%d\n", array[i]);
	}
}
