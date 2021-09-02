#include "philosophers.h"
#include <unistd.h>
#include <stdint.h>

void	time_sleep(t_msecs msecs, t_game_status *gs)
{
	t_msecs	endt;

	endt = time_now() + msecs;
	usleep(msecs / 2);
	while (time_now() < endt && *gs == GS_RUNNING)
		usleep(50);
}
