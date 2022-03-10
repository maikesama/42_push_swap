#include "push_swap.h"

void	ft_swappino(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int *ft_ins_sort(int *src, int size)
{
	int i;
	int j;
	int	n;
	int	*array;

	i = 0;
	array = ft_calloc(size, sizeof(*src));
	if (!array)
		return (0);
	ft_memcpy(array, src, sizeof(*array) * size);
	while (i < (size - 1))
	{
		n = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[n])
				n = j;
			j++;
		}
		ft_swappino(&array[n], &array[i]);
		i++;
	}
	return (array);
}