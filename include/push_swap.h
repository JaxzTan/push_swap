/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:35:56 by chtan             #+#    #+#             */
/*   Updated: 2024/07/25 11:41:16 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				val;
	int				index;
	int				pos;
	int				costa;
	int				costb;
}	t_stack;

// swap node
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// rotate
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// reverse_rotate
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//push
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

//  check input
int		check_dup(char **av);
int		check_digit(char **av);
char	**get_input(int ac, char **av);
int		*turn_array_to_int(char **array);

//	assign stack
t_stack	*assign_stack_a(int *input, int ac);

// label index for each node
void	label_index(t_stack **stack, int *array);
int		get_lstsize(t_stack **stack);
void	bubble_sort(int *stack, int size);
void	assign_index(t_stack **stack);

// simple sort 2 & 3
void	sort_3(t_stack **stack_a);
int		count_element(t_stack **stack);
void	sort(t_stack **a, t_stack **b, int num);
void	sort_5(t_stack **a, t_stack **b);

// utils
int		is_sorted(t_stack **a);
void	error_message(void);
int		count_word(char **str);
long	ft_atol(char *str);
void	label_possition(t_stack **stack);

// temp
void	printLinkedList(t_stack **head);
void	order_stack_a(t_stack **stk_a);

// sort big
void	sort_big(t_stack **a, t_stack **b);
void	push_node(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b);
t_stack	*cheapest(t_stack **stack);
void	rotate_both(t_stack *node_to_push, t_stack **a, t_stack **b);

// counting cost
void	calculate_cost(t_stack **a, t_stack **b);
t_stack	*find_smallest(t_stack **stack);
t_stack	*find_target(t_stack **a, int cur_index);
int		cost(t_stack *node);

#endif