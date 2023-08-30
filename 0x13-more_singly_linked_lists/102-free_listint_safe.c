#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t list, even if it contains a loop.
 * @h: Pointer to a pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current = *h;
	listint_t *temp = NULL;

	while (current != NULL)
	{
		count++;
		if (current->next >= current)
		{
			temp = current->next;
			break;
		}
		temp = current->next;
		free(current);
		current = temp;
	}

	*h = NULL;

	return (count);
}
