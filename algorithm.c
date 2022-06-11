#include "connect4.h"

extern struct map board;

void	compute_turn()
{

}

int	get_first_empty_tile_height_in_column(int column)
{
	int height = 0;
	while (height < get_height() && board.tab[column][height] != empty)
		height++;
	return (height);
}
