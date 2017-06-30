#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main(int argc, char *argv[])
{
    int i = 0;
    int arrayCount = 0;
    ArrayList *pList = NULL;
    ArrayListNode *pValue = NULL;

    pList = createArrayList(6);
    if (pList != NULL)
    {
        ArrayListNode node;
        node.data = 1;
        addALElement(pList, 0, node);
        node.data = 3;
        addALElement(pList, 1, node);
        node.data = 5;
        addALElement(pList, 2, node);
        displayArrayList(pList);

        removeALElement(pList, 0);
        displayArrayList(pList);

        arrayCount = getArrayListLength(pList);
        for(i = 0; i < arrayCount; i++)
        {
            pValue = getALElement(pList, i);
            printf("position[%d]-%d\n", i, pValue->data);
        }
        deleteArrayList(pList);
    }
    return 0;
}
