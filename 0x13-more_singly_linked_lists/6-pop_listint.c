#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list
 * and returns the head node's data (n).
 * @head: Pointer to a pointer to the head of the list.
 *
 * Return: The data stored in the head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data = 0;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	data = temp->n;
	*head = (*head)->next;
	free(temp);

	return (data);
}
