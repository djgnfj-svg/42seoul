/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:07:54 by ysong             #+#    #+#             */
/*   Updated: 2021/07/13 11:18:48 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*init_deque(void)
{
	t_deque	*stack;

	stack = (t_deque *)malloc(sizeof(t_deque));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->header = NULL;
	stack->tailer = NULL;
	return (stack);
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

static void	connect_list(t_node **temp, t_node **node, t_deque **stack)
{
	if (!*node)
	{
		*node = *temp;
		(*stack)->header = *node;
	}
	else
	{
		(*node)->next = *temp;
		(*temp)->prev = *node;
		*node = (*node)->next;
	}
}

static int	set_node(char *av, t_node **node, t_deque **stack)
{
	int		i;
	char	**arg;
	t_node	*temp;

	arg = ft_split(av, ' ');
	if (!arg || !*arg)
		return (0);
	i = -1;
	while (arg[++i])
	{
		temp = init_node();
		if (!temp)
			print_error();
		temp->item = ft_atoi(arg[i]);
		connect_list(&temp, node, stack);
		(*stack)->size++;
		free(arg[i]);
	}
	free(arg);
	return (1);
}

t_node	*make_stack(int ac, char **av, t_deque **stack)
{
	int		i;
	int		ret;
	t_node	*node;

	i = 0;
	node = NULL;
	while (++i < ac)
	{
		ret = set_node(av[i], &node, stack);
		if (!ret)
			print_error();
	}
	if (!node->next)
		(*stack)->tailer = node;
	while (node->prev)
		node = node->prev;
	return (node);
}
