/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:03:39 by ysong             #+#    #+#             */
/*   Updated: 2021/01/22 09:14:48 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

int get_next_line(int fd, char **line);

size_t ft_gstrlen(const char *s);
char *ft_gstrdup(char *s1);
int ft_gstrchr(char *s, int c);
char *ft_gstrjoin(char *s1, char *s2);

#endif