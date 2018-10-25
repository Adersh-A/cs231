/*
 *Insertion sort
 *Author:Adersh A
 *Roll no:2
*/ 


#include <stdio.h>

int inSort(int array[], int n) {
	int i, j, temp;
	for (i=1; i<n; i++) {
		temp = array[i];
		for (j=i-1; j>=0 && array[j] > temp; j--) {
				array[j+1] = array[j];
		}
		array[j+1] = temp;
	}
}
void main() {
	int array[100], i, j, size;

	printf("Enter size of the array : ");
	scanf("%d", &size);

	printf("Enter array\n");
	for (i=0; i<size; i++) {
		scanf("%d", &array[i]);
	}

	inSort(array, size);
	
	printf("Sorted array\n");
	for (i=0; i<size; i++) {
		printf("%d\n", array[i]);
	}
}
