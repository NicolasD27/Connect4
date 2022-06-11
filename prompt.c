#include "connect4.h"

extern t_map board;

void prompt_move()
{
    char input[10];
    int x;
    int y;

    while (1)
    {

        ft_printf("\nWhat's your next move ? %d - %d\n", 1, board.width);
        read(0, &input, 10);
        x = ft_atoi(input) - 1;
        if (x < 0 || x > board.width)
            ft_printf("This column doesn't exist ...\n");
        else
        {
            y = board.height - 1;
            while (y >= 0 && board.tab[y][x] != empty)
                y--;
            if (y < 0)
                ft_printf("This column is already full !\n");
            else
            {
                ft_printf("\n");
                board.tab[y][x] = yellow;
                return;
            }
        }
    }
}
