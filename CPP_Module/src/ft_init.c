/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:07:54 by ysong             #+#    #+#             */
/*   Updated: 2021/07/21 14:47:22 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*init_deque(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (!deque)
		return (NULL);
	deque->size = 0;
	deque->header = NULL;
	deque->tailer = NULL;
	return (deque);
}

static t_node	*init_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->item = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	connect_list(t_node **temp, t_node **node, t_deque **deque)
{
	if (!*node)
	{
		*node = *temp;
		(*deque)->header = *node;
	}
	else
	{
		(*node)->next = *temp;
		(*temp)->prev = *node;
		*node = (*node)->next;
	}
	(*deque)->size++;
}

static int	set_node(char **av, t_node **node, t_deque **deque)
{
	int		i;
	t_node	*temp;

	i = 0;
	while (av[++i])
	{
		temp = init_node();
		if (!temp)
			print_error();
		temp->item = ft_atoi(av[i]);
		connect_list(&temp, node, deque);
	}
	return (1);
}

t_node	*connect_deque(char **av, t_deque **deque)
{
	int		ret;
	t_node	*node;

	node = NULL;
	ret = set_node(av, &node, deque);
	if (!ret)
		print_error();
	if (!node->next)
		(*deque)->tailer = node;
	while (node->prev)
		node = node->prev;
	return (node);
}
