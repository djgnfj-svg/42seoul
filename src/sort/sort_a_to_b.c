/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:46 by ysong             #+#    #+#             */
/*   Updated: 2022/01/10 07:48:54 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exceptional_cases(int r, t_deque *a, t_deque *b)
{
	if (r <= 3)
		under_three(r, a, b, A);
	else if (r == 5)
		hanlde_sort_five(5, a, b, A);
	else
		return (1);
	return (0);
}

static void	push_rotate_a(t_deque *a, t_deque *b, t_op_count *opc)
{

	if (a->header->item > opc->piv_big)
	{
		ft_ra(a);
		opc->ra++;
	}
	else
	{
		ft_pb(a, b);
		opc->pb++;
		if (b->header->item > opc->piv_small)
		{
			ft_rb(b);
			opc->rb++;
		}
	}
}

static void	back_to_orig(t_deque *a, t_deque *b, int *cnt, t_op_count *opc)
{
	int	rrr;
	int	rem;

	rrr = opc->ra;
	rem = opc->rb - rrr;
	if (opc->ra > opc->rb)
	{
		rrr = opc->rb;
		rem = opc->ra - rrr;
	}
	if ((*cnt) > 0)
	{
		while (rrr--)
			ft_rrr(a, b);
		if (opc->ra > opc->rb)
			while (rem--)
				ft_rra(a);
		else
			while (rem--)
				ft_rrb(b);
		return ;
	}
	rrr = opc->rb;
	while (rrr--)
		ft_rrb(b);
}

void	a_to_b(int r, t_deque *a, t_deque *b, int *cnt)
{
	int			r_temp;
	t_op_count	opc;

	if (!exceptional_cases(r, a, b))
		return ;
	init_op_count(&opc);
	select_pivot(r, a, &opc);
	r_temp = r;
	while (r_temp--)
		push_rotate_a(a, b, &opc);
	back_to_orig(a, b, cnt, &opc);
	a_to_b(opc.ra, a, b, cnt);
	b_to_a(opc.rb, a, b, cnt);
	b_to_a(opc.pb - opc.rb, a, b, cnt);
}
