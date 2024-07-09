/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:41:50 by chtan             #+#    #+#             */
/*   Updated: 2024/07/04 13:59:31 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*cur;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	cur->next = temp;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putstr_fd("ra", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_putstr_fd("rr", 1);
}
