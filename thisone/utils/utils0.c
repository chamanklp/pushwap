#include "utils.h"

t_node            *node_create(int content)
{
     t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return NULL; // handle memory allocation failure

    new_node->content = content;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

t_double_list    *double_list_create(void)
{
    t_double_list *list;

    list = malloc(sizeof(t_double_list));
    if (!list)
        return(NULL);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return(list);
}

void                    double_list_free(t_double_list *list)
{
    t_node *node = list->head;
    while(node != NULL)
    {
        t_node *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}