#include "philo_one/rules.h"
#include "philo_one/utils.h"
#include <limits.h>
#include <fcntl.h>

static int	only_digits(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

static int64_t	parse_number(char *str, uint64_t *number)
{
	uint64_t	ret;
	
	if (only_digits(str) < 0)
		return (-1);
	ret = utils_strtoul(str);
	if (ret > INT_MAX)
		return (-1);
	
}

int	rules_parse(t_rules *rules, int argc, char **argv)
{
	uint64_t	number;

	if (parse_number(argv[1], &number))
		return (1);
	rules->number_of_philosophers = (size_t)number;
	if (parse_number(argv[2], &number))
		return (1);
	rules->time_to_die = (t_msecs)number;
	if (parse_number(argv[3], &number))
		return (1);
	rules->time_to_eat = (t_msecs)number;
	if (parse_number(argv[4], &number))
		return (1);
	rules->time_to_sleep = (t_msecs)number;
	if (argc == 6)
	{
		if (parse_number(argv[4], &number))
			return (1);
		rules->number_of_times_each_philosopher_must_eat = (ssize_t)number;
	}
	else
		rules->number_of_times_each_philosopher_must_eat = -1;
	return (0);
}
