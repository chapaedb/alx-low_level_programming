#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data (n).
 * @head: Pointer to the head of the list.
 *
 * Return: The sum of the data in the list, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	listint_t *current = head;
	int sum = 0;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
