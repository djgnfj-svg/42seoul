/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:00:50 by ysong             #+#    #+#             */
/*   Updated: 2021/02/18 23:26:43 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			ft_error_handler(int error_id)
{
	errno = error_id;
	if (error_id == BAD_PATH)
		perror("<<ERROR>> wrong scene path");
	else if (error_id == MEM_ALLOC)
		perror("<<ERROR>> wrong scene path");
	else if (error_id == BAD_RGB)
		perror("<<ERROR>> wrong RGB values, please check format");
	else if (error_id == BAD_FLAG)
		perror("<<ERROR>> wrong flag");
	else if (error_id == BAD_INTENSITY)
		perror("<<ERROR>> wrong light/ambient value, set it between [0, 1]");
	else if (error_id == DOUBLE_FLAG)
		perror("<<ERROR>> duplicated flag");
	else if (error_id == BAD_FORMAT)
		perror("<<ERROR>> wrong scene, please check format");
	else if (error_id == BAD_BONUS)
		perror("<<ERROR>> wrong scene bonus, please check format");
	else if (error_id == BAD_TEXTURE)
		perror("<<ERROR>> wrong image texture path, please check scene");
	exit(EXIT_FAILURE);
}
