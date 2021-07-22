/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:56:40 by ysong             #+#    #+#             */
/*   Updated: 2021/07/21 19:50:20 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_deque *a)
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

void	printingdeque(t_deque *a, int flag)
{
	t_node	*temp;

	temp = a->header;
	if (flag == 1)
		printf("A : ");
	else
		printf("B : ");
	while (temp)
	{
		printf("%d ",temp->item);
		temp = temp->next;
	}
	printf("\n");
}

void printall(char *title, t_deque *a, t_deque *b, t_op_count *opc)
{
	printf(C_BLUE"-----%s-----\n",title);
	printingdeque(a, 1);
	printingdeque(b, 2);
	printf(C_YLLW"opc_piv_small = %ld\n",opc->piv_small);
	printf(C_RED"opc_piv_big = %ld\n"C_AQUA,opc->piv_big);
}

int	main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;

	if (ac < 2)
		return (0);
	arg_check_and_init(ac - 1, av, &a, &b);
	if (!is_sorted(a))
		push_swap(a, b);
	printingdeque(a, 1);
	free_deque(a, b);
	return (0);
}
