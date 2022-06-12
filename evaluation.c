#include "connect4.h"

extern t_map board;
extern struct answer *winner_node;


int		evaluate_position(int x, int y, enum case_state color, struct answer *node)
{
	int result = 0;
	

	if (check_winning_piece(x, y, color, 4))
	{
		node->winner = color;
		result = 1000;
	}
	else if (check_winning_piece(x, y, color, 3))
		result = 100;
	else if (check_winning_piece(x, y, color, 2))
		result = 10;
	// if (color == yellow)
	// 	result *= -1;
	return (result);
}

int evaluate_board(enum case_state ** tab, struct answer *node)
{
	int x;
	int y = 0;
	int sum = 0;
	
	while (y < get_height())
	{
		x = 0;
		while (x < get_width())
		{
			if (tab[y][x] != empty)
				sum += evaluate_position(x, y, tab[y][x], node);
			x++;
		}
		y++;
	}
	return sum;
}

void sum_evals(struct answer *node, int depth)
{
	float sum;
	if (!node)
		return;
	if (is_node_leaf(node))
	{
		sum = 0;
		while (1)
		{
			// if (node->eval < 0)
			// 	node->eval = evaluate_position(node->input.x, node->input.y, red);
			sum += node->eval * 1 ;

			if (!node->prev->prev) //si on est juste avant la racine on quitte
				break;
			node = node->prev;
		}
		if (sum > node->best_eval)
		{
			node->best_eval = sum;
		}
		return ;
	}
	int i = 0;
	while (i < board.width)
	{
		if (node->next[i])
		{
            if (node->next[i]->winner != empty)
            {
                if (!winner_node || (((winner_node->depth > depth) || (winner_node->depth + 1 == depth && winner_node->winner == yellow))))
                {
                    winner_node = node->next[i];
                    winner_node->depth = depth;
					if (winner_node->winner == yellow)
						ft_printf("possible winner move for yellow: %d at depth : %d\n" , node->next[i]->input.x, depth);
					else
						ft_printf("possible winner move for red: %d at depth : %d\n" , node->next[i]->input.x, depth);
					if (depth > 1)
						return;
                }
            }
			sum_evals(node->next[i], depth + 1);
		}
		i++;
	}
}

int best_move(struct answer *node)
{
	int i = 0;
	float max = -1;
	int best_move = 0;

	sum_evals(node, 0);
    if (winner_node)
    {
		if (winner_node->winner == yellow)
		{
			if (winner_node->depth == 1)
			{
				ft_printf("protect %d\n depth : %d\n", winner_node->input.x, winner_node->depth);
				return winner_node->input.x;
			}
		}
		else
		{
			int i = 0;
			while (i++ < winner_node->depth - 1)
				winner_node = winner_node->prev;
			ft_printf("red can win %d\n depth : %d\n", winner_node->input.x, winner_node->depth);
			return winner_node->input.x;
		}
		
    }
	while (i < board.width)
	{
		
		if (node->next[i] && node->next[i]->best_eval >= max)
		{
			best_move = node->next[i]->input.x;
			max = node->next[i]->best_eval;
		}
		i++;
	}
	ft_printf("best eval %f for move in %d\n", max, best_move);
	return best_move;
}
