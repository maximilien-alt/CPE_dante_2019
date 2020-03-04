/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** imperfect_map.c
*/

#include "../../include/my.h"
#include "../../include/generator.h"

char **imperfect_map(int x, int y)
{
    char **map = perfect_map(x, y);
    int check = 0;
    int tab_len = 0;

    for (; map[tab_len]; tab_len += 1);
    check = rand() % tab_len;
    for (int index = 0; map[check][index]; index += 1)
        map[check][index] = '*';
    return (map);
}