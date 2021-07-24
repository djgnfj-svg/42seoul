/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:46 by ysong             #+#    #+#             */
/*   Updated: 2021/07/23 23:54:11 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_five_a(int size, t_deque *a, t_deque *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_item_five(a->header);
	while (size--)
	{
		if (a->header->item < mid)
		{
			ft_pb(a, b);
			push++;
		}
		else
		{
			ft_ra(a);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		ft_rra(a);
}

static void	sort_five_b(int size, t_deque *a, t_deque *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_item_five(b->header);
	while (size--)
	{
		if (b->header->item >= mid)
		{
			ft_pa(b, a);
			push++;
		}
		else
		{
			ft_rb(b);
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
		ft_rrb(b);
}

void	hanlde_sort_five(int size, t_deque *a, t_deque *b, int flag)
{
	if (flag == A)
		sort_five_a(size, a, b);
	else
		sort_five_b(size, a, b);
	arg_three_a(3, a);
	arg_two(a, b, B);
}

void	arg_five(t_deque *a, t_deque *b)
{
	int	pb;
	int	mid;

	pb = 0;
	mid = get_mid_item_five(a->header);
	while (1)
	{
		if (a->header->item < mid)
		{
			ft_pb(a, b);
			pb++;
		}
		else
			ft_ra(a);
		if (pb == 2)
			break ;
	}
	arg_three_a(3, a);
	arg_two(a, b, B);
}
