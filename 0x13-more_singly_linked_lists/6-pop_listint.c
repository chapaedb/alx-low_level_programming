#include "lists.h"

/**
 * pop_listint - Removes the head node of a listint_t list.
 * @head: Pointer to a pointer to the head of the list.
 *
 * Return: The data stored in the head node.
 */
int pop_listint(listint_t **head)
{
    listint_t *temp;
    int data = 0;

    if (head == NULL || *head == NULL)
        return 0;

    temp = *head;
    data = temp->data;
    *head = (*head)->next;
    free(temp);

    return data;
}
