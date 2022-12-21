/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:50:54 by ysong             #+#    #+#             */
/*   Updated: 2020/10/23 15:41:28 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_clean_line(char **file_value, char **line, int i)
{
	char *temp;
	int len;

	(*file_value)[i] = '\0';
	*line = ft_strdup(*file_value);
	len = ft_strlen(*file_value + i + 1);
	if (!len)
	{
		free(*file_value);
		*file_value = 0;
		return (1);
	}
	temp = ft_strdup(*file_value + i + 1);
	free(*file_value);
	*file_value = temp;
	return (1);
}

int return_EOF(char **file_value, char **line)
{
	int i;

	if (*file_value && (i = ft_strchr(*file_value, '\n')) >= 0) //파일끝이고 그안에 \n이 포함되어있으면
		return (ft_clean_line(file_value, line, i));
	else if (*file_value) //가져온 값만 유효
	{
		*line = *file_value;
		*file_value = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int get_next_line(int fd, char **line)
{
	static char *file_value[10240]; //OPEN_MAX
	char buf[BUFFER_SIZE + 1];
	int read_size;
	int temp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);									 //잘못된 입력 = 에러
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0) //파일을 읽어 온다 -1 EOF = 0 나머지양수는 읽어온 양
	{
		buf[read_size] = '\0';
		file_value[fd] = ft_strjoin(file_value[fd], buf);
		if ((temp = ft_strchr(file_value[fd], '\n')) >= 0)
			return (ft_clean_line(&file_value[fd], line, temp)); //file_value[fd]에 \n이 있으면 작동
	}
	if (read_size == -1)
		return (-1);
	return (return_EOF(&file_value[fd], line)); //0이 들어왔을때 작동
}
