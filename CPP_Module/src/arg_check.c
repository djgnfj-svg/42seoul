/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:03:03 by ysong             #+#    #+#             */
/*   Updated: 2022/01/10 07:23:28 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isint(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || ft_isdigit(str[i]))
	{
		i++;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				print_error();
			i++;
		}
	}
	else
		return (0);
	return (1);
}

static void	check_is_int(char **av, int last)
{
	int	start;

	start = -1;
	while (++start != last)
		if (!ft_isint(av[start + 1]))
			print_error();
}

static void	check_duplicate(char **av, int last)
{
	int	start;
	int	temp;
	int	i;

	start = 1;
	while (start < last)
	{
		if (ft_atoi(av[start]) > INT_MAX || ft_atoi(av[start]) < INT_MIN)
			print_error();
		i = start + 1;
		while (i <= last)
		{
			temp = ft_atoi(av[i]);
			if (ft_atoi(av[start]) == temp)
				print_error();
			i++;
		}
		start++;
	}
}

static void	init_all(t_deque **a, t_deque **b, char **av)
{
	(*a) = init_deque();
	(*b) = init_deque();
	(*a)->header = connect_deque(av, a);
}

int	arg_check_and_init(int last, char **av, t_deque **a, t_deque **b)
{
	check_is_int(av, last);
	check_duplicate(av, last);
	init_all(a, b, av);
	return (0);
}
