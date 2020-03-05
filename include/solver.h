/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** solver.h
*/

#ifndef SOLVER_H_
#define SOLVER_H_

typedef struct cellule_s
{
    int x;
    int y;
    int f_cost;
    int g_cost;
    int h_cost;
    void (*show)(char **, int, int);
    struct cellule_s *neighbors;
    struct cellule_s *previous;
}cellule_t;

typedef struct store_s
{
    char **map;
    int cols;
    int rows;
    cellule_t start;
    cellule_t end;
}store_t;

typedef struct nodes_s
{
    cellule_t cellule;
    struct nodes_s *next;
    struct nodes_s *previous;
}nodes_t;

int final_push(nodes_t *current, store_t *store, cellule_t **array);
void addNeighbors(cellule_t **cellule, store_t *store, \
int index, int temp);
void set_neighbors(nodes_t **current, cellule_t **array, store_t *store);
int get_h_cost(int x, int y, int x_f, int y_f);
void delete_node(nodes_t **nodes, nodes_t *ptr);
nodes_t *lowest_fcost(nodes_t *open);
cellule_t **create_array(store_t *store);
void print_map(store_t *store, cellule_t **array, \
nodes_t *open, nodes_t *close);
int include(nodes_t *nodes, cellule_t cellule);
void print_char(char **map, int x, int y);
void push(nodes_t **nodes, cellule_t cellule);
cellule_t new(int x, int y, store_t *store, void (*show)(char **, int, int));
char **dante_solver(char *filepath);
#endif /* SOLVER_H */