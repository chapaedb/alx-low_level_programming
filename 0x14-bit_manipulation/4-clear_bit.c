#include"main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the unsigned long int where the bit will be cleared.
 * @index: The index of the bit to be cleared, starting from 0.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;
	if (index >= (sizeof(unsigned long int) * 8))
	{
		/* Error: Invalid index */
		return (-1);
	}

	mask = ~(1UL << index);
	*n &= mask;

	/* Success */
	return (1);
}
