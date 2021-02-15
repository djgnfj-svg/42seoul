/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 00:09:10 by ysong             #+#    #+#             */
/*   Updated: 2021/02/15 21:58:47 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	parse_res(char *line, t_rt *rt)
{
	char	**buffer;
	int		i;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 3)
		ft_error_handler(BAD_FORMAT);
	rt->x = ft_atoi(buffer[1]);
	rt->y = ft_atoi(buffer[2]);
	ft_del_matrix(buffer);
}

void	parse_amdient(char *line, t_rt *rt)
{
	char	**buffer;
	int		i;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 3)
		ft_error_handler(BAD_FORMAT);
	rt->ambient.intensity = ft_ftoi(buffer[1]);
	if (rt->ambient.intensity < 0 || rt->ambient.intensity > 1)
		ft_error_handler(BAD_INTENSITY);
	rt->ambient.rgb = parse_rgb(buffer[2]);
	ft_del_matrix(buffer);
}

void	parse_camera(char *line, t_rt *rt)
{
	char		**buffer;
	int			i;
	int			fov_deg;
	t_camera	*camera;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 4)
		ft_error_handler(BAD_FORMAT);
	if (!(camera = malloc(sizeof(t_camera))))
		ft_error_handler(MEM_ALLOC);
	rt->camera[rt->index[2] - 1] = camera;
	rt->index[2]--;
	camera->pos = ft_load_coords(buffer[1]);
	camera->n = ft_load_coords(buffer[2]);
	fov_deg = ft_atoi(buffer[3]);
	camera->fov = tan(((double)fov_deg * M_PI) / 360);
	ft_del_matrix(buffer);
}

void	parse_light(char *line, t_rt *rt)
{
	char	**buffer;
	int		i;
	t_light	*light;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i < 4 || i > (4 + ft_bonus_option()))
		ft_error_handler(BAD_FORMAT);
	if (!(light = malloc(sizeof(t_light))))
		ft_error_handler(MEM_ALLOC);
	rt->light[rt->index[3] - 1] = light;
	rt->index[3]--;
	light->pos = ft_load_coords(buffer[1]);
	light->intensity = ft_ftoi(buffer[2]);
	if (light->intensity < 0 || light->intensity > 1)
		ft_error_handler(BAD_INTENSITY);
	light->rgb = parse_rgb(buffer[3]);
	light->parallel = ft_is_parallel_light(buffer[4]);
	ft_del_matrix(buffer);
}
