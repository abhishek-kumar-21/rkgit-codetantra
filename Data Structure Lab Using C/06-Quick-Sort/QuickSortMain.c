#include <stdio.h>
#include "QuickSortFunctions.c"
void main()
{
	int arr[15], i, n;
	printf("Enter array size : ");
	scanf("%d", &n);
	printf("Enter %d elements : ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Before sorting the elements are : ");
	display(arr, n);
	quickSort(arr, 0, n - 1);
	printf("After sorting the elements are : ");
	display(arr, n);
}