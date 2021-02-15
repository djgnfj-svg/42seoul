/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 00:09:33 by ysong             #+#    #+#             */
/*   Updated: 2021/02/14 22:04:39 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_release_textures(t_rt rt, t_bonus bonus)
{
	if (bonus.texture.img)
		mlx_destroy_image(rt.window.mlx_ptr, bonus.texture.img);
	if (bonus.bumpmap.img)
		mlx_destroy_image(rt.window.mlx_ptr, bonus.bumpmap.img);
}

void	ft_clean_cameras(t_camera **camera)
{
	int	i;

	i = 0;
	while (camera[i])
	{
		free(camera[i]);
		camera[i] = NULL;
		i++;
	}
	free(camera[i]);
	camera[i] = NULL;
	free(camera);
	camera = NULL;
}

void	ft_clean_lights(t_light **light)
{
	int	i;

	i = 0;
	while (light[i])
	{
		free(light[i]);
		light[i] = NULL;
		i++;
	}
	free(light[i]);
	light[i] = NULL;
	free(light);
	light = NULL;
}

void	ft_clean_spheres(t_rt rt, t_sphere **sphere)
{
	int	i;

	i = 0;
	while (sphere[i])
	{
		ft_release_textures(rt, sphere[i]->bonus);
		free(sphere[i]);
		sphere[i] = NULL;
		i++;
	}
	free(sphere[i]);
	sphere[i] = NULL;
	free(sphere);
	sphere = NULL;
}

void	ft_clean_planes(t_rt rt, t_plane **plane)
{
	int	i;

	i = 0;
	while (plane[i])
	{
		ft_release_textures(rt, plane[i]->bonus);
		free(plane[i]);
		plane[i] = NULL;
		i++;
	}
	free(plane[i]);
	plane[i] = NULL;
	free(plane);
	plane = NULL;
}
