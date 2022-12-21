/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:21:16 by ysong             #+#    #+#             */
/*   Updated: 2020/10/23 13:55:03 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int get_next_line(int fd, char **line);

size_t ft_strlen(const char *s);
int ft_strchr(char *s, int c);
char *ft_strdup(char *s1);
char *ft_strjoin(char *s1, char *s2);

#endif