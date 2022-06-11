#include "connect4.h"

extern struct map board;

void	fill_turn_node(struct answer * node, enum case_state current_player)
{
	struct coordinates turn_play;

	node->player = current_player;
	for (int i = 0; i < get_width(); i++)
	{
		turn_play.x = i;
		turn_play.y = get_first_empty_tile_height_in_column(i);
		if (turn_play.y != -1) // column is full
			node->next[i] = allocate_answer_node(&turn_play);
		else
			node->next[i] = NULL;
	}
}

int	get_first_empty_tile_height_in_column(int column)
{
	int height = get_height() - 1;
	while (height > -1 &&
		   board.tab[height][column] != empty)
		height--;
	return (height);
}


bool all_move_are_done(struct answer *node)
{
	for (int i = 0; i < get_width(); i++)
	{
		if (node->next[i])
			return (false);
	}
	return (true);
}

void compute_whole_game(struct answer * node, int depth, enum case_state current_player)
{
	if (depth <= 0)
		return ;
	fill_turn_node(node, current_player);
	for (int i = 0; i < get_width(); i++)
	{
		if (node->next[i])
			compute_whole_game(node->next[i], depth - 1, switch_player(current_player));
	}
}

