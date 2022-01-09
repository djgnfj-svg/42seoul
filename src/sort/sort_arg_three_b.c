/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_three_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:44 by ysong             #+#    #+#             */
/*   Updated: 2021/07/23 23:54:11 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arg_three_header_min_b(t_deque *b, int max)
{
	if (b->size == 3)
	{
		ft_rb(b);
		if (b->header->next->item == max)
			ft_sb(b);
	}
	else
	{
		ft_sb(b);
		ft_rb(b);
		ft_sb(b);
		ft_rrb(b);
		if (b->header->next->item == max)
			ft_sb(b);
	}
}

static void	arg_three_middle_min_b(t_deque *b, int max)
{
	if (b->size == 3)
	{
		ft_rrb(b);
		if (b->header->next->item == max)
			ft_sb(b);
	}
	else
	{
		ft_rb(b);
		ft_sb(b);
		ft_rrb(b);
		if (b->header->next->item == max)
			ft_sb(b);
	}
}

void	arg_three_bottom_min_b(t_deque *b, int max)
{
	if (b->header->next->item == max)
		ft_sb(b);
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
	ft_pa(b, a);
	ft_pa(b, a);
	ft_pa(b, a);
}
