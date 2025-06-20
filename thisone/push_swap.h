#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "utils/utils.h"

int arg_checker(char *str,t_double_list    *list_a);
void arg_list_checker(char *str,t_double_list    *list_a);
int check_redondancy(int new_content,t_double_list *list_a);
#endif