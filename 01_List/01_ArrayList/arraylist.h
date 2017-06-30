#ifndef __ARRAY_LIST_H
# define __ARRAY_LIST_H

# define TRUE   1
# define FALSE  0

typedef struct ArrayListNodeType
{
    int data;
} ArrayListNode;

typedef struct ArrayListType
{
    int maxElementCount;
    int currentElementCount;
    ArrayListNode *pElement;
} ArrayList;

ArrayList*  createArrayList(int maxElementCount);
void    deleteArrayList(ArrayList* pList);
int     isArrayListFull(ArrayList* pList);
int     addALElement(ArrayList* pList, int position, ArrayListNode element);
int     removeALElement(ArrayList* pList, int position);
ArrayListNode* getALElement(ArrayList* pList, int position);
void    displayArrayList(ArrayList* pList);
void    clearArrayList(ArrayList* pList);
int     getArrayListLength(ArrayList* pList);

#endif
