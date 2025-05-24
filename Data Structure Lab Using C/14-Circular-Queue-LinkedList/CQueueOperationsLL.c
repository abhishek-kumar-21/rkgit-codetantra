struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
Node *front = NULL;
Node *rear = NULL;
void enqueue(int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocated failed.Cannot enqueue.\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = front;
    printf("Successfully inserted.\n");
}
void dequeue()
{
    if (front == NULL)
    {
        printf("Circular queue is underflow.\n");
        return;
    }
    Node *temp = front;
    int dequeuedItem = temp->data;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }
    free(temp);
    printf("Deleted value = %d\n", dequeuedItem);
}
void display()
{
    if (front == NULL)
    {
        printf("Circular queue is empty.\n");
        return;
    }
    printf("Elements in the circular queue : ");
    Node *current = front;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != front);
    printf("\n");
}
int is_empty()
{
    return front == NULL;
}
int size_queue()
{
    if (front == NULL)
    {
        return 0;
    }
    int count = 0;
    Node *current = front;
    do
    {
        count++;
        current = current->next;
    } while (current != front);
    return count;
}
void isEmpty()
{
    if (is_empty())
    {
        printf("Circular queue is empty.\n");
    }
    else
    {
        printf("Circular queue is not empty.\n");
    }
}
void size()
{
    printf("Circular queue size : %d\n", size_queue());
}