/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:35:56 by chtan             #+#    #+#             */
/*   Updated: 2024/07/02 17:30:02 by chtan            ###   ########.fr       */
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

//  check input
int		check_dup(char **av);
int		check_num(int ac, char **av);
char	**get_input(int ac, char **av);

//	assign stack
void	assign_node(t_stack **stack, int nb);
int		assign_stack_a(t_stack **a, t_stack **input, int ac);

// swap node
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// rotate

#endif