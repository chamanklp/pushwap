#include "utils.h"

int        double_list_add_first(t_double_list *list, int nbr)
{
    t_node    *newelem;

    newelem = node_create(nbr);
    if (!newelem)
        return (0);
    newelem->next = list->head;
    if (list->head)
        list->head->prev = newelem;
    list->head = newelem;
    if (!list->tail)
        list->tail = newelem;
    list->size++;
    return (1);
}
int        double_list_add_last(t_double_list *list, int nbr)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return -1;
    new_node->content = nbr;
    new_node->next = NULL;
    new_node->prev = list->tail;
    if (list->tail)
        list->tail->next = new_node;
    else
        list->head = new_node;
    list->tail = new_node;
    list->size++;
    return 0;
}

int    double_list_pop_first(t_double_list *list)
{
    int value;

    if (!list || !list->head)
        return 0;
    t_node *to_remove = list->head;
    value = to_remove->content;
    list->head = to_remove->next;
    list->size--;
    if (list->head)
        list->head->prev = NULL;
    else
        list->tail = NULL;
    free(to_remove);
    return value;
}
int    double_list_pop_last(t_double_list *list)
{

    t_node *to_remove;

    if (!list || !list->tail)
        return 0;
    to_remove = list->tail;
    int value = to_remove->content;
    list->tail = to_remove->prev;
    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;
    free(to_remove);
    return value;
}


