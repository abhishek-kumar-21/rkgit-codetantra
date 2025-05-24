#include <stdio.h>
void main()
{
	int a[20], i, j, n, maxIndex, temp;
	printf("n = ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	printf("Before sorting : \n");
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
	for (i = n - 1; i > 0; i--)
	{
		maxIndex = 0;
		for (j = 1; j <= i; j++)
		{
			if (a[j] > a[maxIndex])
			{
				maxIndex = j;
			}
		}
		temp = a[i];
		a[i] = a[maxIndex];
		a[maxIndex] = temp;
	}
	printf("After sorting : \n");
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
}