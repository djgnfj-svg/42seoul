/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:19:15 by ysong             #+#    #+#             */
/*   Updated: 2021/07/13 11:22:04 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_item(t_item *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}

void	select_pivot(int r, t_deque *target, t_item *var)
{
	long	min;
	long	max;

	min = get_min_item(target->header, r);
	max = get_max_item(target->header, r);
	var->piv_big = (min + max) / 2;
	var->piv_small = (min + var->piv_big) / 2;
}

void	push_swap(t_deque *a, t_deque *b)
{
	int	cnt;

	cnt = 0;
	if (a->size == 5)
		handle_arg_five(a, b);
	else
		a_to_b(a->size, a, b, &cnt);
}
