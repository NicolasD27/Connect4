#include "connect4.h"

extern struct map board;
int		evaluate_position(int x, int y, int color);

void	print_next_turn_evals(struct answer * node)
{
	for (int i = 0; i < get_width(); i++)
	{
		ft_printf("tile %d, eval %.2f best_eval %.2f\n", i, node->eval, node->best_eval);
	}
}


void	fill_turn_node(struct answer * node, enum case_state current_player)
{
	struct coordinates turn_play;

	node->player = current_player;
	print_turn(node);
	for (int i = 0; i < get_width(); i++)
	{
		turn_play.x = i;
		turn_play.y = get_first_empty_tile_height_in_column(i);
		
		if (turn_play.y != -1) // column is full
		{
			node->next[i] = allocate_answer_node(&turn_play, node);
			if (node->next[i])
				node->next[i]->eval = evaluate_position(turn_play.x, turn_play.y, current_player);
				
		}
		else
			node->next[i] = NULL;
	}
	print_next_turn_evals(node);
}

void sum_evals(struct answer *node, int depth)
{
	float sum;
	if (!(node->next))
	{
		sum = 0;
		while (node->prev && node->prev->prev)
		{
			sum += node->eval * 1 / (float)depth;
			node = node->prev;
		}
		if (node->eval + sum > node->best_eval)
			node->best_eval = node->eval + sum;
		return;
	}
	int i = 0;
	while (i < board.width)
	{
		if (node->next[i])
			sum_evals(node->next[i], depth + 1);
		i++;
	}
}

int best_move(struct answer *node)
{
	int i = 0;
	int max = 0;
	int best_move = 0;

	sum_evals(node, 0);
	while (i < board.width)
	{
		if (node->next[i] && node->next[i]->best_eval >= max)
		{
			best_move = node->next[i]->input.x;
			max = node->next[i]->best_eval;
		}
		i++;
	}
	return best_move;
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

int		check_winning_piece(int x, int y, int color, int streak_length)
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

int		evaluate_position(int x, int y, int color)
{
	int result = 0;
	
	if (check_winning_piece(x, y, color, 4))
		result = 200;
	else if (check_winning_piece(x, y, color, 3))
		result = 100;
	else if (check_winning_piece(x, y, color, 2))
		result = 50;
	else
		result = 10;
	return (result);
}

int	evaluate_answer_node(struct answer * node)
{
	int best_option = -1;
	int score = 0;
	int	node_eval = 0;
	for (int i = 0; i < get_width(); ++i)
	{
		node_eval = evaluate_position(node->input.x, node->input.y, node->player);
		if (node_eval > score)
		{
			score = node_eval;
			best_option = i;
		}
	}
	return (best_option);
}

void	update_answer_tree()
{
	
}
