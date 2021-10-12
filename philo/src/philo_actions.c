/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:21:48 by ysong             #+#    #+#             */
/*   Updated: 2021/10/13 05:59:20 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_on(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->fork_l]);
	print_msg(philo, FORK);
	pthread_mutex_lock(&philo->info->fork[philo->fork_r]);
	print_msg(philo, FORK);
}

void	fork_off(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->fork[philo->fork_l]);
	pthread_mutex_unlock(&philo->info->fork[philo->fork_r]);
}

void	eating(t_philo *philo)
{
	if (philo->info->num_of_philo == 1)
	{
		pthread_mutex_lock(&philo->info->fork[philo->fork_l]);
		print_msg(philo, FORK);
		while (!philo->info->stop)
			usleep(1000);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_l]);
	}
	else
	{
		fork_on(philo);
		pthread_mutex_lock(&philo->protect);
		print_msg(philo, EATING);
		philo->start_time = get_time();
		while (get_time() - philo->start_time <= philo->info->time_to_eat
			&& !philo->info->stop)
			usleep(1000);
		philo->meals++;
		pthread_mutex_unlock(&philo->protect);
		fork_off(philo);
	}
	
}

void	sleeping(t_philo *philo)
{
	int	time;

	print_msg(philo, SLEEPING);
	time = get_time();
	while (get_time() - time <= philo->info->time_to_sleep \
	&& !philo->info->stop)
		usleep(1000);

}

void	thinking(t_philo *philo)
{
	print_msg(philo, THINKING);
}
