/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:35:17 by ysong             #+#    #+#             */
/*   Updated: 2021/02/18 06:28:20 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <float.h>
# include <pthread.h>

# include "mlx.h"
# include "libft.h"
# include "minirt_const.h"
# include "minirt_struct.h"
# include "parse.h"
# include "object.h"
# include "object_struct.h"
# include "vec.h"
# include "shadows.h"
# include "free_memort.h"

void	    ft_error_handler(int error_id);

t_vec	    ft_local_camera_ray(t_rt rt, double p_x, double p_y);
int         ft_global_camera_base(t_rt *rt, int i_cam);

void		ft_handle_axis_translation(int key, t_rt *rt);
void		ft_change_camera(int key, t_rt *rt);
int			ft_handle_keyboard(int key, t_rt *rt);
int			ft_handle_mouse(int press, int u, int v, t_rt *rt);

t_obj_color ft_disruption(t_light *light, t_obj_color obj);


t_vec		ft_parallel_light(t_light *light, t_obj_color obj);

void	    ft_render_pxl(double px, double py, t_ray *ray, t_rt *rt);
void	    ft_fill_img_buf(t_image *img, int x, int y, int color);
void	    ft_render_scene(t_rt *rt);


int		    ft_exit(t_window *window);
void	    ft_draw(t_rt rt);
void	    ft_draw_to_screen(t_rt *rt);

void		ft_check_rgb_range(t_rgb *color);
int			ft_get_color(t_rt rt, t_obj_color obj);

void    	ft_save_bmp(t_rt rt);

#endif
