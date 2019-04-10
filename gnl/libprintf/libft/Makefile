NAME = libft.a
HEAD = libft.h
FLAG =  -Werror -Wextra -Wall
OPTION = -c -I..
SRC = *.c

OBJ = $(SRC:%.c=%.o)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean: 
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
