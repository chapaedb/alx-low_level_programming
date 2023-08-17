#include <stdarg.h>
#include <stdio.h>

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
	va_list args;
	int total = 0;
	unsigned int i;

	va_start(args, n);

	if (n == 0)
		return (0);

	for (i = 0; i < n; ++i)
	{
		int num = va_arg(args, int);

		total += num;
	}

	va_end(args);

	return (total);

}
