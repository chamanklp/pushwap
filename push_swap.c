#include "push_swap.h"

int check_redondancy(int new_content,t_double_list *list_a)
{
    t_node *tmp = list_a->head;
    while (tmp) {
        //printf("\n %i \n",tmp->content);
        if (tmp->content == new_content)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int arg_checker(char *str,t_double_list    *list_a)
{
    int i;
    long new_content;

    i = 0;
    while(str[i])
    {
        if((((str[i] == '+' || str[i] == '-') && i == 0) && is_alphan(str[i+1])) || is_alphan(str[i]))
                i++;
        else{
                dissplay_error("incorrect argument format"); //specific to format of the argument
                return(0);
            }
    }
    new_content = ft_atol(str);
    if(new_content >= +2147483648 || new_content <=  -2147483648 || check_redondancy(new_content,list_a))
    {
        dissplay_error("argument redundant or overflowing");
        return(0);
    }
    double_list_add_last(list_a,new_content);
    return(1);
}

void arg_list_checker(char *str,t_double_list    *list_a)
{
    int i;
    char **splitted_list;

    i = 0;
    splitted_list = ft_split(str,' ');
    if(!splitted_list)
    {
        free_list(splitted_list);
        double_list_free(list_a);
        dissplay_error("ft_split failure");
        exit(2);
    }
    while(splitted_list[i])
    {
        if(arg_checker(splitted_list[i],list_a))
            i++;
        else
        {
            double_list_free(list_a);
            free_list(splitted_list);
            exit(2);
        }
    }
    free_list(splitted_list);
}

t_piles *initialiser(void)
{
    t_piles *piles;

    piles = malloc(sizeof(t_piles));
    if(!piles)
    {
        dissplay_error("Failed to allocate piles");
		exit(1);
    }
    piles->pile_a = double_list_create();
    piles->pile_b = double_list_create();
    if(!piles->pile_a || !piles->pile_b)
    {
        dissplay_error("Failed to creat the double linked list");
        exit(2);
    }
    return(piles);
}
void iterate_and_print(t_double_list *list_a)
{
    t_node *tmp;
    int i;

    tmp = list_a->head;
    i = 0;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
}
/*--------------------------------------------*/
void index_list(t_double_list *list)
{
    t_node *tmp;
    int size;
    int *arr;

    tmp = list->head;
    size = list->size;
    arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = tmp->content;
        tmp = tmp->next;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    tmp = list->head;
    while (tmp) {
        for (int i = 0; i < size; i++) {
            if (tmp->content == arr[i]) {
                tmp->content = i;
                break;
            }
        }
        tmp = tmp->next;
    }
    free(arr);
}

void radix_sort(t_piles *piles)
{
    int max_num;
    int max_bits;

    max_num = piles->pile_a->size - 1;
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;
    for (int i = 0; i < max_bits; i++) {
        int size = piles->pile_a->size;
        for (int j = 0; j < size; j++) {
            int num = piles->pile_a->head->content;
            if (((num >> i) & 1) == 1)
                ra(piles);
            else
                pb(piles);
        }
        while (piles->pile_b->size > 0)
            pa(piles);
    }
}

int main(int argc, char **argv)
{
    int i;
    t_piles *piles;

    i = 1;
    piles = initialiser();
    while(i < argc)
    {
        if(is_space(argv[i]))
            arg_list_checker(argv[i],piles->pile_a);
        else if(!arg_checker(argv[i],piles->pile_a))
        {
            double_list_free(piles->pile_a);
            exit(2);
        }
        i++;
    }
    if(check_if_sorted(piles->pile_a))
    {
        free_piles_all(piles);
        return(0);
    }
    sort_it(piles);
    free_piles_all(piles);
    return(0);
}
