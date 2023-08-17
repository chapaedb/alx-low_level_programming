#include <stdarg.h>
#include <stdio>

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

	va_list args;

	va_start(args, n);

	unsigned int  i;

	for (i = 0; i < n; ++i)
	{
		int num = va_arg(args, int);

		total + = num;
	}

	va_end(args);

	return (total);


