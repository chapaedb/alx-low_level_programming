#include "hash_tables.h"

/**
 * hash_djb2 - Hash function implementing the djb2 algorithm.
 * @str: The string to hash.
 *
 * Return: The calculated hash.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash_value = 5381;
    int character;

    while ((character = *str++)) {
        hash_value = ((hash_value << 5) + hash_value) + character; /* hash * 33 + c */
    }

    return hash_value;
}
