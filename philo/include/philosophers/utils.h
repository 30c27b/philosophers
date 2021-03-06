#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>
# include <sys/types.h>

# define STUL_CUTOFF (1844674407370955161ULL)
# define STUL_CUTLIM (5ULL)

uint64_t	utils_strtoul(char *str);

void		utils_printnbr(uint64_t nbr, char *dest, size_t	*cursor);

void		utils_print(char *str, char *dest, size_t *cursor);
#endif
