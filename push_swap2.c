#include "push_swap.h"

void ra(t_piles *piles)
{
    double_list_add_last(piles->pile_a,double_list_pop_first(piles->pile_a));
    ft_printf("ra\n");
}
void rb(t_piles *piles)
{
    double_list_add_last(piles->pile_b,double_list_pop_first(piles->pile_b));
    ft_printf("rb\n");
}
    void rr(t_piles *piles)
{
    double_list_add_last(piles->pile_a,double_list_pop_first(piles->pile_a));
    double_list_add_last(piles->pile_b,double_list_pop_first(piles->pile_b));
    ft_printf("rr\n");
}
void rra(t_piles *piles)
{
    double_list_add_first(piles->pile_a,double_list_pop_last(piles->pile_a));
    ft_printf("rra\n");
}
void rrb(t_piles *piles)
{
    double_list_add_first(piles->pile_b,double_list_pop_last(piles->pile_b));
    ft_printf("rrb\n");
}