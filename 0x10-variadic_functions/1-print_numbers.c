#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - Prints numbers followed by a new line.
 *
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 * @...: The integers to be printed.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	/* Initialize the va_list using the last fixed parameter */
	va_start(args, n);

	/* Traverse the variable argument list */
	for (i = 0; i < n; ++i)
	{
		/* Access each argument using va_arg macro */
		int num = va_arg(args, int);

		printf("%d", num);

		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	/* Clean up the va_list */
	va_end(args);

	printf("\n");
}
