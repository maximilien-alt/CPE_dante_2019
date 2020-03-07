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
    int check = rand() % 4;

    prev[0] = x;
    prev[1] = y;
    if (map[y][x + 1] && !map[y][x + 2] && !map[y + 1] && map[y][x + 1] != '*')
        return (add_cell(x + 1, y, cells));
    if (map[y + 1] && !map[y + 2] && !map[y][x + 1] && map[y + 1][x] != '*')
        return (add_cell(x, y + 1, cells));
    if (check == 0)
        first_order(map, prev, cells);
    if (check == 1)
        second_order(map, prev, cells);
    if (check == 2)
        third_order(map, prev, cells);
    if (check == 3)
        fourth_order(map, prev, cells);
}

int none_neighbour(int x, int y, char **map)
{
    int prev[2];

    prev[0] = x;
    prev[1] = y;
    if (check_neighbour(x + 1, y, map, prev))
        return (0);
    if (check_neighbour(x - 1, y, map, prev))
        return (0);
    if (check_neighbour(x, y + 1, map, prev))
        return (0);
    if (check_neighbour(x, y - 1, map, prev))
        return (0);
    return (1);
}

char **create_random_map(char **map, cells_t *cellules)
{
    while (cellules) {
        map[cellules->y][cellules->x] = '*';
        if (none_neighbour(cellules->x, cellules->y, map)) {
            cellules = cellules->previous;
            if (cellules)
                cellules->next = NULL;
        } else {
            complete_cell(map, cellules->x, cellules->y, cellules);
            cellules = cellules->next;
        }
    }
    return (map);
}

char **perfect_map(int x, int y)
{
    char **map = my_malloc(sizeof(char *) * (y + 1));
    int index = 0;
    cells_t cellules;

    if (x <= 0 || y <= 0)
        exit (84);
    cellules.x = 0;
    cellules.y = 0;
    cellules.next = NULL;
    cellules.previous = NULL;
    for (index = 0; index < y; index += 1) {
        map[index] = my_malloc(sizeof(char) * x + 1);
        memset(map[index], 'X', x);
        map[index][x] = 0;
    }
    map[index] = NULL;
    map = create_random_map(map, &cellules);
    return (map);
}