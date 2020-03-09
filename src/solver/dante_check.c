/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** dante_check.c
*/

#include "../../include/my.h"
#include "../../include/solver.h"
#include "../../include/garbage_collector.h"

void change_status(cellule_t **neighbors, int y, int x)
{
    for (cellule_t *copy = *neighbors; copy; copy = copy->neighbors) {
        if (copy->y == y && copy->x == x) {
            copy->status = 1;
            return;
        }
    }
}

void setup_neighbors(cellule_t **neighbors, store_t *store, int x, int y)
{
    if (y < store->cols - 1 && store->map[y + 1][x] != 'X')
        spe_push(neighbors, y + 1, x);
    if (y > 0 && store->map[y - 1][x] != 'X')
        spe_push(neighbors, y - 1, x);
    if (x < store->rows - 1 && store->map[y][x + 1] != 'X')
        spe_push(neighbors, y, x + 1);
    if (x > 0 && store->map[y][x - 1] != 'X')
        spe_push(neighbors, y, x - 1);
}

void add_front(nodes_t **nodes, cellule_t cellule)
{
    nodes_t *new = my_malloc(sizeof(nodes_t));

    new->cellule = cellule;
    new->next = *nodes;
    new->previous = NULL;
    (*nodes)->previous = new;
    *nodes = (*nodes)->previous;
}

void delete_neighbor(cellule_t **neighbor, cellule_t *ptr)
{
    if (!*neighbor || !ptr)
        return;
    if (*neighbor == ptr)
        *neighbor = ptr->neighbors;
    if (ptr->neighbors)
        ptr->neighbors->previous = ptr->previous;
    if (ptr->previous)
        ptr->previous->neighbors = ptr->neighbors;
}

int check_better(nodes_t *current, cellule_t *nei, nodes_t **open)
{
    int tempG = 0;
    int bool = 0;

    tempG = current->cellule.g_cost + 1;
    if (include(*open, *nei)) {
        if (tempG < nei->g_cost) {
            nei->g_cost = tempG;
            bool = 2;
        }
    } else {
        nei->g_cost = tempG;
        bool = 1;
    }
    return (bool);
}