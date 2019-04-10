NAME = lbrown-b.filler

HEADER = ../inc/filler.h

FLAGS = -Wall -Werror -Wextra -fsanitize=address

SOURCES = main.c set_data.c algo.c

SRCS = $(addprefix $(SOURCES))

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ../gnl/libprintf
	@gcc $(FLAGS)  -I ../inc -L ../gnl/libprintf -lftprintf ../gnl/get_next_line.c -o $(NAME) $(OBJS)

%.o : $(DIR_S)/%.c
	@gcc $(FLAGS) -I $(HEADER) -c  $(SRC)

clean:
	@make clean -C ../gnl/libprintf
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C ../gnl/libprintf
	@/bin/rm -f $(NAME)
	@/bin/rm -f filler.trace

re: fclean all

game:
	../resources/filler_vm -f ../resources/maps/map00 -p1 ./$(NAME) -p2 ../resources/players/superjeannot.filler