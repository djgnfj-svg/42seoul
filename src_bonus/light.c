/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:47:10 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 01:02:35 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		ft_parallel_light(t_light *light, t_obj_color obj)
{
	t_vec	light_dir;
	t_vec	lp;

	lp = ft_sub_vec(light->pos, obj.p);
	if (ft_isvoid(light->parallel))
	{
		light_dir = light->parallel;
		light_dir = ft_k_mul_vec(-1, light_dir);
		ft_normalize_vector(&light_dir);
		light->pos_shadow = ft_k_mul_vec(ft_dot_product(light_dir, lp)
				, light_dir);
	}
	else
	{
		light_dir = lp;
		light->pos_shadow = light->pos;
		ft_normalize_vector(&light_dir);
	}
	return (light_dir);
}
