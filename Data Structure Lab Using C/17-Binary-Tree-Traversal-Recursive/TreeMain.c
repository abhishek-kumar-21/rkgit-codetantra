// Program for linked implementation of complete binary tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "TreeStructure.c"
#include "Traversals.c"

// For Queue Size
#define SIZE 100000

// A utility function to create a new Queue
struct Queue *createQueue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    queue->front = queue->rear = -1;
    queue->size = size;

    queue->array = (struct node **)malloc(queue->size * sizeof(struct node *));

    int i;
    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;

    return queue;
}

// Standard Queue Functions
int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

int isFull(struct Queue *queue)
{
    return queue->rear == queue->size - 1;
}

int hasOnlyOneItem(struct Queue *queue)
{
    return queue->front == queue->rear;
}

void Enqueue(struct node *root, struct Queue *queue)
{
    if (isFull(queue))
        return;
    queue->array[++queue->rear] = root;
    if (isEmpty(queue))
        ++queue->front;
}
struct node *Dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return NULL;
    struct node *temp = queue->array[queue->front];

    if (hasOnlyOneItem(queue))
        queue->front = queue->rear = -1;
    else
        ++queue->front;
    return temp;
}

struct node *getFront(struct Queue *queue)
{
    return queue->array[queue->front];
}

// A utility function to check if a tree node
// has both left and right children
int hasBothChild(struct node *temp)
{
    return temp && temp->left && temp->right;
}

// Function to insert a new node in complete binary tree
void insert(struct node **root, int data, struct Queue *queue)
{
    // Create a new node for given data
    struct node *temp = newNode(data);
    // If the tree is empty, initialize the root with new node.
    if (!*root)
        *root = temp;
    else
    {
        // get the front node of the queue.
        struct node *front = getFront(queue);

        // If the left child of this front node doesn’t exist, set the
        // left child as the new node
        if (!front->left)
        {
            front->left = NULL;
            front->left = temp;
        }
        // If the right child of this front node doesn’t exist, set the
        // right child as the new node
        else if (!front->right)
        {
            front->right = NULL;
            front->right = temp;
        }
        // If the front node has both the left child and right child,
        // Dequeue() it.
        if (hasBothChild(front))
        {
            Dequeue(queue);
        }
    }
    // Enqueue() the new node for later insertions
    Enqueue(temp, queue);
}

// Standard level order traversal to test above function
void levelOrder(struct node *root)
{
    struct Queue *queue = createQueue(SIZE);
    Enqueue(root, queue);
    while (!isEmpty(queue))
    {
        struct node *temp = Dequeue(queue);
        printf("%d ", temp->data);
        if (temp->left)
            Enqueue(temp->left, queue);
        if (temp->right)
            Enqueue(temp->right, queue);
    }
}

// Driver program to test above functions
int main()
{
    struct node *T1 = NULL;
    struct Queue *queue1 = createQueue(SIZE);
    int ele;

    while (1)
    {
        printf("Enter value : ");
        scanf("%d", &ele);
        if (ele == -1)
        {
            break;
        }
        else
        {
            insert(&T1, ele, queue1);
        }
    }
    inorder(T1);
    printf("\n");
    preorder(T1);
    printf("\n");
    postorder(T1);
}
