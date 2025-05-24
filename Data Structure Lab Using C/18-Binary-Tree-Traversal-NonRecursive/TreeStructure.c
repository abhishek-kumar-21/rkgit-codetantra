// A tree node
struct node
{
    int data;
    struct node *right, *left;
    struct node *root;
};

// A queue node
struct Queue
{
    int front, rear;
    int size;
    struct node **array;
};

// A utility function to create a new tree node

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

typedef struct node *BTNODE;

struct stacknode
{
    BTNODE node;
    struct stacknode *next;
};

typedef struct stacknode *STKNODE;
STKNODE top = NULL;
int isempty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
