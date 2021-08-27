#include "philosophers.h"
#include <unistd.h>
#include <stdlib.h>

static int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_game	*game;

	if (argc < 5 || argc > 6)
		return (print_error());
	if (rules_parse(&rules, argc, argv) < 0)
		return (print_error());
	game = game_new(rules);
	if (game == NULL)
		return (print_error());
	if (game_start(game) < 0)
		return (print_error());
	game_destroy(game);
	return (0);
}
