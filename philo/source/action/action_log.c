#include "philosophers.h"
#include <pthread.h>
#include <unistd.h>

void	action_log(t_action action, t_philo *target, t_game *game)
{
	t_msecs	elapsed;
	char	*action_string;

	if (game->status == GS_OVER)
		return ;
	if (action == ACTION_DIED)
	{
		game->status = GS_OVER;
	}
	elapsed = time_now() - game->start_time;
	action_string = action_to_string(action);
	pthread_mutex_lock(&game->logging);
	if (game->status == GS_OVER && action != ACTION_DIED)
	{
		pthread_mutex_unlock(&game->logging);
		return ;
	}
	utils_printnbr(elapsed);
	write(1, " ", 1);
	utils_printnbr(target->id);
	utils_print(action_string);
	pthread_mutex_unlock(&game->logging);
}
