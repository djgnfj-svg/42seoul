/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:29:59 by ysong             #+#    #+#             */
/*   Updated: 2021/10/05 10:06:27 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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