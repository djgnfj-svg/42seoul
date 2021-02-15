/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 04:19:43 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 04:45:57 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

typedef struct		s_thread_info
{
	t_rt			*rt;
    double          px;
    double          py;
    t_ray           ray;
	int				tnum;
}					t_thread_info;

t_thread_info		*tinfo_new(t_rt *rt, int tnum, t_ray ray)
{
	t_thread_info	*result;

	result->rt = rt;
	result->ray = ray;
	result->tnum = tnum;
	return (result);
}

void					draw_hittable_pthread(t_rt *rt)
{
	pthread_t			*threads;
	int					pnum;
	t_thread_info		*info;
    t_ray               ray;

	pnum = 0;
	while (++pnum <= PTHREAD_CNT)
	{
		info = tinfo_new(rt, pnum, ray);
		pthread_create(&(threads[pnum - 1]), NULL, ft_render_scenep, (void *)info);
	}
	pnum = 0;
	while (++pnum <= PTHREAD_CNT)
		pthread_join(threads[pnum - 1], NULL);
	free(threads);
}

int					tinfo_get_step(t_thread_info *info)
{
	return (info->rt->x / PTHREAD_CNT);
}

int					tinfo_get_y_init_value(t_thread_info *info)
{
	if (info->tnum == PTHREAD_CNT)
		return (info->rt->x);
	return (tinfo_get_step(info) * info->tnum);
}

void	ft_render_scenep(void *arg)
{
	t_thread_info		*tinfo;

	tinfo = (t_thread_info *)arg;
    int px;
    int py;
    px = tinfo_get_y_init_value(tinfo);
    while ((--px) >= (tinfo_get_step(tinfo) * (tinfo->tnum - 1)))
	{
		py = 0;
		while (py < tinfo->rt->y)
		{
			ft_render_pxl_antialiasing((double)px, (double)py, \
            &(tinfo->ray), tinfo->rt);
			ft_fill_img_buf(&(tinfo->rt->img), px, py, tinfo->ray.color);
			py++;
		}
		px++;
	}
}