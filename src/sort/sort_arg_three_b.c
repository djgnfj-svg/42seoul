/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_three_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:44 by ysong             #+#    #+#             */
/*   Updated: 2021/07/17 14:48:20 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arg_three_header_min_b(t_deque *b, int max)
{
	if (b->size == 3)
	{
		rotate_stack(b, B);
		if (b->header->next->item == max)
			swap_stack(b, B);
	}
	else
	{
		swap_stack(b, B);
		rotate_stack(b, B);
		swap_stack(b, B);
		reverse_rotate_stack(b, B);
		if (b->header->next->item == max)
			swap_stack(b, B);
	}
}

static void	arg_three_middle_min_b(t_deque *b, int max)
{
	if (b->size == 3)
	{
		reverse_rotate_stack(b, B);
		if (b->header->next->item == max)
			swap_stack(b, B);
	}
	else
	{
		rotate_stack(b, B);
		swap_stack(b, B);
		reverse_rotate_stack(b, B);
		if (b->header->next->item == max)
			swap_stack(b, B);
	}
}

void	arg_three_bottom_min_b(t_deque *b, int max)
{
	if (b->header->next->item == max)
		swap_stack(b, B);
}

void	arg_three_b(int r, t_deque *a, t_deque *b)
{
	int	min;
	int	max;

	min = get_min_item(b->header, r);
	max = get_max_item(b->header, r);
	if (b->header->item == min)
		arg_three_header_min_b(b, max);
	else if (b->header->next->item == min)
		arg_three_middle_min_b(b, max);
	else if (b->header->next->next->item == min)
		arg_three_bottom_min_b(b, max);
	push_stack(b, a, A);
	push_stack(b, a, A);
	push_stack(b, a, A);
}
