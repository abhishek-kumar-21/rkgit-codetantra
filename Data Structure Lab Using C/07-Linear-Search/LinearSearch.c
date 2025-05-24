#include <stdio.h>
void main()
{
	int a[100], i, s, n, c = 0;
	printf("n = ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	printf("Search key : ");
	scanf("%d", &s);

	for (i = 0; i < n; i++)
	{
		if (s == a[i])
		{
			printf("Key %d is found at position %d.\n", s, i);

			c = 1;
			break;
		}
	}
	if (c == 0)
	{
		printf("Key %d is not found.\n", s);
	}
}