/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:52 by ysong             #+#    #+#             */
/*   Updated: 2021/07/24 00:06:41 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_deque *target)
{
	t_node	*temp;
	t_node	*tailer_prev;

	if (target->size < 2)
		return ;
	temp = target->tailer;
	tailer_prev = target->tailer->prev;
	target->header->prev = temp;
	temp->next = target->header;
	temp->prev = NULL;
	target->header = temp;
	target->tailer = tailer_prev;
	target->tailer->next = NULL;
}

void	ft_rra(t_deque *a)
{
	reverse_rotate_stack(a);
}

void	ft_rrb(t_deque *b)
{
	reverse_rotate_stack(b);
}

void	ft_rrr(t_deque *a, t_deque *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}
