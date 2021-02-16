/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 04:34:34 by ysong             #+#    #+#             */
/*   Updated: 2021/02/17 06:25:01 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_shadows(t_rt rt, t_ray *ray)
{
	int	i;

	i = -1;
	while (rt.sphere[++i])
		if (ft_shadow_sphere(rt, ray, i))
			return (1);
	i = -1;
	while (rt.plane[++i])
		if (ft_shadow_plane(rt, ray, i))
			return (1);
	i = -1;
	while (rt.square[++i])
		if (ft_shadow_square(rt, ray, i))
			return (1);
	i = -1;
	while (rt.triangle[++i])
		if (ft_shadow_triangle(rt, ray, i))
			return (1);
	i = -1;
	while (rt.cylinder[++i])
		if (ft_shadow_cylinder(rt, ray, i))
			return (1);
	return (0);
}

int	ft_between_light_source(t_vec light, t_vec point, t_vec origin)
{
	t_vec	shadow_ray;
	t_vec	light_ray;
	double		mod_global;
	double		mod_shadow;

	shadow_ray = ft_sub_vec(point, origin);
	light_ray = ft_sub_vec(light, origin);
	mod_shadow = ft_mod_vector(shadow_ray);
	mod_global = ft_mod_vector(light_ray);
	if (mod_shadow > 0.0001 && mod_shadow < mod_global)
		return (1);
	return (0);
}
