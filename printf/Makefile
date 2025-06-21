# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenouis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 13:51:23 by mbenouis          #+#    #+#              #
#    Updated: 2024/12/20 14:35:54 by mbenouis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ft_printf.a

SRC = ft_utils.c\
      ft_printf.c\
	  ft_printhex.c\
	  ft_putnbr.c\
	  ft_putptr.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY = clean all fclean re

