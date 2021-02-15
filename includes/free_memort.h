/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memort.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 00:14:15 by ysong             #+#    #+#             */
/*   Updated: 2021/02/14 22:34:56 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MEMORY_H
# define FREE_MEMORY_H

# include "minirt_struct.h"

void	ft_release_textures(t_rt rt, t_bonus bonus);
void	ft_clean_memory(t_rt rt);
void	ft_clean_cameras(t_camera **camera);
void	ft_clean_lights(t_light **ligth);
void	ft_clean_spheres(t_rt rt, t_sphere **sphere);
void	ft_clean_planes(t_rt rt, t_plane **plane);
void	ft_clean_squares(t_rt rt, t_square **square);
void	ft_clean_triangles(t_rt rt, t_triangle **triangle);
void	ft_clean_cylinders(t_cylinder **cylinder);

#endif
