#include "utils.h"

int is_alphan(char str)
{
        if(str < '0' || str > '9')
            return(0);
    return(1);
}
int is_space(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == ' ')
            return(1);
        i++;
    }
    return(0);
}

void free_list(char **str)
{
    int i;

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void dissplay_error(char *str)
{
    ft_printf("ERROR : %s\n",str);
}
