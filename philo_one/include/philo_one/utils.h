#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>
# include <sys/types.h>

# define STUL_CUTOFF (UINT64_MAX / (uint64_t)10)
# define STUL_CUTLIM (UINT64_MAX % (uint64_t)10)

uint64_t	utils_strtoul(char *str);

#endif
