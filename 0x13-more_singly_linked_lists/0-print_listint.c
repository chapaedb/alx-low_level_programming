#include "lists.h"

/**
 * print_listint - Prints all the elements of a linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: Number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
    size_t count = 0; // Variable to keep track of the number of nodes

    while (h != NULL) // Traverse the list until the end is reached
    {
        printf("%d\n", h->n); // Print the value of the current node
        count++; // Increment the count
        h = h->next; // Move to the next node
    }

    return (count); // Return the total number of nodes
}
