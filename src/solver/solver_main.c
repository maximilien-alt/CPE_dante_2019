/*
** EPITECH PROJECT, 2019
** CPE_bootstrap_dante_2019
** File description:
** main.c
*/

#include "../../include/my.h"
#include "../../include/solver.h"
#include "../../include/garbage_collector.h"

int final_push(nodes_t *current, store_t *store, cellule_t **array)
{
    nodes_t *path = NULL;
    cellule_t temp = current->cellule;

    push(&path, temp);
    while (temp.previous) {
        push(&path, *temp.previous);
        temp = *temp.previous;
    }
    for (int index = 0; index < store->cols; index += 1) {
        for (int temp = 0; temp < store->rows; temp += 1) {
            if (include(path, array[index][temp])) {
                printf("\033[0;34m");
                store->map[index][temp] = 'o';
            }
            array[index][temp].show(store->map, temp, index);
            printf("\033[0m");
        }
        printf("\n");
    }
    return (0);
}

void set_neighbors(nodes_t **current, store_t *store)
{
    addNeighbors(&(*current)->cellule.neighbors, store, \
    (*current)->cellule.y, (*current)->cellule.x);
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

    check_good_input(ac, av);
    map = dante_solver(av[1]);
    (void)map;
    //for (int index = 0; map[index]; index += 1)
    //    printf("%s\n", map[index]);
    return (0);
}