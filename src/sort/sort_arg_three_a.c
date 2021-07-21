/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_three_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:45 by ysong             #+#    #+#             */
/*   Updated: 2021/07/17 14:48:20 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arg_three_header_min_a(t_deque *a, int max)
{
	if (a->size == 3)
	{
		if (a->header->next->item == max)
		{
			reverse_rotate_stack(a, A);
			swap_stack(a, A);
		}
	}
	else
	{
		if (a->header->next->item == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate_stack(a, A);
		}
	}
}

static void	arg_three_middle_min_a(t_deque *a, int max)
{
	if (a->size == 3)
	{
		if (a->tailer->item == max)
			swap_stack(a, A);
		else
			rotate_stack(a, A);
	}
	else
	{
		swap_stack(a, A);
		if (a->header->next->item == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate_stack(a, A);
		}
	}
}

static void	arg_three_tailer_min_a(t_deque *a, int max)
{
	if (a->size == 3)
	{
		if (a->header->item == max)
			swap_stack(a, A);
		reverse_rotate_stack(a, A);
	}
	else
	{
		if (a->header->item == max)
			swap_stack(a, A);
		rotate_stack(a, A);
		swap_stack(a, A);
		reverse_rotate_stack(a, A);
		swap_stack(a, A);
	}
}

void	arg_three_a(int r, t_deque *a)
{
	int	min;
	int	max;

	min = get_min_item(a->header, r);
	max = get_max_item(a->header, r);
	if (a->header->item == min)
		arg_three_header_min_a(a, max);
	else if (a->header->next->item == min)
		arg_three_middle_min_a(a, max);
	else if (a->header->next->next->item == min)
		arg_three_tailer_min_a(a, max);
}
