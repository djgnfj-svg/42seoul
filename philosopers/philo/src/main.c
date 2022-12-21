/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:29:59 by ysong             #+#    #+#             */
/*   Updated: 2021/10/12 21:03:38 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac < 5 || ac > 6)
		return (print_error(ARGUMENT_ERROR));
	memset(&info, 0, sizeof(info));
	if (!init_philo(&info, ac, av))
	{
		run_philo(&info);
		free_all(&info);
		return (0);
	}
	(void)av;
	return (0);
}
