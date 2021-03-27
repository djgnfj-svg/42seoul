/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:34:32 by ysong             #+#    #+#             */
/*   Updated: 2021/03/27 15:06:20 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

void	parse_file(char *rt_file, t_rt *rt);

void	parse_res(char *line, t_rt *rt);
void	parse_amdient(char *line, t_rt *rt);
void	parse_camera(char *line, t_rt *rt);
void	parse_light(char *line, t_rt *rt);

void	parse_sphere(char *line, t_rt *rt);
void	parse_plane(char *line, t_rt *rt);
void	parse_square(char *line, t_rt *rt);
void	parse_cylinder(char *line, t_rt *rt);
void	parse_triangle(char *line, t_rt *rt);

double	ft_ftoi(char *str);
void	ft_del_matrix(char **matrix);
t_rgb	parse_rgb(char *buffer);
t_vec	ft_load_coords(char *buffer);

int		ft_check_normalized(t_vec *nor);
void	ft_get_triangle_boundaries(t_triangle *triangle);
int		ft_bonus_option(void);
#endif
