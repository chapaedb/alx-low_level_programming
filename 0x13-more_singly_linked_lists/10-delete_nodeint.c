#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at the given index in a listint_t list.
 * @head: Pointer to a pointer to the head of the list.
 * @index: The index of the node to be deleted (starting from 0).
 *
 * Return: 1 if successful, or -1 if the node cannot be deleted.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current = *head;
    listint_t *temp;
    unsigned int count = 0;

    if (index == 0 && *head != NULL)
    {
        *head = (*head)->next;
        free(current);
        return 1;
    }

    while (current != NULL)
    {
        if (count == index - 1)
        {
            temp = current->next;
            if (temp == NULL)
                return -1;
            current->next = temp->next;
            free(temp);
            return 1;
        }
        current = current->next;
        count++;
    }

    return -1;
}
