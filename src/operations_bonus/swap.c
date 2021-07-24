/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:50 by ysong             #+#    #+#             */
/*   Updated: 2021/07/24 00:07:00 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_deque *target)
{
	t_node	*temp;
	t_node	*header_next;

	if (target->size < 2)
		return ;
	header_next = target->header->next;
	temp = target->header;
	if (target->size > 2)
		header_next->next->prev = target->header;
	temp->next = header_next->next;
	target->header = header_next;
	target->header->prev = NULL;
	target->header->next = temp;
	temp->prev = target->header;
	if (target->size == 2)
		target->tailer = target->header->next;
}

void	ft_sa(t_deque *a)
{
	swap_stack(a);
}

void	ft_sb(t_deque *b)
{
	swap_stack(b);
}

void	ft_ss(t_deque *a, t_deque *b)
{
	swap_stack(a);
	swap_stack(b);
}
