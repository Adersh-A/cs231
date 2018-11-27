#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(int array[], int low, int high) {
  int i = low-1;
  int pivot = array[high];

  for (int j=low; j<high; j++) {
    if (array[j]<pivot) {
      swap(&array[++i], &array[j]);
    }
  }
  swap(&array[++i], &array[high]);
  return i;
}
int quickSortIterative(int array[], int low, int high) {
  int stack[100];
  int partitionIndex, top=-1;
  stack[++top] = low;
  stack[++top] = high;
  while (top > -1) {
    high = stack[top--];
    low = stack[top--];
    partitionIndex = partition(array, low, high);
    if (low < partitionIndex-1) {
      stack[++top] = low;
      stack[++top] = partitionIndex-1;
    }
    if (partitionIndex+1 < high) {
      stack[++top] = partitionIndex+1;
      stack[++top] = high;
    }
  }
}
int printArray(int a[], int size) {
	int i=0;
	for (i=0; i<size; i++) {
		printf("%d\n", a[i]);
	}
}
int main() {
	int array[100], i, size;
	printf("Enter size of the array : ");
	scanf("%d", &size);
	printf("Enter array elements\n");
	for (i=0; i<size; i++)
		scanf("%d", &array[i]);
	printf("Sorted Array\n");
	quickSortIterative(array, 0, size-1);
	printArray(array, size);
}