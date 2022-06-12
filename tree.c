#include "connect4.h"

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
	if (all_move_are_done(node))
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
