/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:06:10 by ysong             #+#    #+#             */
/*   Updated: 2021/02/24 14:09:03 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_STRUCT_H
# define OBJECT_STRUCT_H

typedef struct	s_vec {
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_matrix {
	t_vec		vx;
	t_vec		vy;
	t_vec		vz;
}				t_matrix;

typedef	struct	s_rgb {
	double		r;
	double		g;
	double		b;
}				t_rgb;

typedef struct	s_texture {
	void		*img;
	int			*val;
	int			width;
	int			height;
	int			len;
	int			bitpixl;
	int			end;
}				t_texture;

typedef struct	s_bonus{
	char		type;
	int			id[2];
	t_texture	texture;
	t_texture	bumpmap;
}				t_bonus;

typedef struct	s_obj_color{
	t_vec		p;
	t_vec		center;
	t_vec		normal;
	t_vec		light;
	t_vec		ray;
	t_rgb		rgb;
	t_bonus		bonus;
}				t_obj_color;

typedef struct	s_sphere {
	t_vec		center;
	double		radius;
	t_rgb		rgb;
	double		p_oc;
	double		d;
	t_vec		p;
	t_vec		oc;
	t_vec		n;
	t_bonus		bonus;
}				t_sphere;

typedef struct	s_plane {
	t_vec		point;
	t_vec		n;
	t_rgb		rgb;
	t_bonus		bonus;
}				t_plane;

typedef struct	s_square {
	t_vec		n;
	t_vec		center;
	t_rgb		rgb;
	t_vec		dx;
	t_vec		dy;
	double		side;
	t_bonus		bonus;
}				t_square;

typedef struct	s_triangle {
	t_vec		a;
	t_vec		b;
	t_vec		c;
	t_rgb		rgb;
	double		det;
	char		equation;
	t_vec		e0;
	t_vec		e1;
	t_vec		e2;
	t_vec		p0;
	t_bonus		bonus;
}				t_triangle;

typedef struct	s_cylinder {
	t_vec		point;
	t_vec		n;
	t_rgb		rgb;
	double		radius;
	double		height;
	double		a;
	double		b;
	double		c;
	double		x1;
	double		x2;
	double		m;
	double		discr;
	t_vec		oc;
	t_vec		p;
	t_vec		center;
	t_vec		nsurface;
	t_bonus		bonus;
}				t_cylinder;

typedef struct	s_auxplane {
	t_vec		point;
	t_vec		n;
	double		den;
	double		num;
	t_vec		l;
	t_vec		p;
	t_vec		po;
}				t_auxplane;
#endif
