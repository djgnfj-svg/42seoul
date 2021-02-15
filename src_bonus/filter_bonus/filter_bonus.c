/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:36:32 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 01:14:38 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void			ft_render_pxl_antialiasing(double px, double py
					, t_ray *ray, t_rt *rt)
{
	int		i;
	int		j;
	t_rgb	color;

	color = (t_rgb){0, 0, 0};
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			ft_render_pxl(px + (i + 0.5) / 2, py + (j + 0.5) / 2, ray, rt);
			color.r += (ray->color & 0x00ff0000) >> 16;
			color.g += (ray->color & 0x0000ff00) >> 8;
			color.b += (ray->color & 0x000000ff);
			j++;
		}
		i++;
	}
	ray->color = ((int)(color.r / 4) << 16)
		+ ((int)(color.g / 4) << 8) + (int)(color.b / 4);
}

t_rgb			ft_sepia_filter(t_rt rt, t_rgb in_color)
{
	t_rgb	out_color;

	if (rt.option[1])
	{
		out_color.r = (in_color.r * 0.393)
			+ (in_color.g * 0.769) + (in_color.b * 0.189);
		out_color.g = (in_color.r * 0.349)
			+ (in_color.g * 0.686) + (in_color.b * 0.168);
		out_color.b = (in_color.r * 0.272)
			+ (in_color.g * 0.534) + (in_color.b * 0.131);
		ft_check_rgb_range(&out_color);
		return (out_color);
	}
	return (in_color);
}
