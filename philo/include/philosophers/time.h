#ifndef TIME_H
# define TIME_H

# include <stdint.h>

typedef uint64_t	t_msecs;

t_msecs	time_now(void);

void	time_sleep(t_msecs msecs);

#endif
