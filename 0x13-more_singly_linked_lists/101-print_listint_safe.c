#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;
	listint_t *loop_node = find_listint_loop((listint_t *)head);

	if (loop_node == NULL)
	{
		while (current != NULL)
		{
			count++;
			printf("[%p] %d\n", (void *)current, current->n);
			current = current->next;
		}
	}
	else
	{
		while (current != loop_node)
		{
			count++;
			printf("[%p] %d\n", (void *)current, current->n);
			current = current->next;
		}
		printf("-> [%p] %d\n", (void *)current, current->n);
	}

	return (count);
}
