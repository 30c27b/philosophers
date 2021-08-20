#include "philosophers/rules.h"
#include "philosophers/utils.h"
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

static uint64_t	parse_number(char *str, int *err)
{
	uint64_t	ret;
	
	if (only_digits(str) < 0)
	{
		*err = -1;
		return (0);
	}
	ret = utils_strtoul(str);
	if (ret > INT_MAX)
	{
		*err = -1;
		return (0);
	}
	*err = 0;
	return (ret);
}

int	rules_parse(t_rules *rules, int argc, char **argv)
{
	int	err;

	if (argc < 5 || argc > 6)
		return (-1);
	rules->number_of_philosophers = parse_number(argv[1], &err);
	if (err)
		return (err);
	rules->time_to_die = parse_number(argv[2], &err);
	if (err)
		return (err);
	rules->time_to_eat = parse_number(argv[3], &err);
	if (err)
		return (err);
	rules->time_to_sleep = parse_number(argv[4], &err);
	if (err)
		return (err);
	if (argc == 6)
	{
		rules->number_of_times_each_philosopher_must_eat = parse_number(argv[5], &err);
		if (err)
			return (err);
	}
	else
		rules->number_of_times_each_philosopher_must_eat = -1;
	return (0);
}
