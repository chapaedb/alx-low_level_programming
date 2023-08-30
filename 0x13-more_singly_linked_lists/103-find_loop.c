#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	if (head == NULL || head->next == NULL)
		return (NULL);

	listint_t *turtle = head;
	listint_t *rabbit = head;

	while (rabbit != NULL && rabbit->next != NULL)
	{
		turtle = turtle->next;
		rabbit = rabbit->next->next;

		if (turtle == rabbit)
		{
			turtle = head;
			while (turtle != rabbit)
			{
				turtle = turtle->next;
				rabbit = rabbit->next;
			}
			return (turtle);
		}
	}

	return (NULL);
}
