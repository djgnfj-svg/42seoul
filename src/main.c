/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:29:59 by ysong             #+#    #+#             */
/*   Updated: 2021/09/28 03:07:32 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_info info;
	if (ac < 5 | ac > 6)
		return (print_error(ARGUMENT_ERROR));
	init_philo(info, ac, av);
	if(run_philo())
	{
		free_philo();
		return (0);
	}
	free_philo();
	return (0);
}