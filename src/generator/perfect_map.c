/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** perfect_map.c
*/

#include "../../include/my.h"
#include "../../include/generator.h"
#include "../../include/garbage_collector.h"

void print_list(cells_t *cellules)
{
    cells_t *copy = NULL;

    while (cellules) {
        printf("%d %d\n", cellules->x, cellules->y);
        copy = cellules;
        cellules = cellules->next;
    }
    while (copy->previous) {
        printf("%d %d\n", copy->x, copy->y);
        copy = copy->previous;
    }
}

void create_random_map(char **map, cells_t *cellules)
{
    (void)map;
    for (int i = 1; i < 5; i += 1)
        add_cell(i, i, cellules);
    print_list(cellules);
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
    create_random_map(map, &cellules);
    printf("%d", cellules.x);
    return (map);
}