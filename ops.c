#include "push_swap.h"

void	ft_init_ops(t_data *data)
{
	data->ops->ra = 0;
	data->ops->rra = 0;
	data->ops->rb = 0;
	data->ops->rrb = 0;
	data->ops->rr = 0;
	data->ops->rrr = 0;
}