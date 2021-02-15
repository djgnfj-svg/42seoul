/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:42:31 by ysong             #+#    #+#             */
/*   Updated: 2021/01/14 02:12:54 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			num_base;
	int			num_sign;
}				t_info;

int				ft_printf(const char *format, ...);
int				ft_solution(va_list ap, char *input);
int				ft_print_type(va_list ap, t_info *info);
void			ft_check_info(va_list ap, char *input, t_info *info, int i);
int				ft_check_type(char c, t_info *info);

int				ft_put_width(t_info *info);
int				ft_print_char(int c, t_info *info);

int				ft_print_string(char *str, t_info *info);
char			*soultion_str(char *str, int end, char *buf, t_info *info);

int				ft_print_num(unsigned long long num, t_info *info);
int				ft_put_minus(int buf_len, t_info *info, char **buf);
char			*put_prec_str(unsigned long long num, t_info *info, char *buf);

void			ft_init_info(t_info *info);
void			check_width_prec(va_list ap, char *input, t_info *info, int i);
char			*ft_baseset(char type);
int				ft_numlen(unsigned long long num, t_info *info);
char			*ft_put_width_str(char *buf, t_info *info);

#endif
