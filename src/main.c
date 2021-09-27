/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:29:59 by ysong             #+#    #+#             */
/*   Updated: 2021/08/27 10:52:47 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int main(int ac, char **av)
{
	t_info info;
	if (ac < 5 | ac > 6)
		return (print_error(ARGUMENT_ERROR));
	init_all(info, ac, av);
	if (dining_philo(&info))
	{
		free_all(&info);
		return (1);
	}
	free_all(&info);
	return (0);
}