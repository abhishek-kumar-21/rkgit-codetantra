#include <stdio.h>
#include <stdlib.h>
#include "InsertAndTraversals.c"

void main()
{
    int x, op;
    BSTNODE root = NULL;
    while (1)
    {
        printf("1.Insert 2.Inorder Traversal 3.Preorder Traversal 4.Postorder Traversal 5.Search an element 6.Exit\n");
        printf("Enter your option: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter an element to be inserted : ");
            scanf("%d", &x);
            root = insertNodeInBST(root, x);
            break;
        case 2:
            if (root == NULL)
            {
                printf("Binary Search Tree is empty.\n");
            }
            else
            {
                printf("Elements of the BST (in-order traversal): ");
                inorderInBST(root);
                printf("\n");
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("Binary Search Tree is empty.\n");
            }
            else
            {
                printf("Elements of the BST (pre-order traversal): ");
                preorderInBST(root);
                printf("\n");
            }
            break;
        case 4:
            if (root == NULL)
            {
                printf("Binary Search Tree is empty.\n");
            }
            else
            {
                printf("Elements of the BST (post-order traversal): ");
                postorderInBST(root);
                printf("\n");
            }
            break;
        case 5:
            printf("Enter an element to be searched : ");
            scanf("%d", &x);
            if (searchNodeInBST(root, x) == NULL)
                printf("Element not found in the binary search tree.\n");
            else
                printf("Element found in the binary search tree.\n");
            break;
        case 6:
            exit(0);
        }
    }
}