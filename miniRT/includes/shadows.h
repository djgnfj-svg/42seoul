/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 04:32:36 by ysong             #+#    #+#             */
/*   Updated: 2021/02/24 14:04:23 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADOWS_H
# define SHADOWS_H

# include "minirt_struct.h"

int	ft_shadows(t_rt rt, t_ray *ray);
int	ft_between_light_source(t_vec light,
					t_vec point, t_vec origin);

int	ft_shadow_cylinder(t_rt rt, t_ray *r, int i);
int	ft_shadow_plane(t_rt rt, t_ray *r, int i);
int	ft_intersect_shadow_plane(t_auxplane *plane, t_ray *r);
int	ft_shadow_sphere(t_rt rt, t_ray *r, int i);
int	ft_shadow_square(t_rt rt, t_ray *r, int i);
int	ft_shadow_triangle(t_rt rt, t_ray *r, int i);

#endif
