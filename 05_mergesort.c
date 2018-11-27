#include <stdio.h>

void merge(int a[], int l, int m, int r) {
	int b[100], i, j, k;
	i = l;
	j = m+1;
	k = 0;
	while (i<=m && j<=r) {
		if (a[i]>a[j]) {
			b[k++] = a[j++];
		}
		else {
			b[k++] = a[i++];
		}
	}
	while (i<=m)
		b[k++] = a[i++];
	while (j<=r)
		b[k++] = a[j++];
	
	while (j>l)
		a[--j] = b[--k];
}
int printArray(int a[], int size) {
	int i=0;
	for (i=0; i<size; i++) {
		printf("%d\n", a[i]);
	}
}
int main() {
	int a[100], size, currentSize, i, j, l, r, m;

	printf("Enter array size : ");
	scanf("%d", &size);
	printf("Enter array elements\n");
	for (i=0; i<size; i++) {
		scanf("%d", &a[i]);
	}
	printf("Sorted array\n");
	for (currentSize=1; currentSize<size; currentSize*=2) {
		for (l=0; l<size-1; l+=2*currentSize) {
			m=l+currentSize-1;
			if (m+currentSize < size-1)
				r=l+2*currentSize-1;
			else
				r=size-1;
			merge(a, l, m, r);
		}
	}
	printArray(a, size);
}
