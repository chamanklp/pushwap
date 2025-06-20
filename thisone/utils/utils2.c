#include "utils.h"

int    double_list_peak_last(t_double_list *list)
{
 if (!list || !list->tail)
        return 0;

    return list->tail->content;
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
void    double_list_remove_last(t_double_list *list)
{
    t_node *to_remove;

    if (!list || !list->tail)
        return;
    to_remove = list->tail;
    list->tail = to_remove->prev;
    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;
    free(to_remove);
}