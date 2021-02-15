/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:45:07 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 01:02:45 by ysong            ###   ########.fr       */
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
	aux = ft_mtx_vct_prod(s->camera[s->i_cam]->base, aux);
	s->camera[s->i_cam]->pos = ft_add_vec(aux, s->camera[s->i_cam]->pos);
	ft_draw_to_screen(s);
}

void			ft_change_camera(int key, t_rt *rt)
{
	if (key == ARROW_LEFT)
	{
		if (s->i_cam > 0)
			s->i_cam = s->i_cam - 1;
		else
			s->i_cam = s->n_cams - 1;
	}
	else
	{
		if (s->i_cam < s->n_cams - 1)
			s->i_cam = s->i_cam + 1;
		else
			s->i_cam = 0;
	}
	ft_draw_to_screen(s);
}

int				ft_handle_keyboard(int key, t_rt *rt)
{
	if (key == ESC)
		ft_exit(&s->window);
	else if (key == KEY_A || key == KEY_W || key == KEY_S
			|| key == KEY_D || key == KEY_E || key == KEY_Q)
		ft_handle_axis_translation(key, s);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT)
		ft_change_camera(key, s);
	return (0);
}

int				ft_handle_mouse(int press, int u, int v, t_rt *rt)
{
	t_vec	new_normal;

	(void)press;
	new_normal = ft_local_camera_ray(*s, (double)u, (double)v);
	new_normal = ft_mtx_vct_prod(s->camera[s->i_cam]->base, new_normal);
	ft_normalize_vector(&new_normal);
	s->camera[s->i_cam]->n = new_normal;
	ft_draw_to_screen(s);
	return (0);
}
