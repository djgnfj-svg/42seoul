/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:53 by ysong             #+#    #+#             */
/*   Updated: 2021/07/24 01:25:11 by ysong            ###   ########.fr       */
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

void	ft_pa(t_deque *b, t_deque *a)
{
	if (b->size == 0)
		return ;
	push_pop(b, a);
}

void	ft_pb(t_deque *a, t_deque *b)
{
	if (a->size == 0)
		return ;
	push_pop(a, b);
}
