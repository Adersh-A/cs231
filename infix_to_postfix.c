#include <stdio.h>

int instackPriority(char symbol) {
  switch(symbol) {
    case '+':
    case '-':
      return 2;
    case '*':
    case '/':
      return 4;
    case '^':
      return 6;
    case '(':
      return 0;
  }
}
int incomingPriority(char symbol) {
  switch(symbol) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 3;
    case '^':
      return 5;
  }
}
int isOperand(char symbol) {
  if ((symbol>=97 && symbol<=122) || (symbol>=65 && symbol<=90)) {
    return 1;
  }
  return 0;
}
int main () {
  char infix[20], stack[100];
  int i, top=-1;
  printf("Enter the infix expression : ");
  scanf(" %s", infix);
  for (i=0; infix[i] != '\0'; i++) {
    if (isOperand(infix[i])) {
      printf("%c", infix[i]);
    } else if (infix[i] == '(') {
      stack[++top] = infix[i];
    } else if (infix[i] == ')') {
      while (stack[top] != '(') {
        printf("%c", stack[top--]);
      }
      top--;
    } else if (instackPriority(stack[top])>incomingPriority(infix[i])) {
      while (instackPriority(stack[top])>incomingPriority(infix[i]) && top>-1) {
        printf("%c", stack[top--]);
      }
      stack[++top] = infix[i];
    } else {
      stack[++top] = infix[i];
    }
  }
  while (top > -1) {
    printf("%c", stack[top--]);
  }
}
