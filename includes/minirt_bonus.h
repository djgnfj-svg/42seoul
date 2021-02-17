/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:45:28 by ysong             #+#    #+#             */
/*   Updated: 2021/02/18 01:02:52 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

#include "minirt.h"

t_thread_info		*tinfo_new(t_rt *rt, int tnum);
void	            *ft_render_pthread(void *arg);
void				draw_hittable_pthread(t_rt *rt);

t_vec			ft_get_parallel_dir(char *option);
t_vec			ft_is_parallel_light(char *option);
t_texture		ft_load_texture(t_rt *rt, char *option);
t_bonus			ft_plane_bonus(t_rt *rt, char **option);
t_bonus			ft_sphere_bonus(t_rt *rt, char **option);
t_bonus			ft_cylinder_bonus(char **option);

void			ft_render_pxl_antialiasing(double px, double py
					, t_ray *ray, t_rt *rt);
t_rgb			ft_sepia_filter(t_rt rt, t_rgb in_color);

t_matrix		ft_inv_matrix(t_matrix m);
double			ft_det(t_matrix m);


t_vec		ft_wave_normal(t_obj_color obj);
t_rgb			ft_checkered_pattern(t_obj_color obj);
t_rgb			ft_color_texture(t_obj_color obj, int x, int y);
t_rgb			ft_plane_texture(t_obj_color obj);


void			ft_sphere_coords(t_obj_color obj, double *x, double *y);
t_rgb			ft_sphere_texture(t_obj_color obj);
t_rgb			ft_rainbow_pattern(t_vec n, t_rgb color);


t_vec		ft_bumpmap(t_obj_color obj);
t_vec		ft_get_bumpmap_normal(t_obj_color obj, int x, int y);

#endif