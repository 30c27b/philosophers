#ifndef RULES_H
# define RULES_H

# include "philo_one/time.h"
# include <sys/types.h>

typedef struct s_rules
{
	size_t	number_of_philosophers;
	t_msecs	time_to_die;
	t_msecs	time_to_eat;
	t_msecs	time_to_sleep;
	ssize_t	number_of_times_each_philosopher_must_eat;
}	t_rules;

int	rules_parse(t_rules *rules, int argc, char** argv);

#endif
