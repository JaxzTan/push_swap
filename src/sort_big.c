/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:05:49 by chtan             #+#    #+#             */
/*   Updated: 2024/07/24 18:03:42 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*cheapest(t_stack **stack)
{
	t_stack	*current;
	t_stack	*cheapest_node;

	current = *stack;
	cheapest_node = NULL;
	while (current)
	{
		if (cheapest_node)
		{
			if (cost(cheapest_node) > cost(current))
				cheapest_node = current;
		}
		else
			cheapest_node = current;
		current = current->next;
	}
	return (cheapest_node);
}

void	rotate_both(t_stack *node_to_push, t_stack **a, t_stack **b)
{
	if (node_to_push->costa < 0 && node_to_push->costb < 0)
	{
		while (node_to_push->costa < 0 && node_to_push->costb < 0)
		{
			rrr(a, b);
			node_to_push->costa++;
			node_to_push->costb++;
		}
	}
	else if (node_to_push->costa > 0 && node_to_push->costb > 0)
	{
		while (node_to_push->costa && node_to_push->costb)
		{
			rr(a, b);
			node_to_push->costa--;
			node_to_push->costb--;
		}
	}
}

void	push_node(t_stack **a, t_stack **b)
{
	t_stack	*node_to_push;

	node_to_push = cheapest(b);
	rotate_both(node_to_push, a, b);
	if (node_to_push->costa < 0)
		while (node_to_push->costa++ < 0)
			rra(a);
	else
		while (node_to_push->costa-- > 0)
			ra(a);
	if (node_to_push->costb < 0)
		while (node_to_push->costb++ < 0)
			rrb(b);
	else
		while (node_to_push->costb-- > 0)
			rb(b);
	pa(a, b);
}

//pre sort
void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		len_to_push;
	int		mid;
	int		num;

	len_to_push = count_element(a) - 3;
	mid = count_element(a) / 2;
	num = 0;
	while (num < len_to_push / 2)
	{
		temp = *a;
		if (temp->index < mid)
		{
			pb(a, b);
			num++;
		}
		else
			ra(a);
	}
	while (num++ < len_to_push)
		pb(a, b);
}

void	sort_big(t_stack **a, t_stack **b)
{
	int	to_a;

	push_to_b(a, b);
	sort_3(a);
	to_a = count_element(b);
	while (to_a--)
	{
		label_possition(a);
		label_possition(b);
		calculate_cost(a, b);
		push_node(a, b);
	}
}

/*
push to b(pre sort part for turk sort)
{will first searching for the numbers smaller than the median
(let stack B become in descending order)}
*/