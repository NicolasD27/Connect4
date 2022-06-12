#include "connect4.h"

extern t_map board;

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

void	deallocate_board()
{
	for (int i = 0; i < get_height(); ++i)
		free(board.tab[i]);
	free(board.tab);
}


