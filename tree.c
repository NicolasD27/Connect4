#include "connect4.h"

extern t_map board;

struct answer *	allocate_answer_node(struct coordinates * coord, struct answer * prev, enum case_state ** prev_tab, enum case_state player)
{
	struct answer * new = ft_calloc(1, sizeof(struct answer));
	if (new)
	{
		new->input.x = coord->x;
		new->input.y = coord->y;
		new->eval = -1;
		new->prev = prev;
		new->tab = dup_board_tab(prev_tab);
		if (prev)
			new->tab[coord->y][coord->x] = player;
		new->eval = evaluate_board(new->tab);
		new->next = ft_calloc(get_width(), sizeof(void *));
		if (!new->next)
		{
			free(new);
			new = NULL;
		}
	}
	return (new);
}

void	deallocate_all_nodes(struct answer * node)
{
	if (!node)
		return;
	for (int i = 0; i < get_width(); ++i)
	{
		if (node->next[i])
			deallocate_all_nodes(node->next[i]);
	}
	for (int y = 0; y < get_height(); ++y)
		free(node->tab[y]);
	free(node->tab);
	free(node->next);
	node->next = NULL;
	free(node);
	node = NULL;
}

struct answer * update_tree_with_play(struct answer * node)
{
	for (int i = 0; i < get_width(); ++i)
	{
		if (node->next[i])
		{
			int x = board.last_move.x;
			int y = board.last_move.y;

			if (y == node->next[i]->input.y &&
				x == node->next[i]->input.x)
			{
				puts("found current play");
				return (node->next[i]);
			}
		}
	}
	puts("update tree should have found the play");
	return (NULL);
}


