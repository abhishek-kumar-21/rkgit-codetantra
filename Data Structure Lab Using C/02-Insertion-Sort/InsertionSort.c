#include <stdio.h>
void main()
{
	int a[20], i, n, j, temp;
	printf("n = ");
	scanf("%d", &n);
	// Write the for loop to read array elements
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}

	printf("Before sorting : \n");
	// Write the for loop to display array elements before sorting
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}

	// Write the code to sort elements
	for (i = 1; i <= n - 1; i++)
	{
		temp = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}

	printf("After sorting : \n");
	// Write the for loop to display array elements after sorting
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
}