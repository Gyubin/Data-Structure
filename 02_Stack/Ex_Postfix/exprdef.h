#ifndef __EXPR_DEF_H
# define __EXPR_DEF_H

typedef enum PrecedenceType {
	lparen, rparen, times, divide, plus, minus, operand
} Precedence;

typedef struct ExprTokenType {
	float value;
	Precedence type;
} ExprToken;

#endif
