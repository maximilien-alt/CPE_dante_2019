/*
** EPITECH PROJECT, 2019
** CPE_bootstrap_dante_2019
** File description:
** main.c
*/

#include "../../include/my.h"
#include "../../include/solver.h"
#include "../../include/garbage_collector.h"

int final_push(nodes_t *current, store_t *store)
{
    cellule_t temp = current->cellule;

    while (temp.previous) {
        store->map[temp.y][temp.x] = 'o';
        temp = *temp.previous;
    }
    store->map[temp.y][temp.x] = 'o';
    return (0);
}

void set_neighbors(nodes_t **current, cellule_t **array, store_t *store)
{
    int x = (*current)->cellule.x;
    int y = (*current)->cellule.y;

    (*current)->cellule.neighbors = array[y][x].neighbors;
    if (y < store->cols - 1)
        change_status(&array[y + 1][x].neighbors, y, x);
    if (y > 0)
        change_status(&array[y - 1][x].neighbors, y, x);
    if (x < store->rows - 1)
        change_status(&array[y][x + 1].neighbors, y, x);
    if (x > 0)
        change_status(&array[y][x - 1].neighbors, y, x);
}

void print_char(char **map, int x, int y)
{
    printf("%c", map[y][x]);
}

int check_good_input(int ac, char *av[])
{
    int fd = 0;
    char buffer[1];

    if (ac != 2)
        exit (84);
    fd = open(av[1], O_RDONLY);
    if (!fd)
        exit (84);
    if (read(fd, buffer, 1) <= 0)
        exit (84);
    close (fd);
    return (0);
}

int main(int ac, char *av[])
{
    char **map = NULL;
    int index = 0;

    check_good_input(ac, av);
    map = dante_solver(av[1]);
    (void)map;
    for (; map[index + 1]; index += 1)
        printf("%s\n", map[index]);
    printf("%s", map[index]);
    return (0);
}