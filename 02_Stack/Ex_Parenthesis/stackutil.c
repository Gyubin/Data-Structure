#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"
#include "stackutil.h"

char* reverseString(char* src)
{
    LinkedStack *stack = NULL;
    StackNode *pNode = NULL;
    char* result = NULL;
    int i = 0;
    int size = 0;

    if (src == NULL)
    {
        return NULL;
    }

    size = strlen(src);
    if (size == 0)
    {
        return NULL;
    }

    result = (char *)malloc(sizeof(char) * (size + 1));
    if (result == NULL)
    {
        printf("malloc error\n");
        return NULL;
    }

    stack = createLinkedStack();
    if (stack != NULL)
    {
        StackNode node;
        for (i = 0; i < size; i++)
        {
            node.data = src[i];
            pushLS(stack, node);
        }

        for (i = 0; i < size; i++)
        {
            pNode = popLS(stack);
            if (pNode != NULL)
            {
                result[i] = pNode->data;
                free(pNode);
            }
        }
        result[i] = '\0';
        deleteLinkedStack(stack);
    }
    else
    {
        free(result);
        result = NULL;
    }
    return result;
}

int checkBracketMatching(char *src)
{
    LinkedStack *pStack = NULL;
    StackNode *pNode = NULL;
    StackNode node;
    int size = 0;
    int i = 0;
    int ret = TRUE;

    if (src == NULL)
    {
        return ret;
    }

    size = strlen(src);
    if (size == 0)
    {
        return ret;
    }

    pStack = createLinkedStack();
    if (pStack != NULL)
    {
        for (i = 0; i < size && ret == TRUE; i++)
        {
            if (src[i] == '('
            || src[i] == '['
            || src[i] == '{')
            {
                node.data = src[i];
                pushLS(pStack, node);
            }
            else if (src[i] == ')'
            || src[i] == ']'
            || src[i] == '}')
            {
                pNode = popLS(pStack);
                if (pNode == NULL)
                {
                    ret = FALSE;
                    break;
                }
                if ((src[i] == ')' && pNode->data == '(')
                || (src[i] == ']' && pNode->data == '[')
                || (src[i] == '}' && pNode->data == '{'))
                {
                    free(pNode);
                }
                else
                {
                    free(pNode);
                    ret = FALSE;
                    break;
                }
            }
        }
        if (isLinkedStackEmpty(pStack) == FALSE)
        {
            ret = FALSE;
        }
        deleteLinkedStack(pStack);
    }
    else
    {
        printf("Error in createLinkedStack");
        ret = FALSE;
    }
    return ret;
}
