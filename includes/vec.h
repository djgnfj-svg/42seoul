/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:31:15 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 01:02:45 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
#define VEC_H

#include "minirt_struct.h"

t_vec		ft_k_mul_vec(double k, t_vec v);
t_vec		ft_sub_vec(t_vec u, t_vec v);
t_vec		ft_add_vec(t_vec u, t_vec v);
double			ft_dot_product(t_vec u, t_vec v);
t_vec		ft_cross_product(t_vec u, t_vec v);
void			ft_normalize_vector(t_vec *v);
double			ft_mod_vector(t_vec v);
t_vec		ft_mtx_vct_prod(t_matrix m, t_vec v);
double			ft_abs(double num);
double			ft_det(t_matrix m);
t_matrix		ft_inv_matrix(t_matrix m);
int				ft_minus_vector(t_vec *v);
t_vec		ft_set_axis(char axis);
t_vec		ft_set_hor_axis(t_vec n);
int				ft_isvoid(t_vec vector);
#endif