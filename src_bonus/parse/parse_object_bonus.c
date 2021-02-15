/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:25:52 by ysong             #+#    #+#             */
/*   Updated: 2021/02/15 07:38:10 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_texture		ft_load_texture(t_rt *rt, char *option)
{
	char		**buffer;
	int			i;
	t_texture	texture;

	i = 0;
	buffer = ft_split(option, ':');
	while (buffer[i])
		i++;
	if (i != 2)
		ft_error_handler(BAD_BONUS);
	if (!(texture.img =
				(int *)mlx_xpm_file_to_image(rt->window.mlx_ptr, buffer[1]
					, &texture.width, &texture.height)))
		ft_error_handler(BAD_TEXTURE);
	texture.val = (int *)mlx_get_data_addr(texture.img, &texture.bitpixl,
			&texture.len, &texture.end);
	ft_del_matrix(buffer);
	return (texture);
}

static	int		ft_common_options(t_rt *rt, char **option
		, t_bonus *bonus, int i)
{
	if (!ft_strncmp(option[i], "normal-disruption", 18))
	{
		bonus->id[i] = 1;
		return (1);
	}
	else if (!ft_strncmp(option[i], "bumpmap:", 8))
	{
		bonus->bumpmap = ft_load_texture(rt, option[i]);
		bonus->id[i] = 3;
		return (1);
	}
	return (0);
}

t_bonus			ft_plane_bonus(t_rt *rt, char **option)
{
	t_bonus		bonus;
	int			i;

	i = -1;
	bonus.texture.img = NULL;
	bonus.bumpmap.img = NULL;
	bonus.id[0] = 0;
	while (option[++i])
	{
		if (!ft_strncmp(option[i], "checkered", 10))
			bonus.id[i] = 2;
		else if (!ft_strncmp(option[i], "skybox:", 7))
		{
			bonus.texture = ft_load_texture(rt, option[i]);
			bonus.id[i] = 4;
		}
		else if (!ft_common_options(rt, option, &bonus, i))
			ft_error_handler(BAD_BONUS);
	}
	return (bonus);
}

t_bonus			ft_sphere_bonus(t_rt *rt, char **option)
{
	t_bonus	bonus;
	int		i;

	bonus.texture.img = NULL;
	bonus.bumpmap.img = NULL;
	bonus.id[0] = 0;
	i = -1;
	bonus.type = 's';
	while (option[++i])
	{
		if (!ft_strncmp(option[i], "rainbow", ft_strlen(option[i]) + 1))
		{
			bonus.id[i] = 5;
		}
		else if (!ft_strncmp(option[i], "uv-map:", 7))
		{
			bonus.texture = ft_load_texture(rt, option[i]);
			bonus.id[i] = 6;
		}
		else if (!ft_common_options(rt, option, &bonus, i))
			ft_error_handler(BAD_BONUS);
	}
	return (bonus);
}

t_bonus			ft_cylinder_bonus(char **option)
{
	t_bonus		bonus;
	int			i;

	i = -1;
	bonus.id[0] = 0;
	while (option[++i])
	{
		if (!ft_strncmp(option[i], "rainbow", ft_strlen(option[i]) + 1))
			bonus.id[i] = 5;
		else
			ft_error_handler(BAD_BONUS);
	}
	return (bonus);
}
