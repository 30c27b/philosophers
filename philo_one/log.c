/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 22:00:25 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/29 10:57:29 by ancoulon         ###   ########.fr       */
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

void	log_action(t_game game, t_philo *philo, t_action action)
{
	t_msecs	now;
	char	*action_string;

	now = time_now();
	action_string = action_to_string(action);
	printf("%ul %zu %s\n", now, philo->id, action_string);
}
