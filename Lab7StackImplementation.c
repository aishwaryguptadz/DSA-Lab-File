// a) Infix to Postfix Conversion

// Initialize an empty stack for operators and an empty postfix string.
// For each character in the infix expression:
//      If it is an operand (alphabet/number), append it to the postfix string.
//      If it is an opening parenthesis (, push it onto the stack.
//      If it is a closing parenthesis ), pop from the stack and append to postfix until an opening parenthesis ( is encountered. Discard the (.
//      If it is an operator, pop and append all operators from the stack with precedence greater than or equal to the current operator. Then push the current operator onto the stack.
// After scanning, pop all remaining operators from the stack and append to postfix.
// Return the postfix expression.

// b) Evaluation of Postfix Expression

// Create a stack to store operands (or values).
// Scan the given expression from left to right and do the following for every scanned element.
//      If the element is a number, push it into the stack.
//      If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack.
// When the expression is ended, the number in the stack is the final answer.

// c) Balancing of Paranthesis

// Initialize an empty stack.
// For each character in the expression:
//      If it is an opening bracket ((, {, [), push it onto the stack.
//      If it is a closing bracket (), }, ]):
//          Check if the stack is empty. If yes, return false.
//          Otherwise, pop the top of the stack and ensure it matches the current closing bracket. If not, return false.
// After scanning, check if the stack is empty:
//      If empty, the parentheses are balanced.
//      If not, they are unbalanced.
// Return the result.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

void push(Node **top, char value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        exit(EXIT_FAILURE);
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

char pop(Node **top)
{
    if (*top == NULL)
        exit(EXIT_FAILURE);
    Node *temp = *top;
    char value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

char peek(Node *top)
{
    if (top == NULL)
        exit(EXIT_FAILURE);
    return top->data;
}

int isEmpty(Node *top)
{
    return top == NULL;
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(const char *infix, char *postfix)
{
    Node *stack = NULL;
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(&stack, infix[i]);
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[j++] = pop(&stack);
            pop(&stack);
        }
        else if (isOperator(infix[i]))
        {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i]))
                postfix[j++] = pop(&stack);
            push(&stack, infix[i]);
        }
        i++;
    }
    while (!isEmpty(stack))
        postfix[j++] = pop(&stack);
    postfix[j] = '\0';
}

int evaluatePostfix(char *exp)
{
    Node *stack = NULL;
    for (int i = 0; exp[i]; ++i)
    {
        if (isdigit(exp[i]))
            push(&stack, exp[i] - '0');
        else
        {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            switch (exp[i])
            {
            case '+':
                push(&stack, val2 + val1);
                break;
            case '-':
                push(&stack, val2 - val1);
                break;
            case '*':
                push(&stack, val2 * val1);
                break;
            case '/':
                push(&stack, val2 / val1);
                break;
            }
        }
    }
    return pop(&stack);
}

int isBalanced(const char *exp)
{
    Node *stack = NULL;
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(&stack, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(stack))
                return 0;
            char top = pop(&stack);
            if ((exp[i] == ')' && top != '(') || (exp[i] == '}' && top != '{') || (exp[i] == ']' && top != '['))
                return 0;
        }
        i++;
    }
    return isEmpty(stack);
}

int main()
{
    char infix[100], postfix[100], exp[100];
    int choice;
    while (1)
    {
        printf("1. Convert Infix to Postfix\n2. Evaluate Postfix Expression\n3. Check Parenthesis Balancing\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Infix expression: ");
            scanf("%s", infix);
            infixToPostfix(infix, postfix);
            printf("Postfix Expression: %s\n", postfix);
            break;
        case 2:
            printf("Postfix expression: ");
            scanf("%s", postfix);
            printf("Evaluation: %d\n", evaluatePostfix(postfix));
            break;
        case 3:
            printf("Enter the expression: ");
            scanf("%s", exp);
            if (isBalanced(exp))
                printf("Balanced.\n");
            else
                printf("Not balanced.\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}