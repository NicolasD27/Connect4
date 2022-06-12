#include "connect4.h"

extern t_map board;

struct answer *	allocate_answer_node(struct coordinates * coord, struct answer * prev)
{
	struct answer * new = ft_calloc(1, sizeof(struct answer));
	if (new)
	{
		new->input.x = coord->x;
		new->input.y = coord->y;
		new->eval = 0;
		new->prev = prev;
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
	if (is_node_leaf(node))
	{
		free(node->next);
		node->next = NULL;
		free(node);
		node = NULL;
		return ;
	}
	for (int i = 0; i < get_width(); ++i)
	{
		if (node->next[i])
			deallocate_answer_node(node->next[i]);
	}
	free(node->next);
	free(node);
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


