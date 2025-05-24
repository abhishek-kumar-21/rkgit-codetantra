#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
void enqueue(int item)
{
    if ((rear + 1) % MAX_SIZE == front)
    {
        printf("Circular queue is overflow.\n");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = item;
        printf("Successfully inserted.\n");
    }
}
int dequeue1()
{
    int removedItem;
    if (front == -1)
    {
        return -1;
    }
    else
    {
        removedItem = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        return removedItem;
    }
}
int dequeue()
{
    int item = dequeue1();
    if (item != -1)
    {
        printf("Deleted element = %d\n", item);
    }
    else
    {
        printf("Circular queue is underflow.\n");
    }
}
void display()
{
    if (front == -1)
    {
        printf("Circular queue is empty.\n");
    }
    else
    {
        printf("Elements in the circular queue : ");
        int i = front;
        do
        {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}
void isEmpty()
{
    if (front == -1)
    {
        printf("Circular queue is empty.\n");
    }
    else
    {
        printf("Circular queue is not empty.\n");
    }
}
int size1()
{
    if (front == -1)
    {
        return 0;
    }
    else
    {
        return (rear - front + MAX_SIZE) % MAX_SIZE + 1;
    }
}
void size()
{
    printf("Circular queue size : %d\n", size1());
}