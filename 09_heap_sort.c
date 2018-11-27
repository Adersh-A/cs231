#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int array[], int size, int root) {
  int largest = root;
  int left = root*2+1;
  int right = root*2+2;

  if (left<size && array[left]>array[largest]) {
    largest = left;
  }
  if (right<size && array[right]>array[largest]) {
    largest = right;
  }
  if (largest != root) {
    swap(&array[root], &array[largest]);
    heapify(array, size, largest);
  }
}
void heapSort(int array[], int size) {
  int i;
  for (i=size/2-1; i>=0; i--)
    heapify(array, size, i);
  for (i=size-1; i>0; i--) {
    swap(&array[0], &array[i]);
    heapify(array, i, 0);
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
	heapSort(array, size);
	printArray(array, size);
}