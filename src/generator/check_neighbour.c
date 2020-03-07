/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** check_neighbour.c
*/

#include "../../include/my.h"
#include "../../include/generator.h"
#include "../../include/garbage_collector.h"

int check_neighbour_next(char **map, int prev[2], int x, int y)
{
    if (!map[y + 1]) {
        if ((map[y - 1][x] == '*' && (prev[0] != x || prev[1] != y - 1)) \
        || (map[y][x - 1] == '*' && (prev[0] != x - 1 || prev[1] != y)) \
        || (map[y][x + 1] == '*' && (prev[0] != x + 1 || prev[1] != y)))
            return (0);
        return (1);
    }
    if ((map[y + 1][x] == '*' && (prev[0] != x || prev[1] != y + 1)) \
    || (map[y - 1][x] == '*' && (prev[0] != x || prev[1] != y - 1)) \
    || (map[y][x - 1] == '*' && (prev[0] != x - 1 || prev[1] != y)) \
    || (map[y][x + 1] == '*' && (prev[0] != x + 1 || prev[1] != y)))
        return (0);
    return (1);
}

int check_y_case(char **map, int x, int y, int prev[2])
{
    if (!map[y][x + 1]) {
        if ((map[y][x - 1] == '*' && (prev[0] != x - 1 || prev[1] != y)) \
        || (map[y + 1] && map[y + 1][x] == '*' && \
        (prev[0] != x || prev[1] != y + 1)))
            return (0);
        return (1);
    }
    if ((map[y + 1] && map[y + 1][x] == '*' && (prev[0] != x || prev[1] != y + 1)) \
    || (map[y][x - 1] == '*' && (prev[0] != x - 1 || prev[1] != y)) \
    || (map[y][x + 1] == '*' && (prev[0] != x + 1 || prev[1] != y)))
        return (0);
    return (1);
}

int check_x_case(char **map, int x, int y, int prev[2])
{
    if (y == 0) {
        if ((map[y + 1][x] == '*' && (prev[0] != x || prev[1] != y + 1)) \
        || (map[y][x + 1] == '*' && (prev[0] != x + 1 || prev[1] != y)))
            return (0);
        return (1);
    }
    if (!map[y + 1]) {
        if ((map[y - 1][x] == '*' && (prev[0] != x || prev[1] != y - 1)) \
        || (map[y][x + 1] == '*' && (prev[0] != x + 1 || prev[1] != y)))
            return (0);
        return (1);
    }
    if ((map[y - 1][x] == '*' && (prev[0] != x || prev[1] != y - 1)) \
    || (map[y + 1][x] == '*' && (prev[0] != x || prev[1] != y + 1)) \
    || (map[y][x + 1] == '*' && (prev[0] != x + 1 || prev[1] != y)))
        return (0);
    return (1);
}

int check_last_char(char **map, int x, int y, int prev[2])
{
    if (!map[y + 1]) {
        if (((map[y][x - 1] == '*' && (prev[0] != x - 1 || prev[1] != y)) \
        || (map[y - 1][x] == '*' && (prev[0] != x || prev[1] != y - 1))))
            return (0);
        return (1);
    }
    if ((map[y][x - 1] == '*' && (prev[0] != x - 1 && prev[1] != y)) \
    || (map[y + 1][x] == '*' && (prev[0] != x || prev[1] != y + 1)) \
    || (map[y - 1][x] == '*' && (prev[0] != x || prev[1] != y - 1)))
        return (0);
    return (1);
}

int check_neighbour(int x, int y, char **map, int prev[2])
{
    if (x < 0 || !map[0][x] || y < 0 || !map[y])
        return (0);
    if (map[y][x] == '*')
        return (0);
    if (x == 0)
        return (check_x_case(map, x, y, prev));
    if (y == 0)
        return (check_y_case(map, x, y, prev));
    if (!map[y][x + 1])
        return (check_last_char(map, x, y, prev));
    return (check_neighbour_next(map, prev, x, y));
}