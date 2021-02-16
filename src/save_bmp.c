/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:39:13 by ysong             #+#    #+#             */
/*   Updated: 2021/02/17 06:19:59 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			ft_file_header(t_rt rt, int fd)
{
	int						filesize;
	int						padding;
	static unsigned char	fileheader[] = {
		0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};

	padding = (4 - (rt.x * 3) % 4) % 4;
	filesize = 54 + (3 * rt.x + padding) * rt.y;
	fileheader[0] = (unsigned char)('B');
	fileheader[1] = (unsigned char)('M');
	fileheader[2] = (unsigned char)(filesize);
	fileheader[3] = (unsigned char)(filesize >> 8);
	fileheader[4] = (unsigned char)(filesize >> 16);
	fileheader[5] = (unsigned char)(filesize >> 24);
	fileheader[10] = (unsigned char)(54);
	write(fd, fileheader, 14);
}

void			ft_image_header(t_rt rt, int fd)
{
	static unsigned char	infoheader[] = {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};

	infoheader[0] = (unsigned char)(40);
	infoheader[4] = (unsigned char)(rt.x);
	infoheader[5] = (unsigned char)(rt.x >> 8);
	infoheader[6] = (unsigned char)(rt.x >> 16);
	infoheader[7] = (unsigned char)(rt.x >> 24);
	infoheader[8] = (unsigned char)(rt.y);
	infoheader[9] = (unsigned char)(rt.y >> 8);
	infoheader[10] = (unsigned char)(rt.y >> 16);
	infoheader[11] = (unsigned char)(rt.y >> 24);
	infoheader[12] = (unsigned char)(1);
	infoheader[14] = (unsigned char)(24);
	write(fd, infoheader, 40);
}

void			ft_save_buffer(t_rt rt, int fd)
{
	int						i;
	int						j;
	int						padding;
	static unsigned char	zero[3] = { 0, 0, 0};

	padding = (4 - (rt.x * 3) % 4) % 4;
	i = rt.y;
	while (i > 0)
	{
		i--;
		j = 0;
		while (j < rt.x)
		{
			write(fd, &rt.img.addr[i * rt.x + j], 3);
			j++;
		}
		if (padding > 0)
			write(fd, &zero, padding);
	}
}

void			ft_save_bmp(t_rt rt)
{
	int fd;

	rt.i_cam = 0;
	rt.img.id = mlx_new_image(rt.window.mlx_ptr, rt.x, rt.y);
	rt.img.addr = (int *)mlx_get_data_addr(rt.img.id, &rt.img.bitpixl,
			&rt.img.len, &rt.img.end);
	ft_printf("converting rt to bmp...\n");
	ft_render_scene(&rt);
	if ((fd = open("output_bmp/output.bmp"
					, O_WRONLY | O_TRUNC | O_CREAT, 0744)) == -1)
		ft_error_handler(4);
	ft_file_header(rt, fd);
	ft_image_header(rt, fd);
	ft_save_buffer(rt, fd);
	close(fd);
	ft_printf("saved!\n");
}
