#ifndef __LINKEDLIST_H
# define __LINKEDLIST_H

typedef struct ListNodeType
{
    int data;
    struct ListNodeType * pLink;
} ListNode;

typedef struct LinkedListType
{
    int currentElementCount;
    ListNode headerNode;
} LinkedList;

LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);
void displayLinkedList(LinkedList* pList);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

# define TRUE   1
# define FALSE  0

#endif
