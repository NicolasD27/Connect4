#include "connect4.h"

t_map board;
t_transpos_table *known_board;

int	print_usage()
{
	ft_printf("./connect4 WIDTH HEIGHT\n");
	return 1;
}

bool	get_map_size(char *arg1, char *arg2)
{
	int width = ft_atoi(arg1);
	int height = ft_atoi(arg2);
	if (width >= MIN_WIDTH && height >= MIN_HEIGHT)
	{
		board.width = width;
		board.height = height;
		return (true);
	}
	else
		return (false);
}

int		get_width()
{
	return (board.width);
}

int get_height()
{
	return (board.height);
}

bool	allocate_board()
{
	board.tab = ft_calloc(get_height(), sizeof(void *));
	if (board.tab)
	{
		for (int i = 0; i < get_height(); ++i)
		{
			board.tab[i] = ft_calloc(get_width(), sizeof(enum case_state));
			if (!board.tab[i])
				return (false);
		}
		return (true);
	}
	return (false);
}

struct answer *	allocate_answer_node(struct coordinates * coord, struct answer * prev)
{
	struct answer * new = ft_calloc(1, sizeof(struct answer));
	if (new)
	{
		new->input.x = coord->x;
		new->input.y = coord->y;
		new->eval = -1;
		new->prev = prev;
		new->next = ft_calloc(get_width(), sizeof(void *));
		if (!new->next)
		{
			free(new);
			new = NULL;
		}
	}
	return (new);
}

void	deallocate_answer_node(struct answer * node)
{
	for (int i = 0; i < get_width(); ++i)
	{
		if (node->next[i])
		{
			deallocate_answer_node(node->next[i]);
		}
	}
	//free(node->next[i]);
//	free(node->next);
	free(node);
}

void	deallocate_board()
{
	for (int i = 0; i < get_height(); ++i)
		free(board.tab[i]);
	free(board.tab);
}

enum case_state	choose_first_player()
{
	int res = rand();
	printf("%d\n %d\n", res, rand());
	if (res == 1)
		return red;
	else
		return yellow;
}

enum case_state switch_player(enum case_state current)
{
	if (current == red)
		return yellow;
	else
		return red;
}

void add_move(int move)
{
	int y;
	y = board.height - 1;
	while (y >= 0 && board.tab[y][move] != empty)
		y--;
	if (y >= 0)
		board.tab[y][move] = red;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int winner;
	if ((argc != 3) || !get_map_size(argv[1], argv[2]))
		return print_usage();

	struct coordinates tmp;
	tmp.x = 0;
	tmp.y = 0;
	int ai_move = 0;

	struct answer * node = allocate_answer_node(&tmp, NULL);
	if (allocate_board())
		display_game();
	// known_board = (t_transpos_table)malloc(sizeof(t_transpos_table));
	// if (!known_board)
	// 	return 1;
	compute_whole_game(node, 5, choose_first_player());
	
	ft_printf("ai move : %d\n", ai_move);
	while (1)
	{
		prompt_move();
		display_game();
		compute_whole_game(node, 3, red);
		ai_move = best_move(node);
		ft_printf("best move : %d\n", ai_move);
		add_move(ai_move);
		display_game();
		if ((winner = is_finished()) != 0)
		{
			deallocate_board();
//			deallocate_answer_node(node);
			return print_winner(winner);
		}
	}
	return (0);
}
