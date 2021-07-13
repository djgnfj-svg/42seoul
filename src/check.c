/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 01:23:58 by ysong             #+#    #+#             */
/*   Updated: 2021/07/14 02:18:44 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int		is_sorted(t_deque *a)
{
	t_node	*node;

	node = a->header;
	while (node)
	{
		if (node->next)
		{
			if (node->item > node->next->item)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->item == a->tailer->item)
		return (1);
	else
		return (0);
}
void	do_push(char *buf, t_deque *a, t_deque *b)
{
	if (!ft_strcmp("pa", buf))
		push_stack(b, a, 0);
	else if (!ft_strcmp("pb", buf))
		push_stack(a, b, 0);
}

void	do_swap(char *buf, t_deque *a, t_deque *b)
{
	if (!ft_strcmp("sa", buf))
		swap_stack(a, 0);
	else if (!ft_strcmp("sb", buf))
		swap_stack(b, 0);
	else
		swap_all_stack(a, b, 0);
}

void	do_rotate(char *buf, t_deque *a, t_deque *b)
{
	if (!ft_strcmp("ra", buf))
		rotate_stack(a, 0);
	else if (!ft_strcmp("rb", buf))
		rotate_stack(b, 0);
	else
		rotate_all_stack(a, b, 0);
}

void	do_reverse_rotate(char *buf, t_deque *a, t_deque *b)
{
	if (!ft_strcmp("rra", buf))
		reverse_rotate_stack(a, 0);
	else if (!ft_strcmp("rrb", buf))
		reverse_rotate_stack(b, 0);
	else
		reverse_rotate_all_stack(a, b);
}
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
int		main(int ac, char *av[])
{
	t_deque *a;
	t_deque	*b;

	if (ac < 2)
		return (0);
	arg_check(ac - 1, av);
	a = init_deque();
	b = init_deque();
	a->header = make_stack(ac, av, &a);
	checker(a, b);
	free_all(a, b);
	return (0);
}