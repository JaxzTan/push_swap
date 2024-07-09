/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:35:56 by chtan             #+#    #+#             */
/*   Updated: 2024/07/09 15:03:14 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483637

typedef struct s_stack
{
	struct s_stack	*next;
	int				val;
	int				index;
}	t_stack;

// swap node
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
int		check_num(int ac, char **av);
char	**get_input(int ac, char **av);

//	assign stack
void	assign_node(t_stack **stack, int nb);
t_stack	**assign_stack_a(t_stack **a, char **input, int ac);

// label index for each node
void	label_index(t_stack **stack, int *array);
int		get_lstsize(t_stack **stack);
void	bubble_sort(int *stack, int size);
void	assign_index(t_stack **stack);

// simple sort 2 & 3
void	sort_2(t_stack **stack);
void	sort_3(t_stack **stack_a);
int		count_element(t_stack **a, int count);
void	sort(t_stack **a);

// utils
int		is_sorted(t_stack **a);

#endif