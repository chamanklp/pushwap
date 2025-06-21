#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "utils/utils.h"


typedef struct s_piles
{
    t_double_list *pile_a;
    t_double_list *pile_b;
}                t_piles;


int arg_checker(char *str,t_double_list    *list_a);
void arg_list_checker(char *str,t_double_list    *list_a);
int check_redondancy(int new_content,t_double_list *list_a);
void iterate_and_print(t_double_list *list_a);
void sa(t_piles *piles);
void sb(t_piles *piles);
void ss(t_piles *piles);
void pa(t_piles *piles);
void pb(t_piles *piles);
void ra(t_piles *piles);
void rb(t_piles *piles);
void rr(t_piles *piles);
void rra(t_piles *piles);
void rrb(t_piles *piles);
void rrr(t_piles *piles);
void     sort_it(t_piles *piles);
int check_if_sorted(t_double_list *list_a);
void small_sort(t_piles *piles);
void big_sort(t_piles *piles);
int find_min(t_double_list *list_a);
void hardcoded2_sort(t_piles *piles);
void hardcoded3_sort(t_piles *piles);
void hardcoded4_sort(t_piles *piles);
void hardcoded5_sort(t_piles *piles);
t_piles	*initialiser(void);
void small_sort(t_piles *piles);
void free_piles_all(t_piles *piles);

void index_list(t_double_list *list);
void radix_sort(t_piles *piles);

#endif