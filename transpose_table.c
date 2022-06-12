#include "connect4.h"

t_transpos_table * allocate_transpos_table_node(float eval, t_map *board)
{
	t_transpos_table * new = ft_calloc(1, sizeof(t_transpos_table));
	if (new)
	{
		new->eval = eval;
		(void)board;
		//duplicate board
	}
	return (new);	
}

void deallocate_transpos_table_node(void * table)
{
	t_transpos_table * to_free = table;
	for (int i = 0; i < get_height(); ++i)
		free(to_free->board.tab[i]);
	free(to_free);
}

