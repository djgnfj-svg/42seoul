/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:19:15 by ysong             #+#    #+#             */
/*   Updated: 2021/07/21 14:27:22 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_op_count(t_op_count *opc)
{
	opc->ra = 0;
	opc->rb = 0;
	opc->pa = 0;
	opc->pb = 0;
}

void	select_pivot(int r, t_deque *target, t_op_count *opc)
{
	long	min;
	long	max;

	min = get_min_item(target->header, r);
	max = get_max_item(target->header, r);
	opc->piv_big = (min + max) / 2;
	opc->piv_small = (min + opc->piv_big) / 2;
}

void	push_swap(t_deque *a, t_deque *b)
{
	int	cnt;

	cnt = 0;
	if (a->size == 2)
		arg_two(a, b, A);
	else if (a->size == 3)
		arg_three_a(3, a);
	else if (a->size == 5)
		arg_five(a, b);
	else
		a_to_b(a->size, a, b, &cnt);
}
