/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 22:00:25 by ancoulon          #+#    #+#             */
/*   Updated: 2021/06/03 13:20:29 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <stdio.h>

static char	*action_to_string(t_action action)
{
	static char	*strings[5] = {"has taken a fork", "is eating",
		"is sleeping", "is thinking", "died"};

	return (strings[action]);
}

void	log_action(t_game *game, t_philo *philo, t_action action)
{
	t_msecs	elapsed;
	char	*action_string;

	if (game->status == GS_ENDED)
		return ;
	pthread_mutex_lock(&game->logging);
	elapsed = time_now() - game->start_time;
	action_string = action_to_string(action);
	printf("%llu %zu %s\n", elapsed, philo->id, action_string);
	pthread_mutex_unlock(&game->logging);
}
