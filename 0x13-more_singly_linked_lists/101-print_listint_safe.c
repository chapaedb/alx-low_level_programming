#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *temp = head, *checker = head;

	while (temp != NULL)
	{
		printf("[%p] %d\n", (void *)temp, temp->n);
		count++;

		temp = temp->next;

		if (temp >= checker)
		{
			printf("-> [%p] %d\n", (void *)temp, temp->n);
			break;
		}

		checker = checker->next;
	}

	return (count);
}
