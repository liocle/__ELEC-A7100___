/* In this task, you will learn how to use conditional statements and formatted
 * input and output using scanf and printf. You are required to implement
 * simple_math function that fulfills the following requirements.
 *  1. The function is declared in source.h as
 *      void simple_math(void);
 *  2. Implement the function definition in source.c.
 *  3. The function should expect the user input in the form
 *      <number><space><operator><space><number>
 *      where
 *      <number>
 *        is a float type floating point number.
 *      <operator>
 *        is one of '+', '-', '*' or '/' characters corresponding to the basic
 *        mathematical operators.
 *      <space>
 *        is the space character ' '.
 *  4. If the user entry is not in the expected format, the function should print
 *      ERR
 *  5. If the user enters any other operator than the above stated ones, the function
 *     should print
 *      ERR
 *  6. If the user enters the required input, the function performs the stated
 *     operation on the stated numbers and prints the result with a precision of
 *     a single decimal.
 * An example call of the function is shown below. The input from the user is marked with
 * an @ sign:
 *  @  8 - 2
 *     6.0
 *  @  5 * 5
 *     25.0
 *  @  8.3 / 5.1
 *     1.6
 *  @  2.2 / 0
 *     ERR
 *  @  -3.456 - 2.31
 *     -5.8
 *  @  2.45 : 1.0
 *     ERR
 *  @  * 2.0
 *     ERR
 * Hint
 * - Check the scanf function documentation (http://www.cplusplus.com/reference/cstdio/scanf/)
 * - how does it treat the white-space characters?
 * - how does it treat the non-white-space characters except format specifier?
 * - how does it read the input corresponding to a format specifier?
 * - what is the format specifier for a floating point number?
 * - what is the format specifier for a character constant?
 */

#include "source.h"

#include <math.h>
#include <stdio.h>

void simple_math(void)
{
    float   operand_1;
    float   operand_2;
    char    operator;
    int   space;

    space = scanf("%f %c %f", &operand_1, &operator, &operand_2);
    
    if (space != 3)
        {
        printf("ERR\n");
        return;
        }

    switch(operator)
    {
        case '+':
            printf("%.1f\n", operand_1 + operand_2);
            break;
        case '-':
            printf("%.1f\n", operand_1 - operand_2);
            break;
        case '*':
            printf("%.1f\n", operand_1 * operand_2);
            break;
        case '/':
            if (operand_2 == 0)
                printf("ERR");
            else
                printf("%.1f\n", operand_1 / operand_2);
            break;
        default: 
            printf("ERR\n");
            break;
    }

}
