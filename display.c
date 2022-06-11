
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
            printf("-----");
            x++;
        }
        printf("-\n");
        x = 0;
        while (x < board.width)
        {
            printf("|");
            if ( board.tab[y][x] == red)
                printf(" %s ", "🔴");
            else if ( board.tab[y][x] == empty)
                printf(" %s ", "  ");
            else
                printf(" %s ", "🟡");
            x++;
        }
        y++;
        printf("|\n");
    }
    x = 0;
    while(x < board.width)
    {
        printf("-----");
        x++;
    }
    printf("-\n");
}


    
