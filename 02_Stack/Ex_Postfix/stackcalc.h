#ifndef __STACK_CALC_H
# define __STACK_CALC_H

void calcExpr(ExprToken *pExprTokens, int tokenCount);
int pushLSExprToken(LinkedStack* pStack, ExprToken data);
void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount);
int inStackPrecedence(Precedence oper);
int outStackPrecedence(Precedence oper);
void printToken(ExprToken element);

#endif
