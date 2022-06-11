#ifndef CONNECT4_H
#define CONNECT4_H

#include "libft.h"

#include <stdbool.h>

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


void display_game();
void prompt_move();
int is_finished();
int print_winner(int winner);
int winning_piece(int x, int y, int color);
int is_finished();

#endif



