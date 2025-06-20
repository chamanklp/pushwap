NAME = push_swap
SRC = push_swap.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/ft_printf.a

UTILS_DIR = utils
UTILS = $(UTILS_DIR)/utils.a

DEPS = push_swap.h

all: $(UTILS) $(LIBFT) $(PRINTF) $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) $(PRINTF) $(UTILS):
	$(MAKE) --silent -C $(dir $@)

$(NAME): $(OBJ) $(UTILS) $(LIBFT) $(PRINTF)
	$(CC) $(OBJ) $(CFLAGS) $(UTILS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) --silent -C $(PRINTF_DIR) clean
	$(MAKE) --silent -C $(LIBFT_DIR) clean
	$(MAKE) --silent -C $(UTILS_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) --silent -C $(PRINTF_DIR) fclean
	$(MAKE) --silent -C $(LIBFT_DIR) fclean
	$(MAKE) --silent -C $(UTILS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
