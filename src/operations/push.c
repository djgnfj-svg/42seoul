/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:53 by ysong             #+#    #+#             */
/*   Updated: 2021/07/14 01:17:32 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	from_size_one(t_deque *from, t_deque *to)
{
	if (to->size == 0)
	{
		to->header = from->header;
		to->tailer = to->header;
	}
	else
	{
		to->header->prev = from->header;
		from->header->next = to->header;
		to->header = to->header->prev;
	}
	from->header = NULL;
	from->tailer = NULL;
}

static void	push_pop(t_deque *from, t_deque *to)
{
	if (from->size == 1)
		from_size_one(from, to);
	else
	{
		if (to->size == 0)
		{
			to->header = from->header;
			to->tailer = to->header;
			from->header = from->header->next;
			from->header->prev = NULL;
			to->header->next = NULL;
		}
		else
		{
			to->header->prev = from->header;
			from->header = from->header->next;
			from->header->prev = NULL;
			to->header->prev->next = to->header;
			to->header = to->header->prev;
		}
	}
	to->size++;
	from->size--;
}

void	push_stack(t_deque *from, t_deque *to, int flag)
{
	if (from->size == 0)
		return ;
	push_pop(from, to);
	if (flag == A)
		ft_putendl_fd("pa", 1);
	else if (flag == B)
		ft_putendl_fd("pb", 1);
}
