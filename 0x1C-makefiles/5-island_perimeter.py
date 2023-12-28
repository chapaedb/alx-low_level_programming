#!/usr/bin/python3
"""Defines an island perimeter measuring function."""

def island_perimeter(grid):
    """Return the perimeter of an island.

    The grid represents water by 0 and land by 1.

    Args:
        grid (list): A list of lists of integers representing an island.
    Returns:
        The perimeter of the island defined in the grid.
    """
    width = len(grid[0])
    height = len(grid)
    edge_count = 0
    land_count = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                land_count += 1
                if j > 0 and grid[i][j - 1] == 1:
                    edge_count += 1
                if i > 0 and grid[i - 1][j] == 1:
                    edge_count += 1

    return land_count * 4 - edge_count * 2
