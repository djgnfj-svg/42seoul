/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_three_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:45 by ysong             #+#    #+#             */
/*   Updated: 2021/07/23 23:48:56 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arg_three_header_min_a(t_deque *a, int max)
{
	if (a->size == 3)
	{
		if (a->header->next->item == max)
		{
			ft_rra(a);
			ft_sa(a);
		}
	}
	else
	{
		if (a->header->next->item == max)
		{
			ft_ra(a);
			ft_sa(a);
			ft_rra(a);
		}
	}
}

static void	arg_three_middle_min_a(t_deque *a, int max)
{
	if (a->size == 3)
	{
		if (a->tailer->item == max)
			ft_sa(a);
		else
			ft_ra(a);
	}
	else
	{
		ft_sa(a);
		if (a->header->next->item == max)
		{
			ft_ra(a);
			ft_sa(a);
			ft_rra(a);
		}
	}
}

static void	arg_three_tailer_min_a(t_deque *a, int max)
{
	if (a->size == 3)
	{
		if (a->header->item == max)
			ft_sa(a);
		ft_rra(a);
	}
	else
	{
		if (a->header->item == max)
			ft_sa(a);
		ft_ra(a);
		ft_sa(a);
		ft_rra(a);
		ft_sa(a);
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
