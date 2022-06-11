
CFLAGS = -Wall -Wextra -g3 -pedantic -fsanitize=address -I ./libft

LIBFT = libft/libft.a

NAME = Connect4
FILES = connect4
SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(LIBFT):
	make -C libft all
