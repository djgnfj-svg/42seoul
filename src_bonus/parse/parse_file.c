/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:34:51 by ysong             #+#    #+#             */
/*   Updated: 2021/02/18 07:52:38 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_load_element(char *line, t_rt *rt)
{

	if (ft_strncmp(line, "R ", 2) == 0)
		parse_res(line, rt);
	else if (ft_strncmp(line, "A ", 2) == 0)
		parse_amdient(line, rt);
	else if (ft_strncmp(line, "c ", 2) == 0)
		parse_camera(line, rt);
	else if (ft_strncmp(line, "l ", 2) == 0)
		parse_light(line, rt);
	else if (ft_strncmp(line, "sp ", 3) == 0)
		parse_sphere(line, rt);
	else if (ft_strncmp(line, "pl ", 3) == 0)
		parse_plane(line, rt);
	else if (ft_strncmp(line, "sq ", 3) == 0)
		parse_square(line, rt);
	else if (ft_strncmp(line, "cy ", 3) == 0)
		parse_cylinder(line, rt);
	else if (ft_strncmp(line, "tr ", 3) == 0)
		parse_triangle(line, rt);
	else if (line[0] != '\0')
		ft_error_handler(BAD_FORMAT);
}

static void	ft_set_elements(t_rt *rt)
{
	if (rt->index[Res_Index] != 1 || rt->index[Ambient_Index] != 1)
		ft_error_handler(BAD_FORMAT);
	if (!(rt->camera = malloc((rt->index[2] + 1) * sizeof(t_camera *))))
		ft_error_handler(MEM_ALLOC);
	rt->camera[rt->index[2]] = NULL;
	if (!(rt->light = malloc((rt->index[3] + 1) * sizeof(t_light *))))
		ft_error_handler(MEM_ALLOC);
	rt->light[rt->index[3]] = NULL;
	if (!(rt->sphere = malloc((rt->index[4] + 1) * sizeof(t_sphere *))))
		ft_error_handler(MEM_ALLOC);
	rt->sphere[rt->index[4]] = NULL;
	if (!(rt->plane = malloc((rt->index[5] + 1) * sizeof(t_plane *))))
		ft_error_handler(MEM_ALLOC);
	rt->plane[rt->index[5]] = NULL;
	if (!(rt->square = malloc((rt->index[6] + 1) * sizeof(t_square *))))
		ft_error_handler(MEM_ALLOC);
	rt->square[rt->index[6]] = NULL;
	if (!(rt->cylinder = malloc((rt->index[7] + 1) * sizeof(t_cylinder *))))
		ft_error_handler(MEM_ALLOC);
	rt->cylinder[rt->index[7]] = NULL;
	if (!(rt->triangle = malloc((rt->index[8] + 1) * sizeof(t_triangle *))))
		ft_error_handler(MEM_ALLOC);
	rt->triangle[rt->index[8]] = NULL;
}

static void	ft_number_elements(char *line, t_rt *rt)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		rt->index[Res_Index]++;
	else if (ft_strncmp(line, "A ", 2) == 0)
		rt->index[Ambient_Index]++;
	else if (ft_strncmp(line, "c ", 2) == 0)
		rt->index[Camera_Index]++;
	else if (ft_strncmp(line, "l ", 2) == 0)
		rt->index[Ligth_Index]++;
	else if (ft_strncmp(line, "sp ", 3) == 0)
		rt->index[Sphere_Index]++;
	else if (ft_strncmp(line, "pl ", 3) == 0)
		rt->index[Plane_Index]++;
	else if (ft_strncmp(line, "sq ", 3) == 0)
		rt->index[Square_Index]++;
	else if (ft_strncmp(line, "cy ", 3) == 0)
		rt->index[Cylinder_Index]++;
	else if (ft_strncmp(line, "tr ", 3) == 0)
		rt->index[Triangle_Index]++;
	else if (line[0] != '\0')
		ft_error_handler(BAD_FORMAT);
}

static void	ft_count_elements(char *rt_file, t_rt *rt)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	while (i < 9)
		rt->index[i++] = 0;
	if ((fd = open(rt_file, O_RDONLY)) < 0)
		ft_error_handler(BAD_PATH);
	while (get_next_line(fd, &line) > 0)
	{
		ft_number_elements(line, rt);
		free(line);
	}
	free(line);
	close(fd);
	ft_set_elements(rt);
	rt->n_cams = rt->index[2];
}

void	parse_file(char *rt_file, t_rt *rt)
{
	int		fd;
	char	*line;

	ft_count_elements(rt_file, rt);
	if ((fd = open(rt_file, O_RDONLY)) < 0)
		ft_error_handler(BAD_PATH);
	while (get_next_line(fd, &line) > 0)
	{
		ft_load_element(line, rt);
		free(line);
	}
	free(line);
}
