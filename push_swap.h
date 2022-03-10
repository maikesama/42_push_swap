/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:32:48 by mpaci             #+#    #+#             */
/*   Updated: 2021/11/10 15:32:56 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "./lib/libft/libft.h"
# include "./lib/ft_printf/ft_printf.h"

typedef struct s_args
{
	int		ac;
	char	**av;
}				t_args;

typedef struct s_stack
{
	int	*arr;
	int	size;
}				t_stack;

typedef struct s_errors
{
	int			pos;
	int			cnt;
	int			neg;
	char		*tmp;
}				t_err;

typedef struct s_operations
{
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	int			rr;
	int			rrr;
}				t_ops;

typedef struct s_dataset
{
	int			*set;
	int			set_size;
	int			sub_pos;
	int			sub_cnt;
	int			sub_size;
	int			opt_pos;
	int			total_ops;
	t_ops		*ops;
}				t_data;

int		init_args(t_args *args, int argc, char **argv);
int		error_check(t_args *args);
int		ft_set(t_data *data, t_stack *init);
int 	*ft_ins_sort(int *src, int size);
int		check_double(t_data *data);
void	ft_clean_heap(char ***tmp);
void	ft_real_init(t_data *data, t_stack *init, t_stack *stack_a, t_stack *stack_b);
void	ft_init_ops(t_data *data);
int		ft_opt_submemb(t_data *data, t_stack *stk);
void	*ft_memint(const int *s, int c, int size);
void	ft_rkrs_calc(t_stack *stk_a, t_stack *stk_b, t_data *data);
void	ft_prophet(t_stack *init, t_stack *stk_a, t_stack *stk_b, t_data *data);
void	ft_rot(t_stack *stk);
void	ft_rev_rot(t_stack *stk);
void	ft_push(t_stack *src, t_stack *dst);
void	ft_swap(t_stack *stk);
int		*ft_find_biggest(t_stack *stk);
void	ft_order_b(t_data *data, t_stack *stk_b);
int		ft_ind_is_ordered(t_stack *stk);
void	ft_ind_calc(t_stack *stk_a, t_stack *stk_b, t_data *data, int vr);
int		ft_ind_is_next(t_stack *stk, t_data *data);
int		ft_ind_find_minor(t_stack *stk);
int		ft_ind_is_minor(t_stack *stk, int check);
void	ft_ind_calc(t_stack *stk_a, t_stack *stk_b, t_data *data, int vr);
void    ft_exec_ops(t_data *data, t_stack *stk_a, t_stack *stk_b, int vr);
int		*ft_ordered_position(t_stack *stk, t_data *data, int c);
#endif
