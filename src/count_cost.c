/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:42:48 by chtan             #+#    #+#             */
/*   Updated: 2024/07/25 18:58:40 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
add cost a and cost b become total cost
*/
int	total_cost(t_stack *node)
{
	int	cost;

	cost = 0;
	if (node->costa < 0)
		cost += node->costa * -1;
	else
		cost += node->costa;
	if (node->costb < 0)
		cost += node->costb * -1;
	else
		cost += node->costb;
	return (cost);
}

t_stack	*find_smallest(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*smallest;

	temp = *stack;
	smallest = *stack;
	while (temp)
	{
		if (temp->index < smallest->index)
			smallest = temp;
		temp = temp->next;
	}
	return (smallest);
}

/*
the curr is first node of stack b!!!
。if the index of b is smaller than index of a(will become the first target)
。if there are no index of a is bigger than b it will choose the smallest in
a become the target
。if the the target is set but the next node of stack A is better it will choose
the next node of stack a become target.
*/
t_stack	*find_target(t_stack **a, int b_index)
{
	t_stack	*temp;
	t_stack	*target;

	temp = *a;
	target = NULL;
	while (temp)
	{
		if (target)
		{
			if (b_index < temp->index && target->index > temp->index)
				target = temp;
		}
		else if (b_index < temp->index)
			target = temp;
		temp = temp->next;
	}
	if (!target)
		target = find_smallest(a);
	return (target);
}

/*
will first find the target
that label cost of target to top of stack a
*/
void	calculate_cost(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	t_stack	*target;

	temp_b = *b;
	while (temp_b)
	{
		target = find_target(a, temp_b->index);
		if (target->pos > count_element(a) / 2)
			temp_b->costa = (count_element(a) - target->pos) * -1;
		else
			temp_b->costa = target->pos;
		if (temp_b->pos > (count_element(b) / 2))
			temp_b->costb = (count_element(b) - temp_b->pos) * -1;
		else
			temp_b->costb = temp_b->pos;
		temp_b = temp_b->next;
	}
}
