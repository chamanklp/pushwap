#ifndef UTILS_H
# define UTILS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../printf/ft_printf.h"

typedef struct node
{
    int        content;
    struct node    *next;
    struct node    *prev;
}                t_node;

typedef struct double_list
{
    t_node                *head;
    t_node                *tail;
    unsigned int        size;
}                        t_double_list;

t_node            *node_create(int content);
t_double_list    *double_list_create(void);
void                    double_list_free(t_double_list *list);
int        double_list_add_first(t_double_list *list, int nbr);
int    double_list_peak_first(t_double_list *list);
int    double_list_pop_first(t_double_list *list);
void    double_list_remove_first(t_double_list *list);
int        double_list_add_last(t_double_list *list, int nbr);
int    double_list_peak_last(t_double_list *list);
int    double_list_pop_last(t_double_list *list);
void    double_list_remove_last(t_double_list *list);
int is_alphan(char str);
int is_space(char *s);
void free_list(char **str);
void dissplay_error(char *str);
long	ft_atol(char *str);
#endif