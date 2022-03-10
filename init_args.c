#include "push_swap.h"

static int	ft_sub_cnt(char ***tmp)
{
	int	i;
	int	j;
	int	cnt;
	
	i = 0;
	j = 0;
	cnt = 0;
	while (tmp[i])
	{
		while (tmp[i][j])
		{
			j++;
			cnt++;
		}
		j = 0;
		i++;
	}
	return (cnt);
}

void	ft_real_init(t_data *data, t_stack *init, t_stack *stack_a, t_stack *stack_b)
{
	float	i;
	
	stack_a->size = init->size;
	stack_b->size = 0;
	ft_memcpy(stack_a->arr, init->arr, sizeof(*stack_a->arr) * stack_a->size);
	data->sub_pos = 0;
	data->total_ops = 0;
	i = (float)data->set_size / data->sub_size;
	if (i > (int)i)
		data->sub_cnt = i + 1;
	else
		data->sub_cnt = i;
}

int	ft_cnt(t_args *args, char ***tmp)
{
	int	i;
	int	j;
	int	k;
	
	i = 0;
	j = 0;
	args->av = ft_calloc(ft_sub_cnt(tmp), sizeof(*args->av));
	if (!args->av)
		return (0);
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k])
		{
			args->av[j] = tmp[i][k];
			j++;
			k++;
		}
		i++;
	}
	ft_clean_heap(tmp);
	return (j);
}

int	init_args(t_args *args, int argc, char **argv)
{

	char	***tmp;
	int		i;

	i = 1;
	if (argc < 2)
		return (0);
	tmp = ft_calloc(argc, sizeof(*tmp));
	if (!tmp)
		return(0);
	while (argv[i])
	{
		tmp[i - 1] = ft_split(argv[i], ' ');
		i++;
	}
	args->ac = ft_cnt(args, tmp);
	if (!args->ac)
		return (0);
	return (1);
}

int	ft_set(t_data *data, t_stack *init)
{
	data->set_size = init->size;
	data->set = ft_ins_sort(init->arr, data->set_size);
	if (!data->set)
		return (0);
	data->sub_pos = 0;
	data->total_ops = 0;
	data->sub_size = 10;
		return (1);
}