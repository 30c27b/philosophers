#include "philosophers.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_game	*game;

	if (rules_parse(&rules, argc, argv) < 0)
	{
		fprintf(stderr, "Error\n");
		return (1);
	}
	game = game_new(rules);
	if (game == NULL)
	{
		fprintf(stderr, "Error\n");
		return (1);
	}
	if (game_start(game) < 0)
	{
		fprintf(stderr, "Error\n");
		return (1);
	}
	return (0);
}