/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:21:48 by ysong             #+#    #+#             */
/*   Updated: 2021/09/30 02:48:16 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	eating(t_philo *philo)
{
	if (philo->info->num_of_philo == 1)
	{
		pthread_mutex_lock(&philo->info->fork[philo->fork_r]);
		print_msg(philo, FORK);
		while (!philo->info->stop)
			usleep(1000);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_r]);
	}
	else
	{
		pthread_mutex_lock(&philo->info->fork[philo->fork_r]);
		print_msg(philo, FORK);
		pthread_mutex_lock(&philo->info->fork[philo->fork_l]);
		print_msg(philo, FORK);
		pthread_mutex_lock(&philo->protect);
		print_msg(philo, EATING);
		philo->start_time = get_time();
		pthread_mutex_unlock(&philo->protect);
		while (get_time() - philo->start_time <= philo->info->time_to_eat && \
		!philo->info->stop)
			usleep(1000);
		philo->meals++;
		pthread_mutex_unlock(&philo->info->fork[philo->fork_r]);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_l]);
	}
}

void	sleeping(t_philo *philo)
{
	int	start_sleep;

	start_sleep = get_time();
	print_msg(philo, SLEEPING);
	while (get_time() - start_sleep <= philo->info->time_to_sleep && \
	!philo->info->stop)
		usleep(1000);
}

void	thinking(t_philo *philo)
{
	print_msg(philo, THINKING);
}
