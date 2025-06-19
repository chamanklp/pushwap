#include "utils/utils.h"


int check_redondancy(int new_content,t_double_list *list_a)
{
    while(list_a->head->next)
    {
        if(list_a->head->content == new_content)
        {
            printf("seen this before \n");
            return(1);
        }
        list_a->head = list_a->head->next;
    }
    return(0); 
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
                double_list_free(list_a);
                display_error();
                return(0);
            }
    }
    new_content = ft_atol(str);
    if(new_content >= +2147483647 || new_content <=  -2147483647)
    {
        display_error();
        return(0);
    }
    
    if(check_redondancy(new_content,list_a))
        return(0);
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
        display_error();
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
            exit(0);
        }
    }
}

int main(int argc, char **argv)
{
    int i;
    int argflag;
    t_double_list    *list_a;
    
    list_a = double_list_create();
    if(!list_a)
            free(list_a);
    argflag =1;
    i = 1;
    while(i < argc)
    {
        //printf("%s \n",argv[i]);
        if(is_space(argv[i]))
            arg_list_checker(argv[i],list_a);
        else
            arg_checker(argv[i],list_a);
                    //argchecker also stores the value in the A linked list
        i++;
    }
    return(0);
}