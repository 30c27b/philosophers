#include "philosophers/action.h"
#include "philosophers/time.h"
#include "philosophers/philo.h"
#include "philosophers/game.h"
#include "philosophers/utils.h"
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
	utils_printnbr(elapsed);
	utils_print(" ");
	utils_printnbr(target->id);
	utils_print(" ");
	utils_print(action_string);
	utils_print("\n");
	pthread_mutex_unlock(&game->logging);
}
