/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** generator_main.c
*/

#include "../../include/my.h"
#include "../../include/generator.h"
#include "../../include/garbage_collector.h"

int check_input_error(int ac, char *av[])
{
    if (ac < 3 || ac > 4)
        exit (84);
    if (!my_str_isnum(av[1]) || !my_str_isnum(av[2]))
        exit (84);
    if (ac == 4 && !(!strcmp(av[3], "perfect") || \
    !strcmp(av[3], "imperfect")))
        exit (84);
    return (0);
}

int main(int ac, char *av[])
{
    int x = 0;
    int y = 0;
    char **map = NULL;

    srand(time(NULL));
    check_input_error(ac, av);
    x = my_getnbr(av[1]);
    y = my_getnbr(av[2]);
    if (ac == 4 && !strcmp(av[3], "perfect"))
        map = perfect_map(x, y);
    else
        map = imperfect_map(x, y);
    for (int index = 0; map && map[index]; index += 1)
        printf("%s\n", map[index]);
    return (0);
}