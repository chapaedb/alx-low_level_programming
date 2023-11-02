#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created hash table,
 *         or NULL if something went wrong.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *ht;
    unsigned long int i;

    if (size == 0)
        return NULL;

    /* Allocate memory for the hash table structure */
    ht = malloc(sizeof(hash_table_t));
    if (ht == NULL)
        return NULL;

    /* Allocate memory for the array of hash_node_t pointers */
    ht->array = malloc(sizeof(hash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return NULL;
    }

    /* Initialize each element of the array to NULL */
    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->size = size;

    return ht;
}
