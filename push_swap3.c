#include "push_swap.h"

void rrr(t_piles *piles)
{
    double_list_add_first(piles->pile_a,double_list_pop_last(piles->pile_a));
    double_list_add_first(piles->pile_b,double_list_pop_last(piles->pile_b));
    ft_printf("rrr\n");
}

int check_if_sorted(t_double_list *list_a)
{
    t_node *tmp;
    unsigned int i;

    i = 0;
    tmp = list_a->head;
    while (i < list_a->size && tmp->next)
    {
        if(tmp->content >= tmp->next->content)
            return(0);
        tmp = tmp->next;
        i++;
    }
    return(1);
}

void     sort_it(t_piles *piles)
{
    if(piles->pile_a->size <= 5)
    {
        small_sort(piles);
    }
    else
       big_sort(piles);
}

void small_sort(t_piles *piles)
{
    if(piles->pile_a->size == 4)
    {
        hardcoded4_sort(piles);
    }
    else if (piles->pile_a->size == 5)
    {
        hardcoded5_sort(piles);
    }
    else if (piles->pile_a->size == 3)
    {
        hardcoded3_sort(piles);
    }
    else if(piles->pile_a->size == 2)
        hardcoded2_sort(piles);
}

void        big_sort(t_piles *piles)
{
    index_list(piles->pile_a);
    radix_sort(piles);
}
