/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:21:48 by ysong             #+#    #+#             */
/*   Updated: 2021/02/18 07:40:36 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	parse_sphere(char *line, t_rt *rt)
{
	char		**buffer;
	int			i;
	t_sphere	*sphere;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i < 4 || i > (4 + ft_bonus_option()))
		ft_error_handler(BAD_FORMAT);
	if (!(sphere = malloc(sizeof(t_sphere))))
		ft_error_handler(MEM_ALLOC);
	rt->sphere[rt->index[4] - 1] = sphere;
	rt->index[4]--;
	sphere->center = ft_load_coords(buffer[1]);
	sphere->radius = ft_ftoi(buffer[2]) / 2;
	sphere->rgb = parse_rgb(buffer[3]);
	sphere->bonus = ft_sphere_bonus(rt, &buffer[4]);
	ft_del_matrix(buffer);
}

void	parse_plane(char *line, t_rt *rt)
{
	char		**buffer;
	int			i;
	t_plane		*plane;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i < 4 || i > (4 + ft_bonus_option()))
		ft_error_handler(BAD_FORMAT);
	if (!(plane = malloc(sizeof(t_plane))))
		ft_error_handler(MEM_ALLOC);
	rt->plane[rt->index[5] - 1] = plane;
	rt->index[5]--;
	plane->point = ft_load_coords(buffer[1]);
	plane->n = ft_load_coords(buffer[2]);
	plane->rgb = parse_rgb(buffer[3]);
	plane->bonus = ft_plane_bonus(rt, &buffer[4]);
	ft_del_matrix(buffer);
}

void	parse_square(char *line, t_rt *rt)
{
	char		**buffer;
	int			i;
	t_square	*square;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i < 5 || i > (5 + ft_bonus_option()))
		ft_error_handler(BAD_FORMAT);
	if (!(square = malloc(sizeof(t_square))))
		ft_error_handler(MEM_ALLOC);
	rt->square[rt->index[6] - 1] = square;
	rt->index[6]--;
	square->center = ft_load_coords(buffer[1]);
	square->n = ft_load_coords(buffer[2]);
	square->side = ft_ftoi(buffer[3]);
	square->rgb = parse_rgb(buffer[4]);
	square->dx = (t_vec){0, 1, 0};
	square->dy = (t_vec){0, 0, 0};
	square->bonus = ft_plane_bonus(rt, &buffer[5]);
	ft_del_matrix(buffer);
}

void	parse_cylinder(char *line, t_rt *rt)
{
	char		**buffer;
	int			i;
	t_cylinder	*cylinder;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i < 6 || i > (6 + ft_bonus_option()))
		ft_error_handler(BAD_FORMAT);
	if (!(cylinder = malloc(sizeof(t_cylinder))))
		ft_error_handler(MEM_ALLOC);
	rt->cylinder[rt->index[7] - 1] = cylinder;
	rt->index[7]--;
	cylinder->point = ft_load_coords(buffer[1]);
	cylinder->n = ft_load_coords(buffer[2]);
	cylinder->radius = ft_ftoi(buffer[3]) / 2;
	cylinder->height = ft_ftoi(buffer[4]);
	cylinder->rgb = parse_rgb(buffer[5]);
	cylinder->bonus = ft_cylinder_bonus(&buffer[6]);
	ft_del_matrix(buffer);
}

void	parse_triangle(char *line, t_rt *rt)
{
	char		**buffer;
	int			i;
	t_triangle	*triangle;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i < 5 || i > (5 + ft_bonus_option()))
		ft_error_handler(BAD_FORMAT);
	if (!(triangle = malloc(sizeof(t_triangle))))
		ft_error_handler(MEM_ALLOC);
	rt->triangle[rt->index[8] - 1] = triangle;
	rt->index[8]--;
	triangle->a = ft_load_coords(buffer[1]);
	triangle->b = ft_load_coords(buffer[2]);
	triangle->c = ft_load_coords(buffer[3]);
	triangle->rgb = parse_rgb(buffer[4]);
	triangle->bonus = ft_plane_bonus(rt, &buffer[5]);
	ft_get_triangle_boundaries(triangle);
	ft_del_matrix(buffer);
}
