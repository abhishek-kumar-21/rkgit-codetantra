int a[10];
int min = -1;
int push(int x)
{
	if (min == 9)
	{
		printf("Stack is overflow.\n");
		return;
	}
	a[++min] = x;
	printf("Successfully pushed.\n");
}
void pop()
{
	int j = min;
	if (j == -1)
	{
		printf("Stack is underflow.\n");
		return;
	}
	printf("Popped value = %d\n", a[j]);
	min--;
}
void display()
{
	int i = min;
	if (i == -1)
	{
		isEmpty();
		return;
	}
	printf("Elements of the stack are : ");
	while (i > -1)
	{
		printf("%d ", a[i]);
		i--;
	}
	printf("\n");
}
void isEmpty()
{
	if (min == -1)
		printf("Stack is empty.\n");
	else
		printf("Stack is not empty.\n");
}
void peek()
{
	if (min == -1)
	{
		printf("Stack is underflow.\n");
		return;
	}
	printf("Peek value = %d\n", a[min]);
}