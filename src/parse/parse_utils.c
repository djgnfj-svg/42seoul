/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:46:10 by ysong             #+#    #+#             */
/*   Updated: 2021/02/15 21:47:30 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//이부분하면됨
double	ft_ten_powerf(int p)
{
	double	t;
	int		i;

	t = 1;
	i = 0;
	if (p < 0)
	{
		p = -p;
		while (i++ < p)
			t = t / 10;
	}
	else if (p > 0)
		while (i++ < p)
			t = t * 10;
	return (t);
}

double	ft_ftoi(char *str)
{
	int	k;
	int	d;
	int	l;
	int	i;

	i = 0;
	d = ft_atoi(str);
	while (str[i] != '.' && str[i])
		i++;
	if (!str[i])
		return ((double)d);
	i++;
	l = ft_strlen(&str[i]);
	k = ft_atoi(&str[i]);
	if (!d && str[0] == '-')
		k *= -1;
	return ((double)(d + k * ft_ten_powerf(-l)));
}

void	ft_del_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}

t_rgb			parse_rgb(char *buffer)
{
	char	**buff_aux;
	t_rgb	color;

	buff_aux = ft_split(buffer, ',');
	//참고 내가 바꿈
	color.r = ft_ftoi(buff_aux[0]);
	color.g = ft_ftoi(buff_aux[1]);
	color.b = ft_ftoi(buff_aux[2]);
	if (color.r > 255 || color.g > 255 || color.b > 255 ||\
		color.r < 0 || color.g < 0 || color.b < 0)
		ft_error_handler(BAD_RGB);
	ft_del_matrix(buff_aux);
	return (color);
}

t_vec		ft_load_coords(char *buffer)
{
	char		**buff_aux;
	t_vec	vector;

	buff_aux = ft_split(buffer, ',');
	vector.x = ft_ftoi(buff_aux[0]);
	vector.y = ft_ftoi(buff_aux[1]);
	vector.z = ft_ftoi(buff_aux[2]);
	ft_del_matrix(buff_aux);
	return (vector);
}
