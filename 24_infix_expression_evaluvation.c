#include <stdio.h>
#include <stdlib.h>
int power(int base, int exponent) {
  if (exponent==1) {
    return 1;
  } else {
    return base*power(base, exponent-1);
  }
}
int priority(char symbol) {
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
int evaluvate(int operand1, char operator, int operand2) {
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
      printf("Invalid operator: %c", operator);
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
  char infix[20], operator, currentChar;
  int operatorStack[100], operandStack[100];
  int i, operatorTop=-1, operandTop=-1, x, y;
  printf("Enter the infix expression : ");
  scanf(" %s", infix);
  
  for (i=0; infix[i] != '\0'; i++) {
    currentChar = infix[i];
    if (isOperand(currentChar)) {
      operandStack[++operandTop] = (int)(currentChar-'0');
    } else if (currentChar == '(') {
      operatorStack[++operatorTop] = currentChar;
    } else if (currentChar == ')') {
      while (operatorStack[operatorTop] != '(') {
        operator = operatorStack[operatorTop--];
        y = operandStack[operandTop--];
        x = operandStack[operandTop];
        operandStack[operandTop] = (int)(evaluvate(x, operator, y));
      }
      operatorTop--;
    } else {
      while (priority(operatorStack[operatorTop]) >= priority(currentChar)) {
        operator = operatorStack[operatorTop--];
        y = operandStack[operandTop--];
        x = operandStack[operandTop];
        operandStack[operandTop] = (int)(evaluvate(x, operator, y));
      }
      operatorStack[++operatorTop] = currentChar;
    }
  }
  while (operatorTop > -1) {
    operator = operatorStack[operatorTop--];
    y = operandStack[operandTop--];
    x = operandStack[operandTop];
    operandStack[operandTop] = (int)(evaluvate(x, operator, y));
  }
  printf("Final result : %d\n", operandStack[0]);
}
