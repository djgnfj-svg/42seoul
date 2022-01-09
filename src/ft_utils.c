/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:15:35 by ysong             #+#    #+#             */
/*   Updated: 2022/01/10 08:10:21 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	printf("Error\n");
	exit(0);
}

int	is_sorted(t_deque *a)
{
	t_node	*node;

	node = a->header;
	while (node)
	{
		if (node->next)
		{
			if (node->item > node->next->item)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->item == a->tailer->item)
		return (1);
	else
		return (0);
}

int	is_reverse_sorted(t_deque *a)
{
	t_node	*node;

	node = a->header;
	while (node)
	{
		if (node->next)
		{
			if (node->item < node->next->item)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->item == a->tailer->item)
		return (1);
	else
		return (0);
}

static void	free_stack(t_deque *stack)
{
	t_node	*node;
	t_node	*temp;

	node = stack->header;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free(node);
		if (temp)
			node = temp;
		else
			break ;
	}
	free(stack);
}

void	free_deque(t_deque *a, t_deque *b)
{
	free_stack(a);
	free_stack(b);
}
