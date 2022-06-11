#include "connect4.h"

extern t_map board;

int is_finished()
{
    int x;
    int y = 0;

    while (y < board.height)
    {
        x = 0;
        while(x < board.width)
        {                
            if (board.tab[y][x] != empty && winning_piece(x, y, board.tab[y][x]))
                return board.tab[y][x];
            x++;
        }
        y++;
    }
    return 0;
}

int test_direction(int x, int y, int dirx, int diry, int streak_length, enum case_state color)
{
    if (streak_length == 1)
        return 1;
    else
    {
        if (x + dirx >= 0 && x + dirx < board.width && y + diry >= 0 && y + diry < board.height && (int)board.tab[y + diry][x + dirx] == color)
            return test_direction(x + dirx, y + diry, dirx , diry, streak_length - 1, color);
    }
	return 0;
}


int winning_piece(int x, int y, enum case_state color)
{
    int dirx = -1;
    int diry = -1;

    while (dirx <= 1)
    {
        diry = -1;
        while (diry <= 1)
        {
            if (!(dirx == 0 && diry == 0) && test_direction(x, y, dirx , diry, WINNING_STREAK_LENGTH, color))
                return 1;
            diry++;
        }
        dirx++;
    }
    return 0;
}

int print_winner(int winner)
{
    if (winner == red)
        ft_printf("RED WON !");
    else
        ft_printf("YELLOW WON !");
    return 0;
}
