/*
 * stackOp.h
 *
 *  Created on: Aug 19, 2023
 *      Author: hanyt
 */

#ifndef STACKOP_STACKOP_H_
#define STACKOP_STACKOP_H_


#define MAX_SIZE 100


typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack);
void push(Stack *stack, char value);
char pop(Stack *stack);
char peek(Stack *stack);



int isOperator(char ch);

int getPrecedence(char op);

void infixToPostfix(char *infix, char *postfix);

// Evaluate postfix expression
int evaluatePostfix(const char *postfix);




#endif /* STACKOP_STACKOP_H_ */
