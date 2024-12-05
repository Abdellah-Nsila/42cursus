#include <stdio.h>
#include <stdarg.h>

// variadic function
int sumNumbers(int n, ...)
{
    va_list ap; // ap => argument pointer
    int i;
    int sum;

    printf("1 ap: %d\n", *ap);
    va_start(ap, n);
    printf("2 ap: %p\n", *ap);
    printf("&n: %p\n", &n);
    i = -1;
    sum = 0;
    while(++i < n)
        sum += va_arg(ap, int);
    va_end(ap);
    return (sum);
}

int main()
{
    int result;

    result = sumNumbers(3, 10, 5, 5); // variable number of argument
    printf("Result: %d\n", result);
}