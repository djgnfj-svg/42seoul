/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:42 by ysong             #+#    #+#             */
/*   Updated: 2022/01/10 08:05:00 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exceptional_cases(int r, t_deque *a, t_deque *b)
{
	if (r <= 3)
	{
		under_three(r, a, b, B);
		return (0);
	}
	else if (r == 5)
	{
		hanlde_sort_five(5, a, b, B);
		return (0);
	}
	else
		return (1);
}

static void	push_rotate_b(t_deque *a, t_deque *b, t_op_count *opc)
{
	printall("rotate_b fisrt",a,b, opc);
	if (b->header->item <= opc->piv_small)
	{
		ft_rb(b);
		opc->rb++;
	}
	else
	{
		ft_pa(b, a);
		opc->pa++;
		if (a->header->item <= opc->piv_big)
		{
			ft_ra(a);
			opc->ra++;
		}
	}
	printall("rotate_b last",a,b, opc);
}

static void	back_to_orig(t_deque *a, t_deque *b, t_op_count *opc)
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
	while (rrr--)
		ft_rrr(a, b);
	if (opc->ra > opc->rb)
		while (rem--)
			ft_rra(a);
	else
		while (rem--)
			ft_rrb(b);
}

void	b_to_a(int r, t_deque *a, t_deque *b, int *cnt)
{
	int			r_temp;
	t_op_count	opc;

	(*cnt)++;
	printf("여기 숫자가 있어요 r = %d\n",r);
	if (!exceptional_cases(r, a, b))
		return ;
	init_op_count(&opc);
	select_pivot(r, b, &opc);
	r_temp = r;
	while (r_temp--)
		push_rotate_b(a, b, &opc);
	a_to_b(opc.pa - opc.ra, a, b, cnt);
	back_to_orig(a, b, &opc);
	a_to_b(opc.ra, a, b, cnt);
	b_to_a(opc.rb, a, b, cnt);
}
