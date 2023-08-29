#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a listint_t list.
 * @head: Pointer to a pointer to the head of the list.
 * @idx: The index at which the new node should be inserted.
 * @n: The data to be stored in the new node.
 *
 * Return: Pointer to the newly inserted node, or NULL on failure.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *current = *head;
    listint_t *temp;
    unsigned int count = 0;

    temp = malloc(sizeof(listint_t));
    if (temp == NULL)
        return NULL;

    temp->data = n;
    temp->next = NULL;

    if (idx == 0)
    {
        temp->next = *head;
        *head = temp;
        return temp;
    }

    while (current != NULL)
    {
        if (count == idx - 1)
        {
            temp->next = current->next;
            current->next = temp;
            return temp;
        }
        current = current->next;
        count++;
    }

    free(temp);
    return NULL;
}
