#include <stdio.h>
void main()
{
	int a[20], n, i, j, key, flag = 0, low, mid, high, temp;
	printf("n = ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	printf("Search key = ");
	scanf("%d", &key);
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i] + a[j];
				a[i] = temp - a[i];
				a[j] = temp - a[i];
			}
		}
	}
	printf("After sorting :\n");
	for (i = 0; i < n; i++)
		printf("a[%d] = %d\n", i, a[i]);
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high)
	{
		if (a[mid] < key)
		{
			low = mid + 1;
		}
		else if (a[mid] == key)
		{
			printf("Key %d is found at position %d.\n", key, mid);
			break;
		}
		else
		{
			high = mid - 1;
		}
		mid = (low + high) / 2;
	}
	if (low > high)
	{
		printf("Key %d is not found in the array.\n", key);
	}
}