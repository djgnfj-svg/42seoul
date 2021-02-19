/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:34:50 by ysong             #+#    #+#             */
/*   Updated: 2021/02/20 03:12:09 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt_bonus.h"

static void	ft_bonus_options(char *argv, t_rt *rt)
{
	if (!ft_strncmp(argv, "--save", ft_strlen(argv) + 1))
		rt->option[0] = 1;
	else if (!ft_strncmp(argv, "--sepia", ft_strlen(argv) + 1))
		rt->option[1] = 1;
	else if (!ft_strncmp(argv, "--anti", ft_strlen(argv) + 1))
		rt->option[2] = 1;
	else
		ft_error_handler(BAD_FLAG);
}

static void	ft_check_options(int argc, char **argv, t_rt *rt)
{
	int		i;

	i = -1;
	while (++i < 3)
		rt->option[i] = 0;
	i = 1;
	while (++i < argc)
		ft_bonus_options(argv[i], rt);
}

int			main(int argc, char **argv)
{
	t_rt	rt;

	ft_check_options(argc, argv, &rt);
	if (argc > 1 && !(ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 4)))
	{
		rt.window.mlx_ptr = mlx_init();
		parse_file(argv[1], &rt);
		if (rt.option[0])
			ft_save_bmp(rt);
		else
			ft_draw(rt);
	}
	else
		ft_error_handler(MEM_ALLOC);
	ft_clean_memory(rt);
	return (0);
}
