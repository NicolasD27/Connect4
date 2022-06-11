#ifndef CONNECT4_H
# define  CONNECT4_H

#include "libft.h"

#include <stdbool.h>
#include <time.h>

#define MIN_WIDTH 7
#define MIN_HEIGHT 6

enum case_state {
	empty = 0,
	red,
	yellow
};

struct	coordinates {
	int		x;
	int		y;
};

typedef struct map {

	enum case_state **	tab;
	
	int		height;
	int		width;
}				t_map;

struct	answer {
	enum case_state		player;
	enum case_state		winner;
	struct coordinates	input;
	struct answer		**next;
};

void	display_game();

int		get_width();
int		get_height();

void	compute_whole_game(struct answer * node, int depth, enum case_state current_player);
void	fill_turn_node(struct answer * node, enum case_state current_player);
int		get_first_empty_tile_height_in_column(int column);

struct answer *	allocate_answer_node(struct coordinates * coord);

enum case_state switch_player(enum case_state current);
enum case_state	choose_first_player();


#endif
