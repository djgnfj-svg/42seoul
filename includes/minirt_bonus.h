/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:45:28 by ysong             #+#    #+#             */
/*   Updated: 2021/02/15 07:35:48 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

#include "minirt.h"
/*
** Load bonus
*/
t_vec		ft_get_parallel_dir(char *option);
t_vec		ft_is_parallel_light(char *option);
t_texture		ft_load_texture(t_rt *rt, char *option);
t_bonus			ft_plane_bonus(t_rt *rt, char **option);
t_bonus			ft_sphere_bonus(t_rt *rt, char **option);
t_bonus			ft_cylinder_bonus(char **option);

/*
** Filter color
*/
void			ft_render_pxl_antialiasing(double px, double py
					, t_ray *ray, t_rt *rt);
t_rgb			ft_sepia_filter(t_rt rt, t_rgb in_color);

t_matrix		ft_inv_matrix(t_matrix m);
double			ft_det(t_matrix m);

/*
** Plane disruption
*/

t_vec		ft_wave_normal(t_obj_color obj);
t_rgb			ft_checkered_pattern(t_obj_color obj);
t_rgb			ft_color_texture(t_obj_color obj, int x, int y);
t_rgb			ft_plane_texture(t_obj_color obj);

/*
** Sphere disruption
*/

void			ft_sphere_coords(t_obj_color obj, double *x, double *y);
t_rgb			ft_sphere_texture(t_obj_color obj);
t_rgb			ft_rainbow_pattern(t_vec n, t_rgb color);

/*
** Color utils
*/

t_vec		ft_bumpmap(t_obj_color obj);
t_vec		ft_get_bumpmap_normal(t_obj_color obj, int x, int y);

/*
** Auxiliar axes functions
*/

void	ft_draw_center(t_axis_ref axis, t_rt *rt);
void	ft_set_label_pos(t_axis_ref axis, char dir, t_rt *rt);
void	ft_sketch_axis(t_axis_ref *axis, char dir, t_rt *rt);
void	ft_draw_axis(t_vec p, char dir, t_rt *rt);
void	ft_draw_reference(t_matrix c_base, t_rt *rt);
#endif