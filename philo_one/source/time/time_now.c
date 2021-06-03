#include "philo_one/time.h"
#include <sys/time.h>

t_msecs	time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000UL) + (tv.tv_usec / 1000));
}
