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

bool	allocate_board()
{
	board.tab = ft_calloc(board.height, sizeof(void *));
	if (board.tab)
	{
		for (int i = 0; i < MIN_HEIGHT; ++i)
			board.tab[i] = ft_calloc(board.width, sizeof(enum case_state));
		return (true);
	}
	return (false);
}

void	deallocate_board()
{
	for (int i = 0; i < MIN_HEIGHT; ++i)
		free(board.tab[i]);
	free(board.tab);
}


int main(int argc, char *argv[])
{
	// int winner;
	if ((argc != 3) || !get_map_size(argv[1], argv[2]))
		return print_usage();
	allocate_board();
	display_game();
	// while (1)
	// {
	// 	display_game();
	// 	prompt_move();
	// 	if ((winner = is_finished()) != 0)
	// 		return print_winner(winner);
	// }
	return (0);
}
