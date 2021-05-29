/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:23:44 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/29 10:46:28 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

t_philo	philo_init(size_t id)
{
	t_philo	philo;

	memset(&philo, 0, sizeof(t_philo));
	philo.id = id;
	return (philo);
}

int	philo_start(t_philo *philo)
{
	int	ret;

	ret = pthread_create(&(philo->tid), NULL, &philo_lifecycle, NULL);
	if (ret)
		return (1);
	return (0);
}

void	*philo_lifecycle(void *arg)
{
	(void)arg;
	return (NULL);
}
