/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:43:17 by ysong             #+#    #+#             */
/*   Updated: 2021/02/27 18:12:45 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_draw_to_screen(t_rt *rt)
{
	ft_render_scene(rt);
	mlx_clear_window(rt->window.mlx_ptr, rt->window.win_ptr);
	mlx_put_image_to_window(rt->window.mlx_ptr, rt->window.win_ptr,
			rt->img.id, 0, 0);
}

int		ft_exit(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}

void	ft_draw(t_rt rt)
{
	rt.i_cam = 0;
	rt.window.win_ptr = mlx_new_window(rt.window.mlx_ptr,
			rt.x, rt.y, "miniRT");
	rt.img.id = mlx_new_image(rt.window.mlx_ptr, rt.x, rt.y);
	rt.img.addr = (int *)mlx_get_data_addr(rt.img.id, &rt.img.bitpixl,
			&rt.img.len, &rt.img.end);
	mlx_hook(rt.window.win_ptr, CLOSE, 0L, ft_exit, &rt.window);
	mlx_key_hook(rt.window.win_ptr, ft_handle_keyboard, &rt);
	mlx_mouse_hook(rt.window.win_ptr, ft_handle_mouse, &rt);
	ft_draw_to_screen(&rt);
	mlx_loop(rt.window.mlx_ptr);
}
