/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:03:26 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/29 15:38:23 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

t_fork	*fork_new(size_t num)
{
	t_fork	*fork;

	fork = malloc(sizeof(t_fork));
	if (fork == NULL)
		return (NULL);
	memset(fork, 0, sizeof(t_fork));
	fork->num = num;
	return (fork);
}

int	fork_start(t_fork *fork)
{
	int	err;

	err = pthread_mutex_init(&(fork->mutex), NULL);
	return (err);
}
