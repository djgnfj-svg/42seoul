/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_shadows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 04:48:10 by ysong             #+#    #+#             */
/*   Updated: 2021/02/15 07:34:53 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_shadow_square(t_rt rt, t_ray *r, int i)
{
	t_auxplane	auxplane;

	auxplane.point = s.square[i]->center;
	auxplane.n = s.square[i]->n;
	if (ft_intersect_plane(&s, &auxplane, r))
		if (ft_get_point_plane(&s, &auxplane, r))
			if (ft_intersect_inside_square(s, &auxplane, i))
				if (ft_between_light_source(s.light[s.i_light]->pos
							, auxplane.p, r->origin))
					return (1);
	return (0);
}
