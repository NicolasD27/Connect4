#ifndef CONNECT4_H
# define  CONNECT4_H

#include "libft.h"

#include <stdbool.h>

#define MIN_WIDTH 7
#define MIN_HEIGHT 6

enum case_state {
	empty = 0,
	red,
	black
};

struct	coordinates {
	int		x;
	int		y;
};

struct	map {
	enum case_state **	tab;
	
	int		height;
	int		width;
};

struct	answer {
	struct coordinates	input;
	struct answer		**next;
};

#endif
