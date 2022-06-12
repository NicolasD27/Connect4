#include "connect4.h"

int		evaluate_position(int x, int y, enum case_state color)
{
	int result = 0;
	

	if (check_winning_piece(x, y, color, 4))
		result = 1000;
	else if (check_winning_piece(x, y, color, 3))
		result = 100;
	else if (check_winning_piece(x, y, color, 2))
		result = 10;
	if (color == yellow)
		result *= -1;
	return (result);
}

int evaluate_board(enum case_state ** tab)
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
				sum += evaluate_position(x, y, (int)tab[y][x]);
			x++;
		}
		y++;
	}
	return sum;
}
