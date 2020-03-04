/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** random.c
*/

#include "../../include/my.h"
#include "../../include/generator.h"
#include "../../include/garbage_collector.h"

void fourth_order(char **map, int prev[2], cells_t *cells)
{
    if (check_neighbour(prev[0] - 1, prev[1], map, prev)) {
        add_cell(prev[0] - 1, prev[1], cells);
        return;
    }
    if (check_neighbour(prev[0], prev[1] + 1, map, prev)) {
        add_cell(prev[0], prev[1] + 1, cells);
        return;
    }
    if (check_neighbour(prev[0], prev[1] - 1, map, prev)) {
        add_cell(prev[0], prev[1] - 1, cells);
        return;
    }
    if (check_neighbour(prev[0] + 1, prev[1], map, prev)) {
        add_cell(prev[0] + 1, prev[1], cells);
        return;
    }
}

void third_order(char **map, int prev[2], cells_t *cells)
{
    if (check_neighbour(prev[0], prev[1] + 1, map, prev)) {
        add_cell(prev[0], prev[1] + 1, cells);
        return;
    }
    if (check_neighbour(prev[0], prev[1] - 1, map, prev)) {
        add_cell(prev[0], prev[1] - 1, cells);
        return;
    }
    if (check_neighbour(prev[0] + 1, prev[1], map, prev)) {
        add_cell(prev[0] + 1, prev[1], cells);
        return;
    }
    if (check_neighbour(prev[0] - 1, prev[1], map, prev)) {
        add_cell(prev[0] - 1, prev[1], cells);
        return;
    }
}

void second_order(char **map, int prev[2], cells_t *cells)
{
    if (check_neighbour(prev[0], prev[1] - 1, map, prev)) {
        add_cell(prev[0], prev[1] - 1, cells);
        return;
    }
    if (check_neighbour(prev[0] + 1, prev[1], map, prev)) {
        add_cell(prev[0] + 1, prev[1], cells);
        return;
    }
    if (check_neighbour(prev[0] - 1, prev[1], map, prev)) {
        add_cell(prev[0] - 1, prev[1], cells);
        return;
    }
    if (check_neighbour(prev[0], prev[1] + 1, map, prev)) {
        add_cell(prev[0], prev[1] + 1, cells);
        return;
    }
}

void first_order(char **map, int prev[2], cells_t *cells)
{
    if (check_neighbour(prev[0] + 1, prev[1], map, prev)) {
        add_cell(prev[0] + 1, prev[1], cells);
        return;
    }
    if (check_neighbour(prev[0] - 1, prev[1], map, prev)) {
        add_cell(prev[0] - 1, prev[1], cells);
        return;
    }
    if (check_neighbour(prev[0], prev[1] + 1, map, prev)) {
        add_cell(prev[0], prev[1] + 1, cells);
        return;
    }
    if (check_neighbour(prev[0], prev[1] - 1, map, prev)) {
        add_cell(prev[0], prev[1] - 1, cells);
        return;
    }
}