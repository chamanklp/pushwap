#include "push_swap.h"

void	sa(t_piles *piles)
{
	int	first;
	int	second;

	first = double_list_pop_first(piles->pile_a);
	second = double_list_pop_first(piles->pile_a);
	double_list_add_first(piles->pile_a, first);
	double_list_add_first(piles->pile_a, second);
	ft_printf("sa\n");
}
void	sb(t_piles *piles)
{
	int	first;
	int	second;

	first = double_list_pop_first(piles->pile_a);
	second = double_list_pop_first(piles->pile_a);
	double_list_add_first(piles->pile_a, first);
	double_list_add_first(piles->pile_a, second);
	ft_printf("sb\n");
}
void	ss(t_piles *piles)
{
    int	first;
	int	second;

	first = double_list_pop_first(piles->pile_a);
	second = double_list_pop_first(piles->pile_a);
	double_list_add_first(piles->pile_a, first);
	double_list_add_first(piles->pile_a, second);
    first = double_list_pop_first(piles->pile_a);
	second = double_list_pop_first(piles->pile_a);
	double_list_add_first(piles->pile_a, first);
	double_list_add_first(piles->pile_a, second);
	ft_printf("ss\n");
}
void	pa(t_piles *piles)
{
    if(piles->pile_b->size != 0)
        double_list_add_first(piles->pile_a,double_list_pop_first(piles->pile_b));
	
    ft_printf("pa\n");
}
void	pb(t_piles *piles)
{
    if(piles->pile_a->size != 0)
        double_list_add_first(piles->pile_b,double_list_pop_first(piles->pile_a));
	
    ft_printf("pb\n");
}