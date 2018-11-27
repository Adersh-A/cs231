#include <stdio.h>
#include <stdlib.h>
int power(int base, int exponent) {
  if (exponent==1) {
    return 1;
  } else {
    return base*power(base, exponent-1);
  }
}
int evaluvate(int operand1, int operator, int operand2) {
  switch(operator) {
    case '+':
      return (operand1+operand2);
    case '-':
      return (operand1-operand2);
    case '*':
      return (operand1*operand2);
    case '/':
      return (operand1/operand2);
    case '^':
      return (power(operand1, operand2));
    default:
      printf("Invalid operator");
      exit(0);
  }
}
int isOperand(char symbol) {
  if ((symbol>=48 && symbol<=57)) {
    return 1;
  }
  return 0;
}
int main() {
  char postfix[20];
  int stack[100];
  int i, top=-1, x, y;
  printf("Enter the postfix expression : ");
  scanf(" %s", postfix);
  for (i=0; postfix[i] != '\0'; i++) {
    if (isOperand(postfix[i])) {
      stack[++top] = postfix[i]-48;
    } else {
      y = stack[top--];
      x = stack[top];
      stack[top] = evaluvate(x, postfix[i], y);
    }
  }
  printf("%d\n", stack[top]);
}
