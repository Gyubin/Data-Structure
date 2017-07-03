#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

ArrayStack* createArrayStack(int size)
{
	ArrayStack *pReturn = NULL;
	int i = 0;

	if (size > 0)
	{
		pReturn = (ArrayStack *)malloc(sizeof(ArrayStack));
		if (pReturn != NULL)
		{
			memset(pReturn, 0, sizeof(ArrayStack));
			pReturn->maxElementCount = size;
		}
		else
		{
			printf("malloc error\n");
			return NULL;
		}

		pReturn->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * size);
		if (pReturn->pElement != NULL)
		{
			memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * size);
		}
		else
		{
			printf("malloc error\n");
			free(pReturn); return NULL;
		}
	}
	else
	{
		printf("Stack size error\n");
		return NULL;
	}

	return pReturn;
}

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	int ret = FALSE, i=0;

	if (pStack != NULL)
	{
		if (isArrayStackFull(pStack) == FALSE)
		{
			pStack->pElement[pStack->currentElementCount] = element;
			pStack->currentElementCount++;
			ret = TRUE;
		}
		else
		{
			printf("Error: Stack is full\n");
		}
	}

	return ret;
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
	ArrayStackNode* pReturn = NULL;
	if (pStack != NULL)
	{
		if (isArrayStackEmpty(pStack) == FALSE)
		{
			pReturn = (ArrayStackNode *)malloc(sizeof(ArrayStackNode));
			if (pReturn != NULL)
			{
				*pReturn = pStack->pElement[pStack->currentElementCount - 1];
				pStack->currentElementCount--;
			}
			else
			{
				printf("malloc error\n");
			}
		}
	}

	return pReturn;
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
	ArrayStackNode* pReturn = NULL;
	if (pStack != NULL)
	{
		if (isArrayStackEmpty(pStack) == FALSE)
		{
			pReturn = &(pStack->pElement[pStack->currentElementCount - 1]);
		}
	}

	return pReturn;
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (pStack != NULL)
	{
		if (pStack->pElement != NULL)
		{
			free(pStack->pElement);
		}
		free(pStack);
	}
}

int isArrayStackFull(ArrayStack* pStack)
{
	int ret = FALSE;

	if (pStack != NULL)
	{
		if (pStack->currentElementCount == pStack->maxElementCount)
		{
			ret = TRUE;
		}
	}

	return ret;
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	int ret = FALSE;

	if (pStack != NULL)
	{
		if (pStack->currentElementCount == 0)
		{
			ret = TRUE;
		}
	}

	return ret;
}

void displayArrayStack(ArrayStack *pStack)
{
	int i = 0;
	if (pStack != NULL)
	{
		int size = pStack->maxElementCount;
		int top = pStack->currentElementCount;

		printf("Stack size: %d, Cur el count: %d\n",
				pStack->maxElementCount,
				pStack->currentElementCount);

		for(i = size - 1; i >= top; i--)
		{
			printf("[%d]-[Empty]\n", i);
		}

		for(i = top - 1; i >= 0 ; i--)
		{
			printf("[%d]-[%c]\n",
				i, pStack->pElement[i].data);
		}
	}
}
