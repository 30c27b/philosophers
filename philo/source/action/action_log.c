#include "philosophers.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	action_log(t_action action, t_philo *target, t_game *game)
{
	t_msecs	elapsed;

	if (game->status == GS_OVER)
		return ;
	if (action == ACTION_DIED)
		game->status = GS_OVER;
	pthread_mutex_lock(&game->logging);
	elapsed = time_now() - game->start_time;
	if (game->status == GS_OVER && action != ACTION_DIED)
	{
		pthread_mutex_unlock(&game->logging);
		return ;
	}
	utils_printnbr(elapsed);
	write(1, " ", 1);
	utils_printnbr(target->id);
	action_to_string(action);
	pthread_mutex_unlock(&game->logging);
}
