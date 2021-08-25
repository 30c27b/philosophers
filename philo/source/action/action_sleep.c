#include "philosophers/action.h"
#include "philosophers/time.h"
#include "philosophers/philo.h"
#include "philosophers/game.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void	action_sleep(t_game *game, t_philo *target)
{
	if (game->status != GS_RUNNING)
			return ;
	action_log(ACTION_SLEEPING, target, game);
	if (game->status != GS_RUNNING)
			return ;
	time_sleep(game->rules.time_to_sleep);
}
