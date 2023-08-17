#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - Prints strings followed by a new line.
 *
 * @separator: The string to be printed between the strings.
 * @n: The number of strings passed to the function.
 * @...: The strings to be printed.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	/* Initialize the va_list using the last fixed parameter */
	va_start(args, n);

	/* Traverse the variable argument list */
	for (i = 0; i < n; ++i)
	{
		/* Access each argument using va_arg macro */
		str = va_arg(args, char *);

		/* Print "(nil)" if the string is NULL, otherwise print the string */
		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	/* Clean up the va_list */
	va_end(args);

	printf("\n");
}
