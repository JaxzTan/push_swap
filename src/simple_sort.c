/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:47:29 by chtan             #+#    #+#             */
/*   Updated: 2024/07/08 18:09:11 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// for 2 node there is only 2 possible either return directly or swap
void	sort_2(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	assign_index(stack);
	temp = *stack;
	if (temp->val > temp->next->val)
		sa(&stack);
	else
		ft_putstr_fd("ok", 1);
}
// sorting 3 node is not that hard so i'll use possiblility to solve this

void	sort_3(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	temp = *stack_a;
	first = temp->val;
	second = temp->next->val;
	third = temp->next->next->index;
	if (first > second && first < third)
		sa(stack_a);
	else if (first > second && first > third && second < third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && first > third && second < third)
		ra(stack_a);
	else if (first < second && first < third && second > third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && first > third && second > third)
		rra(stack_a);
}
