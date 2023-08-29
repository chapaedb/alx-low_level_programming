#include "lists.h"

/**
 * get_nodeint_at_index - Returns the node at the given index.
 * @head: Pointer to the head of the list.
 * @index: The index of the desired node (starting from 0).
 *
 * Return: Pointer to the node at the given index, or NULL if it doesn't exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	size_t count = 0;

	while (current != NULL)
	{
		if (count == index)
			return (current);

		current = current->next;
		count++;
	}

	return (NULL);
}
