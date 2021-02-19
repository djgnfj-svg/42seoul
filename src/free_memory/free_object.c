/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 00:06:00 by ysong             #+#    #+#             */
/*   Updated: 2021/02/18 23:37:53 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_clean_squares(t_rt rt, t_square **square)
{
	int	i;

	i = 0;
	while (square[i])
	{
		ft_release_textures(rt, square[i]->bonus);
		free(square[i]);
		square[i] = NULL;
		i++;
	}
	free(square[i]);
	square[i] = NULL;
	free(square);
	square = NULL;
}

void	ft_clean_triangles(t_rt rt, t_triangle **triangle)
{
	int	i;

	i = 0;
	while (triangle[i])
	{
		ft_release_textures(rt, triangle[i]->bonus);
		free(triangle[i]);
		triangle[i] = NULL;
		i++;
	}
	free(triangle[i]);
	triangle[i] = NULL;
	free(triangle);
	triangle = NULL;
}

void	ft_clean_cylinders(t_cylinder **cylinder)
{
	int i;

	i = 0;
	while (cylinder[i])
	{
		free(cylinder[i]);
		cylinder[i] = NULL;
		i++;
	}
	free(cylinder[i]);
	cylinder[i] = NULL;
	free(cylinder);
	cylinder = NULL;
}

void	ft_clean_memory(t_rt rt)
{
	ft_clean_cameras(rt.camera);
	ft_clean_lights(rt.light);
	ft_clean_spheres(rt, rt.sphere);
	ft_clean_planes(rt, rt.plane);
	ft_clean_squares(rt, rt.square);
	ft_clean_triangles(rt, rt.triangle);
	ft_clean_cylinders(rt.cylinder);
}
