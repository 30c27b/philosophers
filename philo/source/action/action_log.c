#include "philosophers.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// static size_t	timestamp_length(t_msecs timestamp)
// {
// 	size_t		count;

// 	count = 0;
// 	if (timestamp < 10)
// 		count++;
// 	else
// 	{
// 		count += timestamp_length(timestamp / 10);
// 		count += timestamp_length(timestamp % 10);
// 	}
// 	return (count);
// }

void	action_log(t_action action, t_philo *target, t_game *game)
{
	t_msecs	elapsed;
	char	*action_string;
	size_t	cursor;

	if (game->status == GS_OVER)
		return ;
	if (action == ACTION_DIED)
	{
		game->status = GS_OVER;
	}
	pthread_mutex_lock(&game->logging);
	elapsed = time_now() - game->start_time;
	action_string = action_to_string(action);
	if (game->status == GS_OVER && action != ACTION_DIED)
	{
		pthread_mutex_unlock(&game->logging);
		return ;
	}
	memset(game->buffer, '\0', BUFFER_LEN);
	cursor = 0;
	utils_printnbr(elapsed, game->buffer, &cursor);
	utils_print(" ", game->buffer, &cursor);
	utils_printnbr(target->id, game->buffer, &cursor);
	utils_print(action_string, game->buffer, &cursor);
	write(1, game->buffer, cursor);
	pthread_mutex_unlock(&game->logging);
}
