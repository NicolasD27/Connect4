
#include "connect4.h"

extern t_map board;

void display_game()
{
    int x = 0;
    int y = 0;

    while (y < board.height)
    {
        x = 0;
        while(x < board.width)
        {
            ft_printf("-----");
            x++;
        }
        ft_printf("-\n");
        x = 0;
        while (x < board.width)
        {
            ft_printf("|");
            if ( board.tab[y][x] == red)
                ft_printf(" %s ", "🔴");
            else if ( board.tab[y][x] == empty)
                ft_printf(" %s ", "  ");
            else
                ft_printf(" %s ", "🟡");
            x++;
        }
        y++;
        ft_printf("|\n");
    }
    x = 0;
    while(x < board.width)
    {
        ft_printf("-----");
        x++;
    }
    ft_printf("-\n");
}


    
