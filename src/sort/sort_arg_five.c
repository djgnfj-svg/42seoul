/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:46 by ysong             #+#    #+#             */
/*   Updated: 2021/07/17 14:48:20 by ysong            ###   ########.fr       */
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
			push_stack(a, b, B);
			push++;
		}
		else
		{
			rotate_stack(a, A);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		reverse_rotate_stack(a, A);
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
			push_stack(b, a, A);
			push++;
		}
		else
		{
			rotate_stack(b, B);
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
		reverse_rotate_stack(b, B);
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
			push_stack(a, b, B);
			pb++;
		}
		else
			rotate_stack(a, A);
		if (pb == 2)
			break ;
	}
	arg_three_a(3, a);
	arg_two(a, b, B);
}
