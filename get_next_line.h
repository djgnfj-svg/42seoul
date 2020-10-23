/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:03:39 by ysong             #+#    #+#             */
/*   Updated: 2020/10/23 13:52:10 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

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