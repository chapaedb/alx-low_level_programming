#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data in a listint_t list.
 * @head: Pointer to the head of the list.
 *
 * Return: The sum of the data in the list.
 */
int sum_listint(listint_t *head)
{
    listint_t *current = head;
    int sum = 0;

    while (current != NULL)
    {
        sum += current->data;
        current = current->next;
    }

    return sum;
}
