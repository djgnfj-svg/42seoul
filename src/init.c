/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:43:56 by ysong             #+#    #+#             */
/*   Updated: 2021/09/29 06:41:18 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int init_fork(t_info *info)
{
	int i;

	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) 
	* info->num_of_philo);
	if(!info->fork)
		return(print_error(FAILED_TO_MEMORY));
	i = -1;
	while (++i < info->num_of_philo)
	{
		if(pthread_mutex_init(&info->fork[i], NULL))
			return (print_error(FAILED_TO_MUTAX));
	}
	return (0);
}

static int check_arg(t_info *info, int ac)
{
	if (info->num_of_philo < 0)
		return (print_error(WRONG_NUM_OF_PHILO));
	if (info->time_to_die < 0)
		return (print_error(WRONG_TIME_TO_DIE));
	if (info->time_to_eat < 0)
		return (print_error(WRONG_TIEM_TO_EAT));
	if (info->time_to_sleep < 0)
		return (print_error(WRONG_TIEM_TO_SLEEP));
	if (ac == 6 && info->num_of_must_eat <= 0)
		return (print_error(WRONG_NUM_OF_MUST_EAT));
	return (0);
}

static int init_philosiper(t_info *info)
{
	int i;
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if(!info->philo)
		return (print_error(FAILED_TO_MEMORY));
	i= -1;
	while (++i < info->num_of_philo)
	{
		info->philo[i].n = i;
		info->philo[i].fork_l = i;
		info->philo[i].fork_r = (i + 1) % info->num_of_philo;
		info->philo[i].start_time = 0;
		info->philo[i].meals = 0;
		info->philo[i].info = info;
		if(pthread_mutex_init(&info->philo[i].protect, NULL))
			return (print_error(FAILED_TO_MUTAX));
	}
	return (0);
}
static int parsing_arg(t_info *info, int ac, char **av)
{
	info->num_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->num_of_must_eat = ft_atoi(av[5]);
	info->stop=0;
	info->base_time = 0;
	if (check_arg(info, ac))
		return (1);
	if (init_fork(info))
		return (1);
	if (pthread_mutex_init(&info->status, NULL))
		return (print_error(FAILED_TO_MUTAX));
	return (0);
}

int init_philo(t_info *info, int ac, char **av)
{
	if (parsing_arg(info, ac, av))
		return (1);
	if (init_philosiper(info))
		return (1);
	return (0);
}
