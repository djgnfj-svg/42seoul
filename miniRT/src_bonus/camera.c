/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:47:55 by ysong             #+#    #+#             */
/*   Updated: 2021/02/24 14:12:47 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		ft_local_camera_ray(t_rt rt, double p_x, double p_y)
{
	t_vec		c_local;
	double		sx;
	double		sy;

	sx = (double)rt.x;
	sy = (double)rt.y;
	c_local.x = (2 * ((p_x + 0.5) / sx) - 1) * (sx / sy)
		* rt.camera[rt.i_cam]->fov;
	c_local.y = (1 - 2 * ((p_y + 0.5) / sy))
		* rt.camera[rt.i_cam]->fov;
	c_local.z = -1;
	return (c_local);
}

int			ft_global_camera_base(t_rt *rt, int i_cam)
{
	t_matrix	conversion;

	if (!rt->camera[i_cam])
		return (0);
	conversion.vx = ft_set_hor_axis(rt->camera[i_cam]->n);
	conversion.vy = ft_cross_product(conversion.vx, rt->camera[i_cam]->n);
	conversion.vz = ft_k_mul_vec(-1, rt->camera[i_cam]->n);
	ft_normalize_vector(&conversion.vx);
	ft_normalize_vector(&conversion.vy);
	ft_normalize_vector(&conversion.vz);
	rt->camera[i_cam]->base = conversion;
	return (1);
}
