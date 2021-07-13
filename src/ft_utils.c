/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:15:35 by ysong             #+#    #+#             */
/*   Updated: 2021/07/13 11:53:14 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	printf("error\n");
	exit(0);
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

void	free_all(t_deque *a, t_deque *b)
{
	free_stack(a);
	free_stack(b);
}
