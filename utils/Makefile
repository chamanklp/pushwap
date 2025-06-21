NAME = utils.a

SRC = utils0.c\
      utils1.c\
	  utils2.c\
	  utils3.c\
	  utils4.c

CC = cc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

%.o: %.c utils.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY = clean all fclean rer