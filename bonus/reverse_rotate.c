/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:15:24 by chtan             #+#    #+#             */
/*   Updated: 2024/07/25 11:19:49 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stk_a)
{
	reverse_rotate(stk_a);
}

void	rrb(t_stack **stk_b)
{
	reverse_rotate(stk_b);
}

void	rrr(t_stack **stk_a, t_stack **stk_b)
{
	reverse_rotate(stk_a);
	reverse_rotate(stk_b);
}
