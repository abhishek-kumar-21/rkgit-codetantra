void display(int arr[15], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int partition(int arr[15], int lb, int ub)
{
	int pivot = arr[ub];
	int i = lb - 1;
	for (int j = lb; j < ub; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i + 1];
	arr[i + 1] = arr[ub];
	arr[ub] = temp;
	return i + 1;
}
void quickSort(int arr[15], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}