#ifndef __CIRCULARLIST_H
# define __CIRCULARLIST_H

typedef struct CircularListNodeType
{
    int data;
    struct CircularListNodeType* pLink;
} CircularListNode;

typedef struct CircularListType
{
    int currentElementCount;
    CircularListNode* pLink;
} CircularList;

CircularList* createCircularList();
void deleteCircularList(CircularList* pList);
int addCLElement(CircularList* pList, int position, CircularListNode element);
int removeCLElement(CircularList* pList, int position);
void clearCircularList(CircularList* pList);
int getCircularListLength(CircularList* pList);
CircularListNode* getCLElement(CircularList* pList, int position);
void displayCircularList(CircularList* pList);

# define TRUE		1
# define FALSE		0

#endif
