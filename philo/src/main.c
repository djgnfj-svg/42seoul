/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:29:59 by ysong             #+#    #+#             */
/*   Updated: 2021/09/30 03:02:36 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// int		init_fork(t_info *info)
// {
// 	int	i;

// 	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
// 	* info->num_of_philo);
// 	if (!info->fork)
// 		return (str_err("Failed to allocate memory.\n"));
// 	i = -1;
// 	while (++i < info->num_of_philo)
// 	{
// 		if (pthread_mutex_init(&info->fork[i], NULL))
// 			return (str_err("Failed to initialize mutex.\n"));
// 	}
// 	return (0);
// }

// int		init_info(t_info *info, char **argv, int argc)
// {
// 	info->num_of_philo = ft_atoi(argv[1]);
// 	if (info->num_of_philo <= 0)
// 		return (str_err("The number of philosophers must be at least one.\n"));
// 	else if (info->num_of_philo >= 200)
// 		return (str_err("Do not test with more than 200 philosophers.\n"));
// 	info->time_to_die = ft_atoi(argv[2]);
// 	info->time_to_eat = ft_atoi(argv[3]);
// 	info->time_to_sleep = ft_atoi(argv[4]);
// 	if (info->time_to_die < 60 || info->time_to_eat < 60 || info->time_to_sleep < 60)
// 		return (str_err("Do not test under 60ms.\n"));
// 	if (argc == 6)
// 	{
// 		info->num_of_must_eat = ft_atoi(argv[5]);
// 		if (info->num_of_must_eat <= 0)
// 			return (str_err("Each philosopher must eat at least once.\n"));
// 	}
// 	else
// 		info->num_of_must_eat = -1;
// 	info->stop = 0;
// 	info->base_time = 0;
// 	if (init_fork(info))
// 		return (1);
// 	if (pthread_mutex_init(&info->status, NULL))
// 		return (str_err("Failed to initialize mutex.\n"));
// 	return (0);
// }

// int		init_philo(t_info *info)
// {
// 	int	i;

// 	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
// 	if (!info->philo)
// 		return (str_err("Failed to allocate memory.\n"));
// 	i = -1;
// 	while (++i < info->num_of_philo)
// 	{
// 		info->philo[i].n = i;
// 		info->philo[i].fork_l = i;
// 		info->philo[i].fork_r = (i + 1) % info->num_of_philo;
// 		info->philo[i].start_time = 0;
// 		info->philo[i].meals = 0;
// 		info->philo[i].info = info;
// 		if (pthread_mutex_init(&info->philo[i].protect, NULL))
// 			return (str_err("Failed to initialize mutex.\n"));
// 	}
// 	return (0);
// }

// void	free_all(t_info *info)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < info->num_of_philo)
// 	{
// 		pthread_mutex_destroy(&info->fork[i]);
// 		pthread_mutex_destroy(&info->philo[i].protect);
// 	}
// 	pthread_mutex_destroy(&info->status);
// 	free(info->philo);
// 	free(info->fork);
// }

int main(int ac, char **av)
{
	t_info info;
	if (ac < 5 || ac > 6)
		return (print_error(ARGUMENT_ERROR));
	memset(&info, 0, sizeof(info));
	init_philo(&info, ac, av);
	if(dining_philo(&info))
	{
		free_all(&info);
		return (0);
	}
	free_all(&info);
	return (0);
}