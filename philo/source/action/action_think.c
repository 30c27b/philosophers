#include "philosophers/action.h"
#include "philosophers/time.h"
#include "philosophers/philo.h"
#include "philosophers/game.h"
#include <pthread.h>

void	action_think(t_game *game, t_philo * target)
{
	action_log(ACTION_THINKING, target, game);
}
