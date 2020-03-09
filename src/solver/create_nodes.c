/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** create_nodes.c
*/

#include "../../include/my.h"
#include "../../include/solver.h"
#include "../../include/garbage_collector.h"

int get_h_cost(int x, int y, int x_f, int y_f)
{
    int x_n = 0;
    int y_n = 0;

    y_n = (y_f - y > 0) ? y_f - y : -(y_f - y);
    x_n = (x_f - x > 0) ? x_f - x : -(x_f - x);
    return (x_n + y_n);
}

int get_g_cost(int x, int y)
{
    int goal[2];
    goal[0] = (0 - x >= 0) ? 0 - x : -(0 - x);
    goal[1] = (0 - y >= 0) ? 0 - y : -(0 - y);
    return (goal[0] + goal[1]);
}

cellule_t **create_array(store_t *store)
{
    cellule_t **array = my_malloc(sizeof(cellule_t *) * store->cols);

    for (int index = 0; index < store->cols; index += 1) {
        array[index] = my_malloc(sizeof(cellule_t) * store->rows);
        for (int temp = 0; temp < store->rows; temp += 1) {
            array[index][temp] = new(temp, index, print_char);
            setup_neighbors(&array[index][temp].neighbors, store, temp, index);
        }
    }
    return (array);
}

cellule_t new(int x, int y, void (*show)(char **, int, int))
{
    cellule_t cellule;

    cellule.status = 0;
    cellule.x = x;
    cellule.y = y;
    cellule.f_cost = 0;
    cellule.g_cost = 0;
    cellule.h_cost = 0;
    cellule.show = show;
    cellule.neighbors = NULL;
    return (cellule);
}

void push(nodes_t **nodes, cellule_t cellule)
{
    nodes_t *new = my_malloc(sizeof(nodes_t));
    nodes_t *temp = *nodes;

    new->cellule = cellule;
    new->next = NULL;
    if (!*nodes) {
        new->previous = NULL;
        *nodes = new;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->next = new;
    new->previous = temp;
}