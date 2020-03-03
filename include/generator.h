/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** generator.h
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

typedef struct cell_s
{
    int y;
    int x;
    struct cell_s *next;
    struct cell_s *previous;
}cells_t;

void add_cell(int x, int y, cells_t *cells);
char **perfect_map(int x, int y);
char **imperfect_map(int x, int y);

#endif /* GENERATOR_H_ */