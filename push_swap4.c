#include "push_swap.h"
int find_min(t_double_list *list_a)
{
    t_node *tmp;
    int min;
    unsigned int i;

    i = 0;
    tmp = list_a->head;
    min = tmp->content;
    while(i < list_a->size)
    {
        if(tmp->content < min)
            min = tmp->content;
        tmp = tmp->next;
        i++;
    }
    return(min);
}

void   hardcoded5_sort(t_piles *piles)
{
    int min;

    min = find_min(piles->pile_a);
    while(piles->pile_a->head->content > min)
        ra(piles);
    pb(piles);
     min = find_min(piles->pile_a);
    while(piles->pile_a->head->content > min)
        ra(piles);
    pb(piles);
    hardcoded3_sort(piles);
    pa(piles);
    pa(piles);
    if(piles->pile_a->head->content > piles->pile_a->head->next->content)
        sa(piles);
}

void   hardcoded4_sort(t_piles *piles)
{
    int min;

    min = find_min(piles->pile_a);
    while(piles->pile_a->head->content > min)
        ra(piles);
    pb(piles);
    hardcoded3_sort(piles);
    pa(piles);
}

void       hardcoded3_sort(t_piles *piles)
{
    int a;
    int b;
    int c;

    a = piles->pile_a->head->content;
    b = piles->pile_a->head->next->content;
    c = piles->pile_a->head->next->next->content;
    //printf("\ngot in here 3\n");
    if (a > b && b < c && a < c)
        sa(piles);               
    else if (a > b && b > c && a > c)
    {
        sa(piles);               
        rra(piles);               
    }
    else if (a > b && b < c && a > c)
        ra(piles);                 
    else if (a < b && b > c && a < c)
    {
        sa(piles);                  
        ra(piles);                 
    }
    else if (a < b && b > c && a > c)
        rra(piles);  
}
void       hardcoded2_sort(t_piles *piles)
{
    int a;
    int b;

    a = piles->pile_a->head->content;
    b = piles->pile_a->head->next->content;
    if(a < b)
        sa(piles);
}
