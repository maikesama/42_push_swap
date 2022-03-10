#include "push_swap.h"

void	*ft_memint(const int *s, int c, int size)
{
	const int	*ptr;
	ptr = s;
	while (size--)
	{
		if (*ptr == c)
			return ((int *)ptr);
		ptr++;
	}
	return (0);
}