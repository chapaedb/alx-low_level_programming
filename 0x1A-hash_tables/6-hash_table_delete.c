#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *temp, *prev;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        temp = ht->array[i];
        while (temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            free(prev->key);
            free(prev->value);
            free(prev);
        }
    }

    free(ht->array);
    free(ht);
}
