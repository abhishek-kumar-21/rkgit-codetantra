void push(BTNODE b)
{
    STKNODE temp;
    temp = (STKNODE)malloc(sizeof(struct stacknode));
    if (temp == NULL)
    {
        printf("Stack is overflow.\n");
    }
    else
    {
        temp->node = b;
        temp->next = top;
        top = temp;
    }
}
BTNODE peek()
{
    if (top == NULL)
    {
        return NULL;
    }
    return top->node;
}
BTNODE pop()
{
    STKNODE temp;
    BTNODE b;
    if (top == NULL)
    {
        printf("Stack is underflow.\n");
        return 0;
    }
    else
    {
        temp = top;
        top = top->next;
        b = temp->node;
        free(temp);
        return b;
    }
}

STKNODE newStackNode(BTNODE b)
{
    STKNODE temp = (STKNODE)malloc(sizeof(struct node));
    temp->node = b;
    temp->next = NULL;
    return temp;
}
BTNODE newNodeInBT(int item)
{
    BTNODE temp = (BTNODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(BTNODE root)
{
    BTNODE current = root;
    printf("Inorder: ");
    while (current != NULL || top != NULL)
    {
        while (current != NULL)
        {
            push(current);
            current = current->left;
        }
        current = pop();
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

void preorder(BTNODE root)
{
    if (root == NULL)
    {
        return;
    }
    push(root);
    printf("Preorder: ");
    while (top != NULL)
    {
        BTNODE current = pop();
        printf("%d ", current->data);
        if (current->right != NULL)
        {
            push(current->right);
        }
        if (current->left != NULL)
        {
            push(current->left);
        }
    }
    printf("\n");
}

void postorder(BTNODE root)
{
    if (root == NULL)
    {
        return;
    }
    push(root);
    BTNODE prev = NULL;
    printf("Postorder: ");
    while (top != NULL)
    {
        BTNODE current = peek();
        if (prev == NULL || prev->left == current || prev->right == current)
        {
            if (current->left != NULL)
            {
                push(current->left);
            }
            else if (current->right != NULL)
            {
                push(current->right);
            }
            else
            {
                pop();
                printf("%d ", current->data);
            }
        }
        else if (current->left == prev)
        {
            if (current->right != NULL)
            {
                push(current->right);
            }
            else
            {
                pop();
                printf("%d ", current->data);
            }
        }
        else if (current->right == prev)
        {
            pop();
            printf("%d ", current->data);
        }
        prev = current;
    }
    printf("\n");
}
