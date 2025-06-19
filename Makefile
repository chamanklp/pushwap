
NAME = push_swap

SRC = push_swap.c

CC = cc

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf

PRINTF = $(PRINTF_DIR)/ft_printf.a

UTILS_DIR = utils

UTILS = $(UTILS_DIR)/utils.a

CFLAGS =  -Wall -Wextra -Werror -g3

all : $(UTILS) $(LIBFT) $(PRINTF) $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) : 
	$(MAKE) --silent -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) --silent -C $(PRINTF_DIR)

$(UTILS):
	$(MAKE) --silent -C $(UTILS_DIR)

$(NAME) : $(OBJ) $(UTILS) $(LIBFT) $(PRINTF) 
	$(CC) $(OBJ) $(CFLAGS) $(UTILS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	rm -f $(OBJ) 
	$(MAKE) --silent -C $(PRINTF_DIR) clean
	$(MAKE) --silent -C $(LIBFT_DIR) clean
	$(MAKE) --silent -C $(UTILS_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = clean all fclean re
