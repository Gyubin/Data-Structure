#ifndef __ARRAY_STACK_H
# define __ARRAY_STACK_H

# define TRUE       1
# define FALSE      0

typedef struct ArrayStackNodeType {
    char data;
} ArrayStackNode;

typedef struct ArrayStackType {
    int maxElementCount;
    int currentElementCount;
    ArrayStackNode *pElement;
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushAS(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* popAS(ArrayStack* pStack);
ArrayStackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);
void displayArrayStack(ArrayStack *pStack);

#endif
