/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:25:42 by ysong             #+#    #+#             */
/*   Updated: 2021/07/14 01:21:13 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exceptional_cases(int r, t_deque *a, t_deque *b)
{
	if (r <= 3)
	{
		handle_under_three(r, a, b, B);
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

static void	push_rotate_b(t_deque *a, t_deque *b, t_item *var)
{
	if (b->header->item <= var->piv_small)
	{
		rotate_stack(b, B);
		var->rb++;
	}
	else
	{
		push_stack(b, a, A);
		var->pa++;
		if (a->header->item <= var->piv_big)
		{
			rotate_stack(a, A);
			var->ra++;
		}
	}
}

static void	back_to_orig_ra(t_deque *a, t_deque *b, t_item *var)
{
	int	rrr;
	int	rem;

	rrr = var->rb;
	rem = var->ra - rrr;
	while (rrr--)
		reverse_rotate_all_stack(a, b);
	while (rem--)
		reverse_rotate_stack(a, A);
}

static void	back_to_orig_rb(t_deque *a, t_deque *b, t_item *var)
{
	int	rrr;
	int	rem;

	rrr = var->ra;
	rem = var->rb - rrr;
	while (rrr--)
		reverse_rotate_all_stack(a, b);
	while (rem--)
		reverse_rotate_stack(b, B);
}

void	b_to_a(int r, t_deque *a, t_deque *b, int *cnt)
{
	int		r_temp;
	t_item	var;

	(*cnt)++;
	if (!exceptional_cases(r, a, b))
		return ;
	init_item(&var);
	select_pivot(r, b, &var);
	r_temp = r;
	while (r_temp--)
		push_rotate_b(a, b, &var);
	a_to_b(var.pa - var.ra, a, b, cnt);
	if (var.ra > var.rb)
		back_to_orig_ra(a, b, &var);
	else
		back_to_orig_rb(a, b, &var);
	a_to_b(var.ra, a, b, cnt);
	b_to_a(var.rb, a, b, cnt);
}
