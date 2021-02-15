/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:21:40 by ysong             #+#    #+#             */
/*   Updated: 2021/02/15 18:17:44 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "object_struct.h"

void	ft_calc_surface_cylinder(t_rt *rt, t_ray *r, int i);
int		ft_intersect_cylinder(t_rt *rt, t_ray *r, int i);
int		ft_draw_caps(t_rt rt, t_ray *r, int i);
int		ft_draw_cylinder(t_rt rt, t_ray *r, int i);
int		ft_intersect_caps(t_rt *rt, t_ray *r, int i, t_auxplane *auxplane);
int		ft_shadow_caps(t_rt rt, t_ray *r, int i);
void	ft_color_cylinder(t_rt rt, t_ray *r, int i);

int		ft_intersect_plane(t_rt *rt, t_auxplane *plane, t_ray *r);
int		ft_get_point_plane(t_rt *rt, t_auxplane *plane, t_ray *r);
int		ft_draw_plane(t_rt rt, t_ray *r, int i);

int		ft_intersect_sphere(t_rt *rt, t_ray *r, int i);
int		ft_draw_sphere(t_rt rt, t_ray *r, int i);

int		ft_intersect_inside_square(t_rt rt, t_auxplane *auxplane, int i);
int		ft_draw_square(t_rt rt, t_ray *r, int i);

double	ft_get_p_param(t_rt rt, t_vec p0, int i);
double	ft_get_q_param(t_rt rt, t_vec p0, int i);
int		ft_is_inside_triangle(t_rt rt, t_auxplane *auxplane, int i);
int		ft_intersect_triangle(t_rt *rt, t_ray *r, int i,
				t_auxplane *auxplane);
int		ft_draw_triangle(t_rt rt, t_ray *r, int i); 

#endif
