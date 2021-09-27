/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:52:57 by ysong             #+#    #+#             */
/*   Updated: 2021/08/27 10:54:54 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void free_all(t_info *info)
{
	int i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		pthread_mutex_destroy(&info->fork[i]);
		pthread_mutex_destroy(&info->philo[i].protect);
	}
	pthread_mutex_destroy(&info->status);
	free(info->philo);
	free(info->fork);
}