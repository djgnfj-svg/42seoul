/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:51 by ysong             #+#    #+#             */
/*   Updated: 2021/07/24 00:06:47 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_deque *target)
{
	t_node	*temp;
	t_node	*header_next;

	if (target->size < 2)
		return ;
	temp = target->header;
	header_next = target->header->next;
	target->tailer->next = temp;
	temp->prev = target->tailer;
	temp->next = NULL;
	target->tailer = temp;
	target->header = header_next;
	target->header->prev = NULL;
}

void	ft_ra(t_deque *a)
{
	rotate_stack(a);
}

void	ft_rb(t_deque *b)
{
	rotate_stack(b);
}

void	ft_rr(t_deque *a, t_deque *b)
{
	rotate_stack(a);
	rotate_stack(b);
}
