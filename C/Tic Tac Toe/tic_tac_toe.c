#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3

void	game(void)
{
	int	board[BOARD_SIZE][BOARD_SIZE] = {{0}};
	int	player;
	int	winner;

	player = 1;
	winner = 0;
	printf("Player one, choose a position:\nExample: 1,3\n\n");
}

int	main(void)
{
	int		sel;
	char	input[10];

	while (1)
	{
		printf("Tic Tac Toe\n");
		printf("Write 1 to play.\n");
		printf("Write 2 to exit.\n");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "1") == 0)
		{
			sel = 1;
			break ;
		}
		else if (strcmp(input, "2") == 0)
		{
			sel = 2;
			break ;
		}
		else
			printf("Invalid input.\n");
	}
	if (sel == 1)
	{
		game();
	}
	else if (sel == 2)
	{
		printf("Exit game.\n");
		return (0);
	}
}
