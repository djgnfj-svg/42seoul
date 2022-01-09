/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 06:42:30 by ysong             #+#    #+#             */
/*   Updated: 2022/01/10 06:42:31 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	check_operations(char *buf, t_deque *a, t_deque *b)
{
	if (!ft_strcmp("pa", buf) || !ft_strcmp("pb", buf))
		do_push(buf, a, b);
	else if (!ft_strcmp("sa", buf) || !ft_strcmp("sb", buf) ||
	!ft_strcmp("ss", buf))
		do_swap(buf, a, b);
	else if (!ft_strcmp("ra", buf) || !ft_strcmp("rb", buf) ||
	!ft_strcmp("rr", buf))
		do_rotate(buf, a, b);
	else if (!ft_strcmp("rra", buf) || !ft_strcmp("rrb", buf) ||
	!ft_strcmp("rrr", buf))
		do_reverse_rotate(buf, a, b);
	else
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
