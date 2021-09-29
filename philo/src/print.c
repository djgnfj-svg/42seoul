/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 03:00:28 by ysong             #+#    #+#             */
/*   Updated: 2021/09/30 03:18:42 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
	{
		res *= 10;
		res += *str++ - '0';
	}
	return (res * sign);
}

void	print_status(t_philo *philo, int status)
{
	printf("%s", "\tPhilosopher ");
	printf("%d", philo->n + 1);
	if (status == FORK)
		printf("%s\n", " : has taken a fork");
	else if (status == EATING)
		printf("%s\n", " : is eating");
	else if (status == SLEEPING)
		printf("%s\n", " : is sleeping");
	else if (status == THINKING)
		printf("%s\n", " : is thinking");
	else if (status == DIED)
		printf("%s\n", " : is died");
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
