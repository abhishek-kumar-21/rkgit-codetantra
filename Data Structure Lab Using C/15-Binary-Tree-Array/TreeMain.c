#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updateElement(char *tree, int arraySize, char s, char t)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (tree[i] == s)
        {
            tree[i] = t;
        }
    }
}
int setRoot(int dataKey, char *tree)
{
    if (tree[0] != '\0')
        printf("Root is already\n");
    else
        tree[0] = dataKey;
    return 0;
}

int addLeft(char dataKey, int parentIndex, char *tree)
{
    if (tree[parentIndex] == '\0')
        printf("No parent found\n");
    else
        tree[(parentIndex * 2) + 1] = dataKey;
    return 0;
}

int addRight(char dataKey, int parentIndex, char *tree)
{
    if (tree[parentIndex] == '\0')
        printf("No parent found\n");
    else
        tree[(parentIndex * 2) + 2] = dataKey;
    return 0;
}

int displayTree(char *tree, int arraySize)
{

    // write your code here to display the tree.
    for (int i = 0; i < arraySize; i++)
    {
        if (tree[i] != '\0')
            printf("%c ", tree[i]);
    }
    return 0;
}

int deleteNode(char *tree, char dataKey, int arraySize)
{

    // write your code here to delete node and replace it with rightmost node in our constructed binary tree.
    int k, l;
    char lastNode;
    for (int i = 0; i < arraySize; i++)
    {
        if (tree[i] == dataKey)
            k = i;
        if (tree[i] != '\0')
            l = i;
    }
    tree[k] = tree[l];
    tree[l] = '\0';
}
// Driver Code
int main()
{
    char *tree;
    char ch, choice, delNode;
    printf("Enter the number of nodes: ");
    int n, index;
    scanf("%d", &n);
    int height = round(log2(n) + 1);
    printf("height: %d\n", height);
    int arraySize = pow(2, height) - 1;
    tree = (char *)malloc(arraySize * sizeof(char));
    memset(tree, '\0', sizeof(char *) * arraySize);
    printf("Enter the data key in root node: ");
    scanf(" %c", &ch);
    setRoot(ch, tree);
    if (n > 1)
    {
        printf("Enter rest of the nodes in the binary tree: \n");
        for (int i = 1; i < n; i++)
        {
            printf("Enter R or r for right and L or l for left side insertion: ");
            scanf(" %c", &choice);
            if (choice == 'R' || choice == 'r')
            {
                printf("Enter datakey and parent index: ");
                scanf(" %c", &ch);
                scanf("%d", &index);
                addRight(ch, index, tree);
            }
            else
            {
                printf("Enter datakey and parent index: ");
                scanf(" %c", &ch);
                scanf("%d", &index);
                addLeft(ch, index, tree);
            }
        }
    }
    printf("Binary tree is:\n");
    displayTree(tree, arraySize);
    printf("\nEnter the data element you want to update: ");
    char s, t;
    scanf(" %c", &s);
    scanf(" %c", &t);
    updateElement(tree, arraySize, s, t);
    printf("Binary tree is:\n");
    displayTree(tree, arraySize);

    printf("\nEnter DeleteNode: ");
    scanf(" %c", &delNode);
    deleteNode(tree, delNode, arraySize);
    printf("Tree after deletion\n");
    displayTree(tree, arraySize);
    return 0;
}