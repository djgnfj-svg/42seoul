/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 03:00:28 by ysong             #+#    #+#             */
/*   Updated: 2021/10/13 06:21:24 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, int status)
{
	printf(" ");
	printf("%d", philo->n + 1);
	if (status == FORK)
		printf("%s\n", " has taken a fork");
	else if (status == EATING)
		printf("%s\n", " is eating");
	else if (status == SLEEPING)
		printf("%s\n", " is sleeping");
	else if (status == THINKING)
		printf("%s\n", " is thinking");
	else if (status == DIED)
		printf("%s\n", " is died");
}

void	print_msg(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->info->status);
	if (philo->info->stop)
	{
		pthread_mutex_unlock(&philo->info->status);
		return ;
	}
	printf("%d", get_time() - philo->info->base_time);
	print_status(philo, status);
	pthread_mutex_unlock(&philo->info->status);
}

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	print_err(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}
