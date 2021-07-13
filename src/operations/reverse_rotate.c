/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:52 by ysong             #+#    #+#             */
/*   Updated: 2021/07/14 01:21:34 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_deque *target, int flag)
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
	if (flag == A)
		ft_putendl_fd("rra", 1);
	else if (flag == B)
		ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_all_stack(t_deque *a, t_deque *b)
{
	reverse_rotate_stack(a, -1);
	reverse_rotate_stack(b, -1);
	ft_putendl_fd("rrr", 1);
}
