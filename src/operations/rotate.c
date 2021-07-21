/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:51 by ysong             #+#    #+#             */
/*   Updated: 2021/07/17 15:47:55 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_deque *target, int flag)
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
	if (flag == A)
		ft_putendl_fd("ra", 1);
	else if (flag == B)
		ft_putendl_fd("rb", 1);
}

void	rotate_all_stack(t_deque *a, t_deque *b, int flag)
{
	rotate_stack(a, flag);
	rotate_stack(b, flag);
	ft_putendl_fd("rr", 1);
}
