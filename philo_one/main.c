/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:40:28 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/29 11:58:19 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_game	*game;
	int		err;

	if (argc < 5 || argc > 6)
		return (1);
	err = params_parse(&rules, argc, argv);
	if (err)
		return (1);
	game = game_new(rules);
	if (game == NULL)
		return (1);
	err = game_start(game);
	if (err)
		return (1);
	return (0);
}
