/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rt_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:44:47 by ysong             #+#    #+#             */
/*   Updated: 2021/02/18 01:03:24 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt_bonus.h"

void	ft_draw_element(t_rt rt, t_ray *ray)
{
	int	i;

	i = -1;
	while (rt.sphere[++i])
		ft_draw_sphere(rt, ray, i);
	i = -1;
	while (rt.plane[++i])
		ft_draw_plane(rt, ray, i);
	i = -1;
	while (rt.square[++i])
		ft_draw_square(rt, ray, i);
	i = -1;
	while (rt.cylinder[++i])
		ft_draw_cylinder(rt, ray, i);
	i = -1;
	while (rt.triangle[++i])
		ft_draw_triangle(rt, ray, i);
}

void	ft_fill_img_buf(t_image *img, int x, int y, int color)
{
	img->addr[y * img->len / 4 + x] = color;
}

void	ft_initialize_ray(t_ray *ray)
{
	ray->t = DBL_MAX;
	ray->color = 0;
	ray->origin = (t_vec){0, 0, 0};
}

void	ft_render_pxl(double px, double py, t_ray *ray, t_rt *rt)
{
	ray->local = ft_local_camera_ray(*rt, px, py);
	ray->global = ft_mtx_vct_prod(rt->camera[rt->i_cam]->base, ray->local);
	ft_initialize_ray(ray);
	ft_normalize_vector(&ray->global);
	ft_draw_element(*rt, ray);
}

void	ft_render_scene(t_rt *rt)
{
	if (ft_global_camera_base(rt, rt->i_cam))
		draw_hittable_pthread(rt);
}