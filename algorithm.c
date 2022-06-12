#include "connect4.h"

extern struct map board;


void	print_next_turn_evals(struct answer * node)
{
	for (int i = 0; i < get_width(); i++)
	{
		ft_printf("tile %d, eval %.2f best_eval %.2f\n", i, node->eval, node->best_eval);
	}
}



void compute_game_turns(struct answer * node, int depth, enum case_state current_player)
{
	if (depth <= 0 || node->winner != empty)
		return ;

	// if (node->prev)
	// 	board.tab[node->input.y][node->input.x] = current_player;

	fill_turn_node(node, current_player);
	for (int i = 0; i < get_width(); i++)
	{

		if (node->next[i])
		{

			compute_game_turns(node->next[i], depth - 1, switch_player(current_player));

		}
	}
	// if (node->prev)
	// 	board.tab[node->input.y][node->input.x] = empty;

}


void	append_possible_paths(struct answer * node)
{
	if (is_node_leaf(node))
		compute_game_turns(node, 3, node->player);
	else
	{
		for (int i = 0; i < get_width(); i++)
		{
			if (node->next[i])
			{
				append_possible_paths(node->next[i]);
			}
		}
	}
}



void	fill_turn_node(struct answer * node, enum case_state current_player)
{
	struct coordinates turn_play;

	node->player = current_player;

//	print_turn(node);

	for (int i = 0; i < get_width(); i++)
	{
		turn_play.x = i;
		turn_play.y = get_first_empty_tile_height_in_column(i);
/*

		ft_printf("current tried pos %d %d\n", turn_play.x, turn_play.y); 
*/
		if (turn_play.y != -1) // column is full
		{
/*
			board.tab[turn_play.y][turn_play.x] = current_player;
			display_game();
			board.tab[turn_play.y][turn_play.x] = empty;
*/
			node->next[i] = allocate_answer_node(&turn_play, node, node->tab, current_player);

				
		}
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


bool is_node_leaf(struct answer *node)
{
	for (int i = 0; i < get_width(); i++)
	{
		if (node->next[i])
			return (false);
	}
	return (true);
}

int		check_winning_piece(int x, int y, enum case_state color, int streak_length)
{
    int dirx = -1;
    int diry = -1;

    while (dirx <= 1)
    {
        diry = -1;
        while (diry <= 1)
        {
            if (!(dirx == 0 && diry == 0) && test_direction(x, y, dirx , diry, streak_length, color))
                return 1;
            diry++;
        }
        dirx++;
    }
    return 0;
}



