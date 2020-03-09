/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** dante_include.c
*/

#include "../../include/my.h"
#include "../../include/solver.h"
#include "../../include/garbage_collector.h"

void spe_push(cellule_t **neighbor, int y, int x)
{
    cellule_t *new = my_malloc(sizeof(cellule_t));
    cellule_t *temp = *neighbor;

    new->status = 0;
    new->x = x;
    new->y = y;
    new->f_cost = 0;
    new->g_cost = 0;
    new->h_cost = 0;
    new->show = print_char;
    new->neighbors = NULL;
    if (!*neighbor) {
        new->previous = NULL;
        *neighbor = new;
        return;
    }
    while (temp->neighbors)
        temp = temp->neighbors;
    temp->neighbors = new;
    new->previous = temp;
}

void delete_node(nodes_t **nodes, nodes_t *ptr)
{
    if (!*nodes || !ptr)
        return;
    if (*nodes == ptr)
        *nodes = ptr->next;
    if (ptr->next)
        ptr->next->previous = ptr->previous;
    if (ptr->previous)
        ptr->previous->next = ptr->next;
}

nodes_t *lowest_fcost(nodes_t *open)
{
    int save_f = 1000000000;
    int check = 0;
    int winner = 0;

    for (nodes_t *copy = open; copy; copy = copy->next) {
        if (copy->cellule.f_cost < save_f) {
            save_f = copy->cellule.f_cost;
            winner = check;
        }
        check += 1;
    }
    for (nodes_t *copy = open; copy; copy = copy->next) {
        if (winner == 0)
            return (copy);
        winner -= 1;
    }
    return (NULL);
}

int include(nodes_t *nodes, cellule_t cellule)
{
    for (nodes_t *copy = nodes; copy; copy = copy->next)
        if (copy->cellule.x == cellule.x && \
        copy->cellule.y == cellule.y)
            return (1);
    return (0);
}