#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

typedef enum e_game_status
{
	GS_STARTING=0,
	GS_RUNNING=1,
	GS_OVER=2
}	t_game_status;

# include "philosophers/utils.h"

# include "philosophers/rules.h"

# include "philosophers/time.h"

# include "philosophers/action.h"

# include "philosophers/fork.h"

# include "philosophers/philo.h"

# include "philosophers/game.h"

#endif
