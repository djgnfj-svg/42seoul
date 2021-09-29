/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:29:56 by ysong             #+#    #+#             */
/*   Updated: 2021/09/29 11:16:07 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
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
int	str_err(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}
int print_error(int error_int)
{
	if (error_int == ARGUMENT_ERROR)
		printf("Error : argument.\n");
	else if (error_int == WRONG_NUM_OF_PHILO)
		printf("Error : wrong num_of_philo.\n");
	if (error_int == WRONG_TIME_TO_DIE)
		printf("Error : wrong tiem_to_die.\n");
	if (error_int == WRONG_TIEM_TO_EAT)
		printf("Error : wrong time_to_eat.\n");
	if (error_int == WRONG_TIEM_TO_SLEEP)
		printf("Error : wrong time_to_sleep.\n");
	if (error_int == WRONG_NUM_OF_MUST_EAT)
		printf("Error : wrong num_of_must_eat.\n");
	if (error_int == FAILED_TO_MEMORY)
		printf("Error : failed to allocate memory.\n");
	if (error_int == FAILED_TO_MUTAX)
		printf("Error : failed to initialize mutax.\n");
	return (1);
}

int get_time(void)
{
	struct timeval time;
	
	gettimeofday(&time, NULL);
	return (time.tv_sec *1000 + time.tv_usec / 1000);	
}

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