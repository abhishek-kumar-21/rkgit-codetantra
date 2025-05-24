struct node
{
    int data;
    struct node *left, *right;
};
typedef struct node *BSTNODE;
BSTNODE newNodeInBST(int item)
{
    BSTNODE temp = (BSTNODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorderInBST(BSTNODE root)
{
    if (root != NULL)
    {
        inorderInBST(root->left);
        printf("%d ", root->data);
        inorderInBST(root->right);
    }
}
void preorderInBST(BSTNODE root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderInBST(root->left);
        preorderInBST(root->right);
    }
}
void postorderInBST(BSTNODE root)
{
    if (root != NULL)
    {
        postorderInBST(root->left);
        postorderInBST(root->right);
        printf("%d ", root->data);
    }
}
BSTNODE insertNodeInBST(BSTNODE node, int ele)
{
    if (node == NULL)
    {
        printf("Successfully inserted.\n");
        return newNodeInBST(ele);
    }
    if (ele < node->data)
        node->left = insertNodeInBST(node->left, ele);
    else if (ele > node->data)
        node->right = insertNodeInBST(node->right, ele);
    else
        printf("Element exists in BST.\n");
    return node;
}
BSTNODE searchNodeInBST(BSTNODE root, int ele)
{
    if (root == NULL || root->data == ele)
    {
        return root;
    }
    if (ele < root->data)
    {
        return searchNodeInBST(root->left, ele);
    }
    else
    {
        return searchNodeInBST(root->right, ele);
    }
}