/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:50 by ysong             #+#    #+#             */
/*   Updated: 2021/07/14 00:18:44 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_deque *target, int flag)
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
	if (flag == A)
		ft_putendl_fd("sa", 1);
	else if (flag == B)
		ft_putendl_fd("sb", 1);
}

void	swap_all_stack(t_deque *a, t_deque *b, int flag)
{
	swap_stack(a, flag);
	swap_stack(b, flag);
	if (flag == ALL)
		ft_putendl_fd("ss", 1);
}
