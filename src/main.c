/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:34:50 by ysong             #+#    #+#             */
/*   Updated: 2021/02/18 23:28:26 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			ft_initialize_options(t_rt *rt)
{
	int	i;

	i = -1;
	while (++i < 14)
		rt->option[i] = 0;
}

void			ft_save_option(char *argv, t_rt *rt)
{
	if (!ft_strncmp(argv, "--save", ft_strlen(argv) + 1))
	{
		if (rt->option[0])
			ft_error_handler(DOUBLE_FLAG);
		rt->option[0] = 1;
	}
	else
		ft_error_handler(BAD_FLAG);
}

void			ft_check_options(int argc, char **argv, t_rt *rt)
{
	int	i;

	i = 1;
	while (++i < argc)
		ft_save_option(argv[i], rt);
}

int		main(int argc, char **argv)
{
	t_rt	rt;
	char	*aux;

	ft_initialize_options(&rt);
	if (argc > 1 && (aux = ft_strnstr(argv[1], ".rt", \
		ft_strlen(argv[1]))) && !(*(aux + 3)))
	{
		rt.window.mlx_ptr = mlx_init();
		ft_check_options(argc, argv, &rt);
		parse_file(argv[1], &rt);
		if (rt.option[0])
			ft_save_bmp(rt);
		else
			ft_draw(rt);
	}
	else
		ft_error_handler(1);
	ft_clean_memory(rt);
	return (0);
}
