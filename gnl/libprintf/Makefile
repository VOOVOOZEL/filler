NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

DIR_S = printf

HEADER = includes

SOURCES  =	check_format.c ft_printf.c identification_1.c identification_2.c identification_3.c \
 			count_position.c flags_set.c flags_others.c ft_build.c length_precision.c \
 			read_wchar.c min_width.c identification_4.c


SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(DIR_S)/$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp ./libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o : $(DIR_S)/%.c
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)

re: fclean all

test:
	@gcc -I include -o test test.c -L. -lftprintf
	@./test | cat -e

pupa:
	@rm test
	@gcc -I include -o test test.c -L. -lftprintf