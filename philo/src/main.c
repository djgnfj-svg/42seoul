/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:29:59 by ysong             #+#    #+#             */
/*   Updated: 2021/09/30 04:35:22 by ysong            ###   ########.fr       */
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
		dining_philo(&info);
		free_all(&info);
		return (0);
	}
	free(info.philo);
	free(info.fork);
	return (0);
}
