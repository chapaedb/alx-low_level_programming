#include"lists.h"
/**
 * list_length - Returns the number of nodes in a linked list.
 * @head: The head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t list_length(const list_t *head)
{
	size_t n = 0;
	const list_t *current = head;

	while (current != NULL)
	{
		n++;
		current = current->next;
	}

	return n;
}
