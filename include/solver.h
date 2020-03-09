/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** solver.h
*/

#ifndef SOLVER_H_
#define SOLVER_H_

typedef struct fast_s
{
    int top;
    int bottom;
    int right;
    int left;
}fast_t;

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

int spe_include(nodes_t *close, int y, int x);
void spe_push(cellule_t **neighbor, int y, int x);
void add_front(nodes_t **nodes, cellule_t cellule);
void delete_neighbor(cellule_t **neighbor, cellule_t *ptr);
int check_better(nodes_t *current, cellule_t *nei, nodes_t **open);
int final_push(nodes_t *current, store_t *store, cellule_t **array);
void check_for_close(nodes_t *close, fast_t *fast, int y, int x);
void set_neighbors(nodes_t **current, store_t *store, \
nodes_t *close, fast_t *fast);
int get_h_cost(int x, int y, int x_f, int y_f);
void delete_node(nodes_t **nodes, nodes_t *ptr);
nodes_t *lowest_fcost(nodes_t *open);
cellule_t **create_array(store_t *store);
void print_map(store_t *store, cellule_t **array, \
nodes_t *open, nodes_t *close);
int include(nodes_t *nodes, cellule_t cellule);
void print_char(char **map, int x, int y);
void push(nodes_t **nodes, cellule_t cellule);
cellule_t new(int x, int y, void (*show)(char **, int, int));
char **dante_solver(char *filepath);
#endif /* SOLVER_H */