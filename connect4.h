#ifndef CONNECT4_H
# define  CONNECT4_H

#include "libft.h"

#include <stdbool.h>
#include <time.h>

#define MIN_WIDTH 2
#define MIN_HEIGHT 2
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

	struct coordinates		last_move;
}				t_map;

struct	answer {
	enum case_state		player;
	enum case_state		winner;
	struct coordinates	input;
	enum case_state **	tab;
	float				eval;
	float				best_eval;
	struct answer		*prev;

	struct answer		**next;
};

typedef struct	s_transpos_table { 
	float eval;
	t_map board;
	struct	s_transpos_table * next;
}				t_transpos_table;


void display_game();
void prompt_move();
int is_finished();
int print_winner(int winner);
int winning_piece(int x, int y, enum case_state color);
int is_finished();

//	board
bool	get_map_size(char *arg1, char *arg2);
bool	allocate_board();
void	deallocate_board();
void	deallocate_map(t_map * map);
bool	board_are_same(t_map * dst, t_map * src);

int test_direction(int x, int y, int dirx, int diry, int streak_length, enum case_state color);


int		get_width();
int		get_height();

//int test_direction(int x, int y, int dirx, int diry, int streak_length, int color);

void	compute_game_turns(struct answer * node, int depth, enum case_state current_player);
void	append_possible_paths(struct answer * node);
void	fill_turn_node(struct answer * node, enum case_state current_player);
int		get_first_empty_tile_height_in_column(int column);


bool is_node_leaf(struct answer *node);

enum case_state switch_player(enum case_state current);

//	tree
void	deallocate_answer_node(struct answer * node);

int evaluate_board(enum case_state ** tab);
int		evaluate_position(int x, int y, enum case_state color);
int best_move(struct answer *node);

struct answer *	allocate_answer_node(struct coordinates * coord, struct answer * prev, enum case_state ** prev_tab, enum case_state player);

enum case_state switch_player(enum case_state current);
enum case_state	choose_first_player();

struct answer * update_tree_with_play(struct answer * node);


//debug
void	print_turn(struct answer *node);

#endif
