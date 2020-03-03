/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** cells.c
*/

#include "../../include/garbage_collector.h"
#include "../../include/my.h"
#include "../../include/generator.h"

void delete_cell(cells_t *cellules, cells_t *ptr)
{
    if (!cellules || !ptr)
        return;
    if (cellules == ptr)
        cellules = ptr->next;
    if (ptr->next)
        ptr->next->previous = ptr->previous;
    if (ptr->previous)
        ptr->previous->next = ptr->next;
}

void add_cell(int x, int y, cells_t *cells)
{
    cells_t *copy = my_malloc(sizeof(cells_t));
    cells_t *temp = cells;

    copy->x = x;
    copy->y = y;
    copy->next = NULL;
    if (!cells) {
        copy->previous = NULL;
        cells = copy;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->next = copy;
    copy->previous = temp;
}