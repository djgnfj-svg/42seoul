/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:42 by ysong             #+#    #+#             */
/*   Updated: 2021/07/21 19:51:42 by ysong            ###   ########.fr       */
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
	if (b->header->item <= opc->piv_small)
	{
		rotate_stack(b, B);
		opc->rb++;
	}
	else
	{
		push_stack(b, a, A);
		opc->pa++;
		if (a->header->item <= opc->piv_big)
		{
			rotate_stack(a, A);
			opc->ra++;
		}
	}
}

static void	back_to_orig_ra(t_deque *a, t_deque *b, t_op_count *opc)
{
	int	rrr;
	int	rem;

	rrr = opc->rb;
	rem = opc->ra - rrr;
	while (rrr--)
		reverse_rotate_all_stack(a, b);
	while (rem--)
		reverse_rotate_stack(a, A);
}

static void	back_to_orig_rb(t_deque *a, t_deque *b, t_op_count *opc)
{
	int	rrr;
	int	rem;

	rrr = opc->ra;
	rem = opc->rb - rrr;
	while (rrr--)
		reverse_rotate_all_stack(a, b);
	while (rem--)
		reverse_rotate_stack(b, B);
}

void	b_to_a(int r, t_deque *a, t_deque *b, int *cnt)
{
	int		r_temp;
	t_op_count	opc;

	(*cnt)++;
	if (!exceptional_cases(r, a, b))
		return ;
	init_op_count(&opc);
	select_pivot(r, b, &opc);
	printall("b_to_a_first",a,b,&opc);
	r_temp = r;
	while (r_temp--)
		push_rotate_b(a, b, &opc);
	a_to_b(opc.pa - opc.ra, a, b, cnt);
	if (opc.ra > opc.rb)
		back_to_orig_ra(a, b, &opc);
	else
		back_to_orig_rb(a, b, &opc);
	a_to_b(opc.ra, a, b, cnt);
	b_to_a(opc.rb, a, b, cnt);
}
