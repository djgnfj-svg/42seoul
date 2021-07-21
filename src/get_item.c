/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_counts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:20:12 by ysong             #+#    #+#             */
/*   Updated: 2021/07/13 11:20:24 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_op_counts(int item[])
{
	int	i;
	int	j;
	int	tmp;

	i = 5;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (item[j] > item[j + 1])
			{
				tmp = item[j + 1];
				item[j + 1] = item[j];
				item[j] = tmp;
			}
		}
	}
	return (item[2]);
}

int	get_mid_item_five(t_node *node)
{
	int	i;
	int	item[5];

	i = -1;
	while (++i < 5)
	{
		item[i] = node->item;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (sort_op_counts(item));
}

int	get_min_item(t_node *node, int size)
{
	int	min;

	min = node->item;
	while (size--)
	{
		if (min > node->item)
			min = node->item;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (min);
}

int	get_max_item(t_node *node, int size)
{
	int	max;

	max = node->item;
	while (size--)
	{
		if (max < node->item)
			max = node->item;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}
