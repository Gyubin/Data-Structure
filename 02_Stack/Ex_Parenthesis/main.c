#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"
#include "stackutil.h"

int main(int argc, char *argv[])
{
	char sourceStr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rightExprStr[] = "((A * B) / C) - {(D + E) && (F - G)}";
	char wrongExprStr[] = "((A * B) / C - {(D + E) && (F - G))}";
	int checkResult = 0;

	char *pReverseStr = reverseString(sourceStr);
	if (pReverseStr != NULL)
	{
		printf("[%s] => [%s]\n", sourceStr, pReverseStr);
		free(pReverseStr);
	}

	checkResult = checkBracketMatching(rightExprStr);
	if (checkResult == TRUE)
	{
		printf("SUCCESS, %s\n", rightExprStr);
	}
	else
	{
		printf("FAIL, %s\n", rightExprStr);
	}

	checkResult = checkBracketMatching(wrongExprStr);
	if (checkResult == TRUE)
	{
		printf("FAIL, %s\n", wrongExprStr);
	}
	else
	{
		printf("SUCCESS, %s\n", wrongExprStr);
	}

	return 0;
}
