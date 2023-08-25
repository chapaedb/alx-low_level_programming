#include<stdio.h>
#include"lists.h"
/**
 * main - check the code
 * print_list:  prints the number of elements
 * @param j - a pointer to a list
 * Return: Always 0.
 */
size_t print_list(const list_t *j)
{
	size_t i = 0;

	while (j)
	{
		if (!j->str)
			printf("[0] (nil)\n");
		else
			printf("[%u]%s\n", j->len, j->str);
		j = j->next;
		i++;
	}
	return (i);
}
