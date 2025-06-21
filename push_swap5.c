#include "push_swap.h"

void free_piles_all(t_piles *piles)
{
    double_list_free(piles->pile_a);
    double_list_free(piles->pile_b);
    free(piles);

}