/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 04:19:43 by ysong             #+#    #+#             */
/*   Updated: 2021/02/24 14:11:36 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_thread_info		*tinfo_new(t_rt *rt, int tnum)
{
	t_thread_info	*result;

	result = (t_thread_info *)malloc(sizeof(t_thread_info));
	result->rt = rt;
	result->tnum = tnum;
	return (result);
}

static int			tinfo_get_step(t_thread_info *info)
{
	return (info->rt->x / PTHREAD_CNT);
}

static int			tinfo_get_y_init_value(t_thread_info *info)
{
	if (info->tnum == PTHREAD_CNT)
		return (info->rt->x);
	return (tinfo_get_step(info) * info->tnum);
}

void				*ft_render_pthread(void *arg)
{
	t_thread_info	*tinfo;
	int				px;
	int				py;
	t_ray			ray;

	tinfo = (t_thread_info *)arg;
	px = tinfo_get_y_init_value(tinfo);
	while (--px >= (tinfo_get_step(tinfo) * (tinfo->tnum - 1)))
	{
		py = 0;
		while (py < tinfo->rt->y)
		{
			if (tinfo->rt->option[2])
				ft_render_pxl_antialiasing((double)px, (double)py, \
							&ray, tinfo->rt);
			else
				ft_render_pxl((double)px, (double)py, \
							&ray, tinfo->rt);
			ft_fill_img_buf(&(tinfo->rt->img), px, py, ray.color);
			py++;
		}
	}
	free(tinfo);
	return (0);
}

void				draw_hittable_pthread(t_rt *rt)
{
	pthread_t		*threads;
	int				pnum;
	t_thread_info	*info;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * PTHREAD_CNT);
	pnum = 0;
	while (++pnum <= PTHREAD_CNT)
	{
		info = tinfo_new(rt, pnum);
		pthread_create(&(threads[pnum - 1]), NULL,\
						ft_render_pthread, (void *)info);
	}
	pnum = 0;
	while (++pnum <= PTHREAD_CNT)
		pthread_join(threads[pnum - 1], NULL);
	free(threads);
}
