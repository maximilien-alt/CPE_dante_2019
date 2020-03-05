/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** dante_check.c
*/

#include "../../include/my.h"
#include "../../include/solver.h"
#include "../../include/garbage_collector.h"

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
            bool = 1;
        }
    } else {
        nei->g_cost = tempG;
        bool = 1;
    }
    return (bool);
}