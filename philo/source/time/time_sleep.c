#include "philosophers/time.h"
#include <unistd.h>

void	time_sleep(t_msecs msecs)
{
	while (msecs > 0)
	{
		usleep(1000);
		msecs--;
	}
}
