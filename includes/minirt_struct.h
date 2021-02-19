/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:42:24 by ysong             #+#    #+#             */
/*   Updated: 2021/02/20 06:11:54 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "object_struct.h"

typedef struct	s_window {
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

typedef struct	s_image{
	void		*id;
	int			*addr;
	int			len;
	int			bitpixl;
	int			end;
}				t_image;

typedef struct	s_ambient {
	double		intensity;
	t_rgb		rgb;
}				t_ambient;

typedef struct	s_camera {
	t_vec		pos;
	t_vec		n;
	t_matrix	base;
	double		fov;
}				t_camera;

typedef struct	s_light {
	t_vec		pos;
	t_vec		pos_shadow;
	double		intensity;
	t_rgb		rgb;
	t_vec		parallel;
}				t_light;

typedef struct	s_ray {
	int			p_x;
	int			p_y;
	t_vec		local;
	t_vec		global;
	t_vec		origin;
	int			color;
	double		t;
}				t_ray;

typedef struct	s_axis {
	t_vec		x;
	t_vec		y;
	t_vec		z;
}				t_axis;

typedef struct	s_axis_ref {
	int			x;
	int			y;
	int			l_x;
	int			l_y;
	int			px;
	int			py;
	int			color;
}				t_axis_ref;


typedef struct	s_rt {
	int			option[3];
	int			x;
	int			y;
	int			index[9];
	int			n_cams;
	int			i_cam;
	int			i_light;
	t_axis		axis;
	t_window	window;
	t_image		img;
	t_ambient	ambient;
	t_camera	**camera;
	t_light		**light;
	t_sphere	**sphere;
	t_plane		**plane;
	t_square	**square;
	t_cylinder	**cylinder;
	t_triangle	**triangle;
}				t_rt;

typedef struct	s_thread_info
{
	t_rt		*rt;
    t_ray       *ray;
	int			tnum;
}				t_thread_info;

#endif
