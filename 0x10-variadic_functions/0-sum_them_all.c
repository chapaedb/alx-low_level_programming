#include <stdarg.h>

/**
 * sum_them_all - Calculates the sum of all the parameters.
 *
 * @n: The number of parameters.
 * @...: The parameters to be summed.
 *
 * Return: The sum of all the parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
    int total = 0;

    // Declare a variable to hold the information needed
    // to traverse the variable argument list
    va_list args;

    // Initialize the va_list using the last fixed parameter
    va_start(args, n);

    // Traverse the variable argument list
    for (unsigned int i = 0; i < n; ++i) {
        // Access each argument using va_arg macro
        int num = va_arg(args, int);
        total += num;
    }

    // Clean up the va_list
    va_end(args);

    return total;
}
