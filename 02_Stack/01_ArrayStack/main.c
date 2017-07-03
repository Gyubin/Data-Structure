#include <stdio.h>
#include <stdlib.h>
#include "arraystack.h"

int main(int argc, char *argv[])
{
	ArrayStack *pStack = NULL;
	ArrayStackNode *pNode = NULL;
	char value = 0;

	pStack = createArrayStack(6);
	if (pStack != NULL)
	{
		ArrayStackNode node1 = {'A'};
		ArrayStackNode node2 = {'B'};
		ArrayStackNode node3 = {'C'};
		ArrayStackNode node4 = {'D'};

		pushAS(pStack, node1);
		pushAS(pStack, node2);
		pushAS(pStack, node3);
		pushAS(pStack, node4);
		displayArrayStack(pStack);

		pNode = popAS(pStack);
		if (pNode != NULL)
		{
			printf("Pop-[%c]\n", pNode->data);
			free(pNode);
		}
		else
		{
			printf("Empty stack\n");
		}
		displayArrayStack(pStack);

		pNode = peekAS(pStack);
		if (pNode != NULL)
		{
			printf("Peek-[%c]\n", pNode->data);
		}
		else
		{
			printf("Empty stack\n");
		}
		displayArrayStack(pStack);

		deleteArrayStack(pStack);
	}
	return 0;
}
