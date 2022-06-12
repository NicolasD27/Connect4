#include "connect4.h"

t_map board;
t_transpos_table *known_board;

enum case_state player_color;
enum case_state ia_color;
enum case_state current_player;


struct answer * current_move;


int	print_usage()
{
	ft_printf("./connect4 WIDTH HEIGHT\n");
	return 1;
}

void	choose_first_player()
{
	if (rand() % 2)
	{
		ft_printf("IA starts !\n");
		player_color = red;
		ia_color = yellow;
	}
	else
	{
		ft_printf("You start !\n");
		player_color = yellow;
		ia_color = red;
	}
	current_player = yellow;
}

enum case_state switch_player(enum case_state current)
{
	if (current == red)
		return yellow;
	else
		return red;
}

void add_move(int move)
{
	int y;
	y = board.height - 1;
	while (y >= 0 && board.tab[y][move] != empty)
	{
		y--;
	}
	if (y >= 0)
	{
		board.tab[y][move] = red;
		board.last_move.x = move;
		board.last_move.y = y;
	}
}

int print_winner(int winner)
{
    if (winner == (int)player_color)
        ft_printf("YOU WON !");
    else
        ft_printf("IA WON !");
    return 0;
}


int main(int argc, char *argv[])
{
	struct answer * node;
	int winner;
	int ai_move = 0;
	struct coordinates tmp;
	tmp.x = -1;
	tmp.y = -1;

	srand(time(NULL));
	if ((argc != 3) || !get_map_size(argv[1], argv[2]))
		return print_usage();

	choose_first_player();
	allocate_board();
	while (1)
	{
		if (current_player == player_color)
			prompt_move();
		else
		{
			node = allocate_answer_node(&tmp, NULL, board.tab, ia_color);
			compute_game_turns(node, 5, ia_color);	
			ai_move = best_move(node);
			deallocate_all_nodes(node);
			add_move(ai_move);
		}
		display_game();
		if ((winner = is_finished()) != 0)
			break ;
		current_player = switch_player(current_player);
	}
	deallocate_board();
	return (print_winner(current_player));
}
