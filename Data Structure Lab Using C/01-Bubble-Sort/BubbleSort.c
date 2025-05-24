#include <stdio.h>
void main()
{
	int a[30], n, i, j, temp;
	printf("n : ");
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
	for (i = n - 2; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	printf("After sorting : \n");
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
}