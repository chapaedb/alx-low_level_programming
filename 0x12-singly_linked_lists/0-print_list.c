#include<stdio.h>
#include"lists.h"
/**
 * print_list -  prints the number of elements.
 * @j: a pointer to a list.
 * Return: number of nodes.
 */
size_t print_list(const list_t *j)
{
	size_t i = 0;

	while (j)
	{
		if (!j->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", j->len, j->str);
		j = j->next;
		i++;
	}
	return (i);
}
