// write your code here
#define M 100
int arr[M];
int f = -1, r = -1;

void size()
{
    int s = 0;
    if (f == -1)
    {
        printf("Queue size : 0\n");
    }
    else
    {
        printf("Queue size : ");
        for (int i = f; i <= r; i++)
        {
            s++;
        }
        printf("%d\n", s);
    }
}

void enqueue(int a)
{
    if (r == M - 1)
    {
        printf("Queue Overflow.\n");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
        r = r + 1;
        arr[r] = a;
        printf("Successfully inserted.\n");
    }
}

void dequeue()
{
    if (f == -1 || f > r)
    {
        printf("Queue is underflow.\n");
    }
    else
    {
        printf("Deleted value = %d\n", arr[f]);
        f++;
    }
}

void display()
{
    int i;
    if (f == -1 || f > r)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Elements in the queue : ");
        for (i = f; i <= r; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void isEmpty()
{
    if (f < 0 || f > r)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is not empty.\n");
    }
}