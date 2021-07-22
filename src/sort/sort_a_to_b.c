/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:46 by ysong             #+#    #+#             */
/*   Updated: 2021/07/21 20:00:33 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exceptional_cases(int r, t_deque *a, t_deque *b)
{
	if (r <= 3)
	{
		under_three(r, a, b, A);
		return (0);
	}
	else if (r == 5)
	{
		hanlde_sort_five(5, a, b, A);
		return (0);
	}
	else
		return (1);
}

static void	push_rotate_a(t_deque *a, t_deque *b, t_op_count *opc)
{
	printall("rotate_a fisrt",a,b, opc);
	if (a->header->item > opc->piv_big)
	{
		rotate_stack(a, A);
		opc->ra++;
	}
	else
	{
		push_stack(a, b, B);
		opc->pb++;
		if (b->header->item > opc->piv_small)
		{
			rotate_stack(b, B);
			opc->rb++;
		}
	}
	printall("rotate_a end",a,b, opc);
}

static void	back_to_orig_ra(t_deque *a, t_deque *b, int *cnt, t_op_count *opc)
{
	int	rrr;
	int	rem;

	rrr = opc->rb;
	rem = opc->ra - rrr;
	printall("ra first",a,b, opc);
	if ((*cnt) > 0)
	{
		while (rrr--)
			reverse_rotate_all_stack(a, b);
		while (rem--)
			reverse_rotate_stack(a, A);
	}
	else
	{
		while (rrr--)
			reverse_rotate_stack(b, B);
	}
	printall("ra last",a,b, opc);
}

static void	back_to_orig_rb(t_deque *a, t_deque *b, int *cnt, t_op_count *opc)
{
	int	rrr;
	int	rem;

	rrr = opc->ra;
	rem = opc->rb - rrr;
	printall("rb first",a,b, opc);
	if ((*cnt) > 0)
	{
		while (rrr--)
			reverse_rotate_all_stack(a, b);
		while (rem--)
			reverse_rotate_stack(b, B);
	}
	else
	{
		while (rrr--)
			reverse_rotate_stack(b, B);
	}
	printall("rb last",a,b, opc);
}

// 여기서는 item을 하나의 객채로 만들고 그걸 할떄마다 초기화 하는 방식으로 했는데 다르게 하자
void	a_to_b(int r, t_deque *a, t_deque *b, int *cnt)
{
	t_op_count	opc;
	printf("여기 숫자가 있어요 r = %d\n",r);
	if (!exceptional_cases(r, a, b))
		return ;
	init_op_count(&opc);
	select_pivot(r, a, &opc);
	printall("a_to_b_first",a,b,&opc);
	while (r--)
		push_rotate_a(a, b, &opc);
	if (opc.ra > opc.rb)
		back_to_orig_ra(a, b, cnt, &opc);
	else
		back_to_orig_rb(a, b, cnt, &opc);
	printall("a_to_b_last",a,b,&opc);
	a_to_b(opc.ra, a, b, cnt);
	b_to_a(opc.rb, a, b, cnt);
	b_to_a(opc.pb - opc.rb, a, b, cnt);
}
