#include "utils.h"

int    double_list_peak_last(t_double_list *list)
{
 if (!list || !list->tail)
        return 0;

    return list->tail->content;
}
int    double_list_peak_first(t_double_list *list)
{
    if (!list || !list->head)
        return 0; 
    return list->head->content;
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
void    double_list_remove_first(t_double_list *list)
{
    if (!list || !list->head)
        return;
    t_node *to_remove = list->head;
    list->head = to_remove->next;
    if (list->head)
        list->head->prev = NULL;
    else
        list->tail = NULL;
    free(to_remove);
}