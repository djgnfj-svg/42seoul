/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:45:51 by ysong             #+#    #+#             */
/*   Updated: 2021/02/12 20:46:04 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj_color	ft_disruption(t_light *light, t_obj_color obj)
{
	(void)light;
	obj.light = ft_parallel_light(light, obj);
	return (obj);
}
