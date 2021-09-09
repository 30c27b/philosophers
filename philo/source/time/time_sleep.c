#include "philosophers.h"
#include <unistd.h>
#include <stdint.h>

void	time_sleep(t_msecs msecs)
{
	t_msecs	endt;

	endt = time_now() + msecs;
	usleep(msecs * 0.99);
	while (time_now() <= endt)
		usleep(200);
}
