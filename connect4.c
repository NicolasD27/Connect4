#include "connect4.h"

t_map board;

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

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int winner;
	if ((argc != 3) || !get_map_size(argv[1], argv[2]))
		return print_usage();

	struct coordinates tmp;
	tmp.x = 0;
	tmp.y = 0;

	if (allocate_board())
		display_game();

//	int ai_move = best_move(node);
//	ft_printf("ai move : %d\n", ai_move);
	while (1)
	{
		prompt_move();
		display_game();
		struct answer * node = allocate_answer_node(&tmp, NULL);
		compute_whole_game(node, 3, red);
		print_turn(node);
		deallocate_answer_node(node);

		if ((winner = is_finished()) != 0)
		{
			deallocate_board();
			return print_winner(winner);
		}
	}

	return (0);
}
