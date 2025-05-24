#include <stdio.h>
#include <stdlib.h>
#include "TreeStructure.c"
// For Queue Size
#define SIZE 50

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
};

// int hasBothChild(struct node* temp) {
// 	return temp && temp->left && temp->right;
// }

void insert(struct node **root, int data, struct Queue *queue)
{

    // Write your code here to insert a new node in complete binary tree
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    if (*root == NULL)
    {
        *root = newNode;
    }
    else
    {
        struct node *front = getFront(queue);
        if (front->left == NULL)
        {
            front->left = newNode;
        }
        else if (front->right == NULL)
        {
            front->right = newNode;
        }
        if (front->left && front->right)
        {
            Dequeue(queue); // Move to the next level
        }
    }
    Enqueue(newNode, queue);
}

void removethedeepestnode(struct node *root, struct node *d_node)
{
    struct Queue *queue = createQueue(SIZE);

    // Write your code here to insert a new node in complete binary tree
    Enqueue(root, queue);
    struct node *temp;
    while (!isEmpty(queue))
    {
        temp = Dequeue(queue);
        if (temp == d_node)
        {
            temp = NULL;
            free(d_node);
            return;
        }
        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                free(d_node);
                return;
            }
            else
            {
                Enqueue(temp->right, queue);
            }
        }
        if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left = NULL;
                free(d_node);
                return;
            }
            else
            {
                Enqueue(temp->left, queue);
            }
        }
    }
}

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

void findDeepestnode(struct node *root, struct node *search)
{
    struct Queue *queue = createQueue(SIZE);

    Enqueue(root, queue);
    struct node *temp, *par;

    while (!isEmpty(queue))
    {
        par = temp;
        temp = Dequeue(queue);

        if (temp->left)
            Enqueue(temp->left, queue);

        if (temp->right)
            Enqueue(temp->right, queue);
    }
    search->data = temp->data;
    removethedeepestnode(root, temp);
}

struct node *searchingNode(struct node *root, int data)
{
    struct Queue *queue = createQueue(SIZE);

    Enqueue(root, queue);
    struct node *searchNode = NULL;

    while (!isEmpty(queue))
    {
        struct node *temp = Dequeue(queue);
        if (temp->data == data)
        {
            searchNode = temp;
            return searchNode;
        }

        if (temp->left)
            Enqueue(temp->left, queue);

        if (temp->right)
            Enqueue(temp->right, queue);
    }
    return searchNode;
}

// Driver program to test above functions
int main()
{
    struct node *root = NULL;
    struct Queue *queue = createQueue(SIZE);
    int i;
    int limit;
    int data1;
    printf("Enter the limit to form binary tree: ");
    scanf("%d", &limit);

    for (i = 1; i <= limit; ++i)
    {
        printf("Enter node: ");
        scanf("%d", &data1);
        insert(&root, data1, queue);
    }
    printf("Level order traversal before deletion\n");
    levelOrder(root);
    int data;
    printf("\nEnter data to delete: ");
    scanf("%d", &data);

    struct node *search = searchingNode(root, data);
    if (search == NULL)
        printf("Node is not present\n");
    else
    {
        findDeepestnode(root, search);
        printf("Level order traversal after deletion\n");
        levelOrder(root);
    }
    return 0;
}
