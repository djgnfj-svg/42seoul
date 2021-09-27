/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:56:09 by ysong             #+#    #+#             */
/*   Updated: 2021/09/28 03:08:34 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int dining_philo(t_info *info)
{
	int i;

	info->start_time = get_time();
}
int	init_thread(t_info *info)
{
	int			i;
	pthread_t	thread;

	i = -1;
	info->start_time = get_time();
	while (++i < info->num_of_philo)
	{
		info->philo[i].last_eat_time = get_time();
		if (pthread_create(&thread, NULL, routine, &info->philo[i]))
			return (1);
		pthread_detach(thread);
		if (pthread_create(&info->philo[i].thread, \
			NULL, monitor, &info->philo[i]))
			return (1);
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_join(info->philo[i].thread, NULL))
			return (1);
	}
	return (0);
}