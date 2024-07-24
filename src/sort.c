/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:17:56 by chtan             #+#    #+#             */
/*   Updated: 2024/07/24 18:04:02 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	while (count_element(a) > 3)
	{
		temp = *a;
		if (temp->index == 4 || temp->index == 0)
			pb(a, b);
		else
			ra(a);
	}
	sort_3(a);
	while (count_element(b) > 0)
	{
		pa(a, b);
		if ((*a)->index == 4)
			ra(a);
	}
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*temp;
	int		first;
	int		second;
	int		third;

	temp = *stack_a;
	first = temp->val;
	second = temp->next->val;
	third = temp->next->next->val;
	if (first > second && first < third)
		sa(stack_a);
	else if (first > second && first > third && second > third)
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

int	count_element(t_stack **stack)
{
	t_stack	*temp;
	int		count;

	count = 0;
	temp = *stack;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
