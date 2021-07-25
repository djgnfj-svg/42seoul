/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 01:23:58 by ysong             #+#    #+#             */
/*   Updated: 2021/07/25 18:47:59 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_operations(char *buf, t_deque *a, t_deque *b)
{
	if (!ft_strcmp("pa", buf))
		ft_pa(b, a);
	else if (!ft_strcmp("pb", buf))
		ft_pb(a, b);
	else if (!ft_strcmp("sa", buf))
		ft_sa(a);
	else if (!ft_strcmp("sb", buf))
		ft_sb(b);
	else if (!ft_strcmp("ss", buf))
		ft_ss(a, b);
	else if (!ft_strcmp("ra", buf))
		ft_ra(a);
	else if (!ft_strcmp("rb", buf))
		ft_rb(b);
	else if (!ft_strcmp("rr", buf))
		ft_rr(a, b);
	else if (!ft_strcmp("rra", buf))
		ft_rra(a);
	else if (!ft_strcmp("rrb", buf))
		ft_rrb(b);
	else if (!ft_strcmp("rrr", buf))
		ft_rrr(a, b);
	print_error();
}

void	checker(t_deque *a, t_deque *b)
{
	char	*buf;

	while (get_next_line(0, &buf) > 0)
	{
		check_operations(buf, a, b);
		free(buf);
	}
	free(buf);
	if (is_sorted(a) && !b->tailer)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int ac, char *av[])
{
	t_deque	*a;
	t_deque	*b;

	if (ac < 2)
		return (0);
	arg_check_and_init(ac - 1, av, &a, &b);
	checker(a, b);
	free_deque(a, b);
	return (0);
}
