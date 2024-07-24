/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:41:50 by chtan             #+#    #+#             */
/*   Updated: 2024/07/24 17:01:59 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	current = *stack;
	while (current->next)
		current = current->next;
	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	current->next = temp;
}

void	ra(t_stack **stk_a)
{
	rotate(stk_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stk_b)
{
	rotate(stk_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stk_a, t_stack **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
	ft_printf("rr\n");
}
