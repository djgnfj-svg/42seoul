/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:45:07 by ysong             #+#    #+#             */
/*   Updated: 2021/02/17 06:19:39 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			ft_handle_axis_translation(int key, t_rt *rt)
{
	t_vec	aux;

	if (key == KEY_A)
		aux = (t_vec){-1, 0, 0};
	else if (key == KEY_D)
		aux = (t_vec){1, 0, 0};
	else if (key == KEY_W)
		aux = (t_vec){0, 1, 0};
	else if (key == KEY_S)
		aux = (t_vec){0, -1, 0};
	else if (key == KEY_E)
		aux = (t_vec){0, 0, -1};
	else
		aux = (t_vec){0, 0, 1};
	aux = ft_mtx_vct_prod(rt->camera[rt->i_cam]->base, aux);
	rt->camera[rt->i_cam]->pos = ft_add_vec(aux, rt->camera[rt->i_cam]->pos);
	ft_draw_to_screen(rt);
}

void			ft_change_camera(int key, t_rt *rt)
{
	if (key == ARROW_LEFT)
	{
		if (rt->i_cam > 0)
			rt->i_cam = rt->i_cam - 1;
		else
			rt->i_cam = rt->n_cams - 1;
	}
	else
	{
		if (rt->i_cam < rt->n_cams - 1)
			rt->i_cam = rt->i_cam + 1;
		else
			rt->i_cam = 0;
	}
	ft_draw_to_screen(rt);
}

int				ft_handle_keyboard(int key, t_rt *rt)
{
	if (key == ESC)
		ft_exit(&rt->window);
	else if (key == KEY_A || key == KEY_W || key == KEY_S
			|| key == KEY_D || key == KEY_E || key == KEY_Q)
		ft_handle_axis_translation(key, rt);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT)
		ft_change_camera(key, rt);
	return (0);
}

int				ft_handle_mouse(int press, int u, int v, t_rt *rt)
{
	t_vec	new_normal;

	(void)press;
	new_normal = ft_local_camera_ray(*rt, (double)u, (double)v);
	new_normal = ft_mtx_vct_prod(rt->camera[rt->i_cam]->base, new_normal);
	ft_normalize_vector(&new_normal);
	rt->camera[rt->i_cam]->n = new_normal;
	ft_draw_to_screen(rt);
	return (0);
}
