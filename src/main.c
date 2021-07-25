/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:56:40 by ysong             #+#    #+#             */
/*   Updated: 2021/07/25 18:09:35 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;

	if (ac < 2)
		return (0);
	arg_check_and_init(ac - 1, av, &a, &b);
	if (!is_sorted(a))
		push_swap(a, b);
	free_deque(a, b);
	return (0);
}
