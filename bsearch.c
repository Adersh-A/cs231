    #include <stdio.h>
     
    int main()
    {
       int i, first, last, middle, n, search, array[100],j,swap;
     
       printf("Enter number of elements\n");
       scanf("%d",&n);
     
       printf("Enter %d integers\n", n);
     
       for (i=0; i<n; i++)
          scanf("%d",&array[i]);

       for (i=0 ; i<n-1; i++)
	{
          for (j=0 ; j<n-i-1;j++)
             {
                if (array[j] > array[j+1]) /* For decreasing order use < */
                    {
                       swap=array[j];
                       array[j]=array[j+1];
                       array[j+1]=swap;
                    }
             }
        }
	printf("sorted array ");
	for(i=0;i<n;i++)
	{
		printf("%d",array[i]);
	}

     
       printf("\n Enter value to find\n");
       scanf("%d", &search);
     
       first = 0;
       last = n - 1;
       middle = (first+last)/2;
     
       while (first <= last) {
          if (array[middle] < search)
             first = middle + 1;    
          else if (array[middle] == search) {
             printf("%d found at location %d.\n", search, middle+1);
             break;
          }
          else
             last = middle - 1;
     
          middle = (first + last)/2;
       }
       if (first > last)
          printf("Not found! %d isn't present in the list.\n", search);
     
       return 0;  
    }
