#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define TREENODES 100
#define FALSE 0
struct tree
{
    int info;
    int used;
};
struct tree node[TREENODES];
void Createtree();
void Insert(int);
void Display();
void Setleft(int, int);
void Setright(int, int);

void Createtree(int x)
{
    int i;
    node[0].info = x;
    node[0].used = TRUE;
    for (i = 1; i < TREENODES; i++)
        node[i].used = FALSE;
}

void Insert(int x)
{
    int i = 0;
    while (i < TREENODES)
    {
        if (!node[i].used)
        {
            node[i].info = x;
            node[i].used = TRUE;
            // printf("%d inserted successfully\n",x);
            return;
        }
        else if (x == node[i].info)
        {
            printf("%d is a duplicate number\n");
            return;
        }
        else if (x < node[i].info)
        {
            i = 2 * i + 1;
        }
        else
        {
            i = 2 * i + 2;
        }
    }
    printf("No more space for new node\n");
}

void Setleft(int pos, int x)
{
    int q;
    q = 2 * pos + 1;
    if (q > TREENODES)
        printf("Array overflow.");
    else if (node[q].used == TRUE)
        printf("Invalid insertion.");
    else
    {
        node[q].info = x;
        node[q].used = TRUE;
    }
}

void Setright(int pos, int x)
{
    int q;
    q = 2 * pos + 2;
    if (q > TREENODES)
        printf("Array overflow.");
    else if (node[q].used == TRUE)
        printf("Invalid insertion.\n");
    else
    {
        node[q].info = x;
        node[q].used = TRUE;
    }
}

void Display()
{
    for (int i = 0; i < TREENODES; i++)
    {
        if (node[i].used)
        {
            printf("%d ", node[i].info);
        }
    }
    printf("\n");
}
void main()
{
    int x, y;
    char ch = '1';
    printf("Enter root node value:");
    scanf("%d", &x);
    Createtree(x);
    while (ch != '3')
    {
        printf("1.Insert\n2.Display\n3.Quit\nEnter your choice: ");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            printf("Enter the element to be inserted:");
            scanf("%d", &x);
            Insert(x);
            break;
        case 2:
            Display();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Out of Range...!\n");
            break;
        }
    }
}
