#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 10
#include "StackOperations.c"

int main()
{
	int op, x;
	while (1)
	{
		printf("1.Push 2.Pop 3.Display 4.Is Empty 5.Peek 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			printf("Enter element : ");
			scanf("%d", &x);
			push(x);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			isEmpty();
			break;
		case 5:
			peek();
			break;
		case 6:
			exit(0);
		}
	}
}