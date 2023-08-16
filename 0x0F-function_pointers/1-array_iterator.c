#include <stdio.h>
#include "function_pointers.h"
/**
 * array_iterator - prints array elements on a new line
 * @my_array: array
 * @size: the number of elemnts to  print
 * @action: pointer to print in regular or hex
 * Return: does not return anything
 */
void array_iterator(int *my_array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (my_array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(my_array[i]);
	}
}

