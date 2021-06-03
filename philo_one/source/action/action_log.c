#include "philo_one/action.h"
#include "philo_one/time.h"
#include "philo_one/philo.h"
#include "philo_one/game.h"
#include <pthread.h>
#include <stdio.h>

void	action_log(t_action action, t_philo *target, t_game *game)
{
	t_msecs	elapsed;
	char	*action_string;

	if (game->status == GS_OVER)
		return ;
	pthread_mutex_lock(&game->logging);
	elapsed = time_now() - game->start_time;
	action_string = action_to_string(action);
	printf("%llu %zu %s\n", elapsed, target->id, action_string);
	pthread_mutex_unlock(&game->logging);
}
