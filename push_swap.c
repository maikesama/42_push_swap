/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:33:02 by mpaci             #+#    #+#             */
/*   Updated: 2021/11/10 15:33:04 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_args *args, t_stack *stack_a, t_stack *stack_b, t_stack *init)
{
	int	i;

	i = 0;
	init->arr = ft_calloc(args->ac + 1, sizeof(*init->arr));
	stack_a->arr = ft_calloc(args->ac + 1, sizeof(*stack_a->arr));
	stack_b->arr = ft_calloc(args->ac + 1, sizeof(*stack_b->arr));
	if (!stack_a->arr || !stack_b->arr || !init->arr)
		return (0);
	init->size = args->ac;
	while(i < init->size)
	{
		init->arr[i] = ft_atoi(args->av[i]);
		i++;
	}
	return (1);
}

static void	ft_clean_stks(t_stack *init, t_data *data,
						t_stack *stk_a, t_stack *stk_b)
{
	free(init->arr);
	free(stk_a->arr);
	free(stk_b->arr);
	free(data->set);
}

static void	ft_clean_args(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->ac)
	{
		free(args->av[i]);
		i++;
	}
	free(args->av);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_args	args;
	t_stack	stack_a;
	t_stack	stack_b;
	t_stack	init;
	
	if (!init_args(&args, argc, argv) || !error_check(&args))
	{
		ft_printf("Error.\n");
		return (0);
	}
	if (!init_stack(&args, &stack_a, &stack_b, &init))
		return (0);
	if (!ft_set(&data, &init) || !check_double(&data))
		return (0);
	ft_real_init(&data, &init, &stack_a, &stack_b);
	if (ft_memcmp(stack_a.arr, data.set, sizeof(*stack_a.arr) * stack_a.size))
		ft_prophet(&init, &stack_a, &stack_b, &data);
	ft_clean_stks(&init, &data, &stack_a, &stack_b);
	ft_clean_args(&args);
	return (0);
}
