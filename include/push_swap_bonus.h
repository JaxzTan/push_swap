/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:56:45 by chtan             #+#    #+#             */
/*   Updated: 2024/07/25 11:22:19 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
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

//assign stack
t_stack	*assign_stack_a(int *str, int num);

// get_input
int		*turn_array_to_int(char **array);
int		check_dup(char **av);
int		check_digit(char **av);
char	**get_input(int ac, char **av);

// utils
int		is_sorted(t_stack **a);
void	error_message(void);
long	ft_atol(char *str);
int		count_word(char **array);
void	label_possition(t_stack **stack);

//main
int		do_both(t_stack **a, t_stack **b, char *ins);
void	checker(t_stack **a, t_stack **b);
int		do_both(t_stack **a, t_stack **b, char *ins);
void	checker(t_stack **a, t_stack **b);

#endif