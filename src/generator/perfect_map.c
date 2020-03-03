/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** perfect_map.c
*/

#include "../../include/my.h"
#include "../../include/generator.h"
#include "../../include/garbage_collector.h"

void complete_cell(char **map, int x, int y, cells_t *cells)
{
    int prev[2];

    prev[0] = x;
    prev[1] = y;
    if (check_neighbour(x + 1, y, map, prev)) {
        add_cell(x + 1, y, cells);
        return;
    }
    if (check_neighbour(x - 1, y, map, prev)) {
        add_cell(x - 1, y, cells);
        return;
    }
    if (check_neighbour(x, y + 1, map, prev)) {
        add_cell(x, y + 1, cells);
        return;
    }
    if (check_neighbour(x, y - 1, map, prev)) {
        add_cell(x, y - 1, cells);
        return;
    }
}

int none_neighbour(int x, int y, char **map)
{
    int prev[2];

    prev[0] = x;
    prev[1] = y;
    if (check_neighbour(x + 1, y, map, prev)) {
        return (0);
    }
    if (check_neighbour(x - 1, y, map, prev)) {
        return (0);
    }
    if (check_neighbour(x, y + 1, map, prev)) {
        return (0);
    }
    if (check_neighbour(x, y - 1, map, prev)) {
        return (0);
    }
    return (1);
}

char **create_random_map(char **map, cells_t *cellules)
{
    cells_t *copy = NULL;

    if (!cellules)
        return (map);
    map[cellules->y][cellules->x] = '*';
    for (int index = 0; map[index]; index += 1)
        printf("%s\n", map[index]);
    printf("\n");
    if (none_neighbour(cellules->x, cellules->y, map)) {
        copy = cellules;
        for (; cellules; cellules = cellules->next)
            delete_cell(cellules, cellules);
        return (create_random_map(map, copy->previous));
    }
    complete_cell(map, cellules->x, cellules->y, cellules);
    return (create_random_map(map, cellules->next));
}

char **perfect_map(int x, int y)
{
    char **map = my_malloc(sizeof(char *) * (y + 1));
    int index = 0;
    cells_t cellules;

    cellules.x = 0;
    cellules.y = 0;
    cellules.next = NULL;
    cellules.previous = NULL;
    for (index = 0; index < y; index += 1) {
        map[index] = my_malloc(sizeof(char) * x + 1);
        my_memset(map[index], 0, x + 1);
        for (int temp = 0; temp < x; temp += 1)
            map[index][temp] = 'X';
    }
    map[index] = NULL;
    map = create_random_map(map, &cellules);
    return (map);
}