/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 02:02:50 by ysong             #+#    #+#             */
/*   Updated: 2021/02/24 14:16:10 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vec		ft_get_bumpmap_normal(t_obj_color obj, int x, int y)
{
	double	coef[2];
	t_vec	u;
	t_vec	v;

	if ((x - 1) >= 0 && (x + 1) < obj.bonus.bumpmap.width)
		coef[0] = (obj.bonus.bumpmap.val[y * obj.bonus.bumpmap.width + (x + 1)]
				- obj.bonus.bumpmap.val[y
				* obj.bonus.bumpmap.width + (x - 1)]) / 2;
	if ((y - 1) >= 0 && (y + 1) < obj.bonus.bumpmap.height)
		coef[1] = (obj.bonus.bumpmap.val[(y + 1)
				* obj.bonus.bumpmap.width + x]
				- obj.bonus.bumpmap.val[(y - 1)
				* obj.bonus.bumpmap.width + x]) / 2;
	coef[0] /= 0xFFFFFF;
	coef[1] /= 0xFFFFFF;
	u = (t_vec){coef[1], 0, 0};
	v = (t_vec){0, coef[0], 0};
	obj.normal = ft_add_vec(obj.normal, ft_add_vec(u, v));
	ft_normalize_vector(&obj.normal);
	return (obj.normal);
}

t_vec		ft_bumpmap(t_obj_color obj)
{
	double	x;
	double	y;

	if (obj.bonus.type == 's')
	{
		ft_sphere_coords(obj, &x, &y);
		x *= obj.bonus.bumpmap.width;
		y *= obj.bonus.bumpmap.height;
	}
	else
	{
		x = ft_abs((int)obj.p.x % obj.bonus.bumpmap.width);
		y = (obj.bonus.bumpmap.height - 1)
			- ft_abs((int)obj.p.y % obj.bonus.bumpmap.height);
	}
	return (ft_get_bumpmap_normal(obj, (int)x, (int)y));
}
