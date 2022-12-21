/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 01:23:58 by ysong             #+#    #+#             */
/*   Updated: 2022/01/10 08:18:04 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push(char *buf, t_deque *a, t_deque *b)
{
	if (!ft_strcmp("pa", buf))
		ft_pa(b, a);
	else if (!ft_strcmp("pb", buf))
		ft_pb(a, b);
}

void	do_swap(char *buf, t_deque *a, t_deque *b)
{
	if (!ft_strcmp("sa", buf))
		ft_sa(a);
	else if (!ft_strcmp("sb", buf))
		ft_sb(b);
	else
		ft_ss(a, b);
}

void	do_rotate(char *buf, t_deque *a, t_deque *b)
{
	if (!ft_strcmp("ra", buf))
		ft_ra(a);
	else if (!ft_strcmp("rb", buf))
		ft_rb(b);
	else
		ft_rr(a, b);
}

void	do_reverse_rotate(char *buf, t_deque *a, t_deque *b)
{
	if (!ft_strcmp("rra", buf))
		ft_rra(a);
	else if (!ft_strcmp("rrb", buf))
		ft_rrb(b);
	else
		ft_rrr(a, b);
}
