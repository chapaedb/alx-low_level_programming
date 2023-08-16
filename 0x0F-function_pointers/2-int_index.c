#include "function_pointers.h"
/**
 * int_index - return index place if comparison = true, else -1
 * @my_array: list
 * @size: size of elements in array
 * @cmp: pointer to func of one of the 3 in main
 * Return: 0
 */
int int_index(int *my_array, int size, int (*cmp)(int))
{
	int i;

	if (my_array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(my_array[i]))
			return (i);
	}
	return (-1);
}

