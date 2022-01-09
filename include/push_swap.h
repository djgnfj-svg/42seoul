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
}			t_op_count;

int		arg_check_and_init(int last, char **av, t_deque **a, t_deque **b);

void	print_error(void);
int		is_sorted(t_deque *a);
int		is_reverse_sorted(t_deque *a);
void	free_deque(t_deque *a, t_deque *b);
t_deque	*init_deque(void);

void	init_op_count(t_op_count *opc);
void	select_pivot(int r, t_deque *target, t_op_count *opc);
void	push_swap(t_deque *a, t_deque *b);

int		get_mid_item_five(t_node *node);
int		get_min_item(t_node *node, int size);
int		get_max_item(t_node *node, int size);

t_node	*connect_deque(char **av, t_deque **stack);
/*
	operations
*/
void	ft_pb(t_deque *a, t_deque *b);
void	ft_pa(t_deque *b, t_deque *a);

void	ft_rra(t_deque *a);
void	ft_rrb(t_deque *b);
void	ft_rrr(t_deque *a, t_deque *b);

void	ft_ra(t_deque *a);
void	ft_rb(t_deque *b);
void	ft_rr(t_deque *a, t_deque *b);

void	ft_sa(t_deque *a);
void	ft_sb(t_deque *b);
void	ft_ss(t_deque *a, t_deque *b);
/*
		sort
*/
void	arg_two(t_deque *a, t_deque *b, int flag);
void	under_three(int r, t_deque *a, t_deque *b, int flag);
void	a_to_b(int r, t_deque *a, t_deque *b, int *cnt);
void	hanlde_sort_five(int size, t_deque *a, t_deque *b, int flag);
void	arg_five(t_deque *a, t_deque *b);
void	arg_three_a(int r, t_deque *a);
void	arg_three_b(int r, t_deque *a, t_deque *b);
void	b_to_a(int r, t_deque *a, t_deque *b, int *cnt);

void	printingdeque(t_deque *a, int flag);
void	printall(char *str, t_deque *a, t_deque *b, t_op_count *opc);

void	do_reverse_rotate(char *buf, t_deque *a, t_deque *b);
void	do_rotate(char *buf, t_deque *a, t_deque *b);
void	do_rotate(char *buf, t_deque *a, t_deque *b);
void	do_swap(char *buf, t_deque *a, t_deque *b);
void	do_push(char *buf, t_deque *a, t_deque *b);
#endif
