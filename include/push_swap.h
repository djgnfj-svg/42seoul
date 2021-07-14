/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:56:50 by ysong             #+#    #+#             */
/*   Updated: 2021/07/14 01:20:57 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

# define A 1
# define B 2
# define ALL 3

typedef struct s_node
{
	int				item;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_deque
{
	t_node	*header;
	t_node	*tailer;
	int		size;
}			t_deque;

typedef struct s_item
{
	long	piv_big;
	long	piv_small;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
}			t_item;

int		arg_check(int last, char **av);

void	print_error(void);
void	free_all(t_deque *a, t_deque *b);
t_deque	*init_deque(void);

void	init_item(t_item *var);
void	select_pivot(int r, t_deque *target, t_item *var);
void	push_swap(t_deque *a, t_deque *b);

int		get_mid_item_five(t_node *node);
int		get_min_item(t_node *node, int size);
int		get_max_item(t_node *node, int size);

t_node	*make_stack(int ac, char **av, t_deque **target);
/*
	operations
*/
void	push_stack(t_deque *from, t_deque *to, int flag);

void	reverse_rotate_stack(t_deque *target, int flag);
void	reverse_rotate_all_stack(t_deque *a, t_deque *b);

void	rotate_stack(t_deque *target, int flag);
void	rotate_all_stack(t_deque *a, t_deque *b, int flag);

void	swap_stack(t_deque *target, int flag);
void	swap_all_stack(t_deque *a, t_deque *b, int flag);
/*
		sort
*/
void	handle_arg_two(t_deque *a, t_deque *b, int flag);
void	handle_under_three(int r, t_deque *a, t_deque *b, int flag);

void	a_to_b(int r, t_deque *a, t_deque *b, int *cnt);

void	hanlde_sort_five(int size, t_deque *a, t_deque *b, int flag);
void	handle_arg_five(t_deque *a, t_deque *b);

void	handle_arg_three_a(int r, t_deque *a);


void	handle_arg_three_b(int r, t_deque *a, t_deque *b);

void	b_to_a(int r, t_deque *a, t_deque *b, int *cnt);
#endif
