#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left, *right;
};

// Creation
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder Traversal using recursion
void inorder(struct node *root)
{
    if (root != NULL)
    {
        // Traverse left
        inorder(root->left);
        // Traverse root
        printf("%d ", root->key);
        // Traverse right
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        // Traverse left
        printf("%d ", root->key);
        preorder(root->left);
        // Traverse right
        preorder(root->right);
    }
}
// Find the inorder successor
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Insert a node in BST
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver code
int main()
{
    struct node *root = NULL;
    int n, data;
    printf("Enter how many nodes you want to insert in BST :");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value: ");
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Inorder traversal(Always gives ascending order): ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nEnter the data to delete: ");
    scanf("%d", &data);

    printf("After deleting %d\n", data);
    root = deleteNode(root, data);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
}
