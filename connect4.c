#include "connect4.h"

t_map board;

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

struct answer *	allocate_answer_node(struct coordinates * coord)
{
	struct answer * new = ft_calloc(1, sizeof(struct answer));
	if (new)
	{
		new->input.x = coord->x;
		new->input.y = coord->y;
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
	free(node->next);
}

void	deallocate_board()
{
	for (int i = 0; i < get_height(); ++i)
		free(board.tab[i]);
	free(board.tab);
}

enum case_state	choose_first_player()
{
	int res = rand() % 2;
	if (res)
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

int main(int argc, char *argv[])
{
	// int winner;
	if ((argc != 3) || !get_map_size(argv[1], argv[2]))
		return print_usage();
	struct coordinates tmp;
	tmp.x = 0;
	tmp.y = 0;
	struct answer * node = allocate_answer_node(&tmp);
	if (allocate_board())
		display_game();

	compute_whole_game(node, 5, choose_first_player());
	//display_game();
	deallocate_board();
	// while (1)
	// {
	// 	display_game();
	// 	prompt_move();
	// 	if ((winner = is_finished()) != 0)
	// 		return print_winner(winner);
	// }
	return (0);
}
