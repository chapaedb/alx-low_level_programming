#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    int comma_flag = 0;
    hash_node_t *temp;

    if (ht == NULL)
        return;

    printf("{");

    for (i = 0; i < ht->size; i++)
    {
        temp = ht->array[i];
        while (temp != NULL)
        {
            if (comma_flag == 1)
                printf(", ");
            printf("'%s': '%s'", temp->key, temp->value);
            comma_flag = 1;
            temp = temp->next;
        }
    }

    printf("}\n");
}
