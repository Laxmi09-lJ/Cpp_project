//Develop a calculator program that performs basic arithmetic operations such as addition, subtraction, multiplication, and division.
//Allow the user to input two numbers and choose an operation to perform.

// C Program to implement a Simple Calculator 
// using if-else statements

#include <float.h>
#include <stdio.h>

int main() {
    char op;
    double a, b, res;

    // Read the operator
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &op);

    // Read the two numbers
    printf("Enter two operands: ");
    scanf("%lf %lf", &a, &b);

    // Perform the operation corresponding to the
    //  given operator
    if (op == '+')
        res = a + b;
    else if (op == '-')
        res = a - b;
    else if (op == '*')
        res = a * b;
    else if (op == '/')
        res = a / b;
    else {
        printf("Error! Operator is not correct.\n");
        res = -DBL_MAX;
    }
  
    if (res != -DBL_MAX)
        printf("Result: %.2lf\n", res);

    return 0;
}