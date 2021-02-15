/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:45:51 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 02:07:51 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_obj_color	ft_disruption(t_light *light, t_obj_color obj)
{
	if (obj.bonus.id[0])
	{
		if (obj.bonus.id[0] == 1 || obj.bonus.id[1] == 1)
			obj.normal = ft_wave_normal(obj);
		else if (obj.bonus.id[0] == 3 || obj.bonus.id[1] == 3)
			obj.normal = ft_bumpmap(obj);
		if (obj.bonus.id[0] == 2 || obj.bonus.id[1] == 2)
			obj.rgb = ft_checkered_pattern(obj);
		else if (obj.bonus.id[0] == 5 || obj.bonus.id[1] == 5)
			obj.rgb = ft_rainbow_pattern(obj.normal, obj.rgb);
		else if (obj.bonus.id[0] == 6 || obj.bonus.id[1] == 6)
			obj.rgb = ft_sphere_texture(obj);
		else if (obj.bonus.id[0] == 4 || obj.bonus.id[1] == 4)
			obj.rgb = ft_plane_texture(obj);
	}
	obj.light = ft_parallel_light(light, obj);
	return (obj);
}

