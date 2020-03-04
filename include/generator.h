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

void first_order(char **map, int prev[2], cells_t *cells);
void second_order(char **map, int prev[2], cells_t *cells);
void third_order(char **map, int prev[2], cells_t *cells);
void fourth_order(char **map, int prev[2], cells_t *cells);
void delete_cell(cells_t *cellules, cells_t *ptr);
int check_neighbour(int x, int y, char **map, int prev[2]);
void add_cell(int x, int y, cells_t *cells);
char **perfect_map(int x, int y);
char **imperfect_map(int x, int y);

#endif /* GENERATOR_H_ */