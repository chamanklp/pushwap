#include "utils/utils.h"


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
    if(new_content >= +2147483647 || new_content <=  -2147483647)
    {
        dissplay_error("argument value overflow");
        return(0);
    }
    if(check_redondancy(new_content,list_a))
    {
        dissplay_error("Argument redundancy");
        return(0);
    }
    double_list_add_first(list_a,new_content);
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
        exit(0);
    }
    while(splitted_list[i])
    {
        if(arg_checker(splitted_list[i],list_a))
            i++;
        else
        {
            double_list_free(list_a);
            free_list(splitted_list);
            exit(1);
        }
    }
    free_list(splitted_list);
}

int main(int argc, char **argv)
{
    int i;
    t_double_list    *list_a;
    
    list_a = double_list_create();
    if(!list_a){
        dissplay_error("Failed to creat the double linked list");
        return(1);
    }
    i = 1;
    while(i < argc)
    {
        if(is_space(argv[i]))
            arg_list_checker(argv[i],list_a);
        else if(!arg_checker(argv[i],list_a))
        {
            double_list_free(list_a);
            exit(1);
        }
        i++;
    }
    double_list_free(list_a);
    return(0);
}