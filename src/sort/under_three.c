/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:47 by ysong             #+#    #+#             */
/*   Updated: 2021/07/13 11:33:27 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_two(t_deque *a, t_deque *b, int flag)
{
	if (flag == A)
	{
		if (a->header->item > a->header->next->item)
			swap_stack(a, A);
	}
	else
	{
		if (b->header->item < b->header->next->item)
			swap_stack(b, B);
		push_stack(b, a, A);
		push_stack(b, a, A);
	}
}

void	under_three(int r, t_deque *a, t_deque *b, int flag)
{
	if (r == 3)
	{
		if (flag == A)
			arg_three_a(r, a);
		else
			arg_three_b(r, a, b);
	}
	else if (r == 2)
		arg_two(a, b, flag);
	else if (r == 1)
	{
		if (flag == B)
			push_stack(b, a, A);
	}
}
