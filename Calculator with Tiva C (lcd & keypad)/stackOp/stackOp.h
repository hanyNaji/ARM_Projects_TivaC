/*
 * stackOp.h
 *
 *  Created on: Aug 19, 2023
 *      Author: hany nagy
 */

#ifndef STACKOP_STACKOP_H_
#define STACKOP_STACKOP_H_

/* Maximum size for the stack */
#define MAX_SIZE 100

/* Structure to represent a stack */
typedef struct {
    char data[MAX_SIZE]; // Data array to hold stack elements
    int top;             // Index of the top element in the stack
} Stack;

/* Function Prototypes */

/**
 * @brief Initializes a stack by setting the top index to -1.
 */
void initialize(Stack *stack);

/**
 * @brief Pushes a value onto the stack.
 */
void push(Stack *stack, char value);

/**
 * @brief Pops and returns the top element from the stack.
 */
char pop(Stack *stack);

/**
 * @brief Returns the top element of the stack without popping it.
 */
char peek(Stack *stack);

/**
 * @brief Checks if a character is an operator (+, -, *, /).
 *
 * @return 1 if the character is an operator, 0 otherwise.
 */
int isOperator(char ch);

/**
 * @brief Returns the precedence level of an operator.
 */
int getPrecedence(char op);

/**
 * @brief Converts an infix expression to a postfix expression using a stack.
 */
void infixToPostfix(char *infix, char *postfix);

/**
 * @brief Evaluates a postfix expression using a stack.
 */
int evaluatePostfix(const char *postfix);

#endif /* STACKOP_STACKOP_H_ */
