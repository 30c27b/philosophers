/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 22:20:31 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/29 13:20:30 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <limits.h>

static int	str2ul(char *string, uint64_t *number)
{
	size_t	i;

	i = 0;
	*number = 0;
	while (string[i])
	{
		if (string[i] < '0' || string[i] > '9')
			return (1);
		*number = (*number * 10) + (string[i] - '0');
		i++;
	}
	return (0);
}

int	params_parse(t_rules *rules, int argc, char **argv)
{
	uint64_t	number;

	if (str2ul(argv[1], &number))
		return (1);
	rules->number_of_philosophers = (size_t)number;
	if (str2ul(argv[2], &number))
		return (1);
	rules->time_to_die = (t_msecs)number;
	if (str2ul(argv[3], &number))
		return (1);
	rules->time_to_eat = (t_msecs)number;
	if (str2ul(argv[4], &number))
		return (1);
	rules->time_to_sleep = (t_msecs)number;
	if (argc == 6)
	{
		if (str2ul(argv[4], &number))
			return (1);
		rules->number_of_times_each_philosopher_must_eat = (ssize_t)number;
	}
	else
		rules->number_of_times_each_philosopher_must_eat = -1;
	return (0);
}
