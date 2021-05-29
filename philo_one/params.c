/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 22:20:31 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/29 10:52:34 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <limits.h>

static int64_t	philo_str2int(char *string, int64_t *number)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	*number = 0;
	if (string[i] == '+')
		i++;
	else if (string[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (string[i])
	{
		if (string[i] < '0' || string[i] > '9')
			return (1);
		*number = (*number * 10) + (string[i] - '0');
		i++;
	}
	return (*number * sign);
}

int	params_parse(t_rules *rules, int argc, char **argv)
{
	return (1);
}
