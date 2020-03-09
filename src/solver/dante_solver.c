/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** dante_solve.c
*/

#include "../../include/my.h"
#include "../../include/solver.h"
#include "../../include/garbage_collector.h"

char **get_map(char *filepath)
{
    int fd = 0;
    char *buffer = NULL;
    struct stat st;
    char **map = NULL;

    fd = open(filepath, O_RDONLY);
    stat(filepath, &st);
    buffer = my_malloc(sizeof(char) * st.st_size + 1);
    memset(buffer, 0, st.st_size + 1);
    read(fd, buffer, st.st_size);
    close (fd);
    map = my_str_to_word_array(buffer, "\n");
    return (map);
}

void foreach_neighbors(nodes_t *current, nodes_t **open, \
nodes_t *close, store_t *store)
{
    cellule_t *nei = current->cellule.neighbors;
    int bool = 0;

    for (; nei; nei = nei->neighbors) {
        if (!include(close, *nei)) {
            bool = check_better(current, nei, open);
            if (bool == 1 || bool == 2) {
                nei->h_cost = get_h_cost(nei->x, nei->y, \
                store->end.x, store->end.y);
                nei->f_cost = nei->g_cost + nei->h_cost;
                nei->previous = &current->cellule;
            }
            if (bool == 1)
                push(open, *nei);
        }
    }
}

int loop(store_t *store, cellule_t **array)
{
    nodes_t *open = NULL;
    nodes_t *close = NULL;
    nodes_t *current = NULL;

    push(&open, store->start);
    while (open) {
        current = lowest_fcost(open);
        if (current->cellule.x == store->end.x && \
        current->cellule.y == store->end.y)
            return (final_push(current, store, array));
        delete_node(&open, current);
        push(&close, current->cellule);
        set_neighbors(&current, store);
        foreach_neighbors(current, &open, close, store);
    }
    exit (84);
}

char **dante_solver(char *filepath)
{
    char **map = get_map(filepath);
    store_t store;
    int index = 0;
    cellule_t **array = NULL;

    for (; map[0][index]; index += 1);
    store.map = map;
    store.rows = index;
    for (index = 0; map[index]; index += 1);
    store.cols = index;
    array = create_array(&store);
    store.start = array[0][0];
    store.end = array[store.cols - 1][store.rows - 1];
    loop(&store, array);
    return (store.map);
}