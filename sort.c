/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:17:56 by chtan             #+#    #+#             */
/*   Updated: 2024/07/09 13:23:09 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// for 2 node there is only 2 possible either return directly or swap
void	sort_2(t_stack **stack_a)
{
	t_stack	*temp;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	assign_index(stack_a);
	temp = *stack_a;
	if (temp->val > temp->next->val)
		sa(&stack_a);
	else
		ft_putstr_fd("ok", 1);
}
// sorting 3 node is not that hard so i'll use possiblility to solve this

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
		sa(&stack_a);
	else if (first > second && first > third && second < third)
	{
		sa(&stack_a);
		rra(&stack_a);
	}
	else if (first > second && first > third && second < third)
		ra(&stack_a);
	else if (first < second && first < third && second > third)
	{
		sa(&stack_a);
		ra(&stack_a);
	}
	else if (first < second && first > third && second > third)
		rra(&stack_a);
}

int	count_element(t_stack **a, int count)
{
	t_stack	*temp;

	count = 0;
	temp = *a;
	while (temp->next)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	sort(t_stack **a)
{
	int	i;

	i = 0;
	count_element(a, i);
	if (i == 2)
		sort_2(a);
	else if (i == 3)
		sort_3(a);
}
