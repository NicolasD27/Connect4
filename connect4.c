#include "connect4.h"

t_map board;
t_transpos_table *known_board;

struct answer * current_move;


int	print_usage()
{
	ft_printf("./connect4 WIDTH HEIGHT\n");
	return 1;
}

enum case_state	choose_first_player()
{
	int res = rand();
	printf("%d\n %d\n", res, rand());
	if (res == 1)
		return red;
	else
		return yellow;
}

enum case_state switch_player(enum case_state current)
{
	if (current == red)
		return yellow;
	else
		return red;
}

void	print_turn(struct answer *node)
{
	if (node->player == red)
		puts("red plays");
	else if (node->player == yellow)
		puts("yellow plays");
	else
		puts("no one plays ?!");
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

int main(int argc, char *argv[])
{
	struct answer * node;
	int winner;
	int ai_move = 0;
	struct coordinates tmp;

	srand(time(NULL));
	if ((argc != 3) || !get_map_size(argv[1], argv[2]))
		return print_usage();

	tmp.x = -1;
	tmp.y = -1;
  
// known_board = (t_transpos_table)malloc(sizeof(t_transpos_table));
 // if (!known_board)
	// 	return 1; 
	if (allocate_board())
		display_game();
	while (1)
	{
		prompt_move();
		display_game();
		if ((winner = is_finished()) != 0)
		{
			deallocate_board();
			return print_winner(winner);
		}
		node = allocate_answer_node(&tmp, NULL, board.tab, yellow);
		compute_game_turns(node, 5, yellow);	
		ai_move = best_move(node);
		deallocate_all_nodes(node);
		add_move(ai_move);
		display_game();
		if ((winner = is_finished()) != 0)
		{
			deallocate_board();
			return print_winner(winner);
		}
	}

	return (0);
}
