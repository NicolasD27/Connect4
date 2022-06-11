#ifndef CONNECT4_H
# define  CONNECT4_H

#include "libft.h"

#include <stdbool.h>
#include <time.h>

#define MIN_WIDTH 7
#define MIN_HEIGHT 6
#define WINNING_STREAK_LENGTH 4

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
	float				eval;
	float				best_eval;
	struct answer		*prev;

	struct answer		**next;
};

void display_game();
void prompt_move();
int is_finished();
int print_winner(int winner);
int winning_piece(int x, int y, enum case_state color);
int is_finished();


int test_direction(int x, int y, int dirx, int diry, int streak_length, int color);

int		get_width();
int		get_height();

void	compute_whole_game(struct answer * node, int depth, enum case_state current_player);
void	fill_turn_node(struct answer * node, enum case_state current_player);
int		get_first_empty_tile_height_in_column(int column);

int best_move(struct answer *node);

struct answer *	allocate_answer_node(struct coordinates * coord, struct answer * node);

enum case_state switch_player(enum case_state current);
enum case_state	choose_first_player();


#endif
