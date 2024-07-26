/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:05:49 by chtan             #+#    #+#             */
/*   Updated: 2024/07/26 10:25:37 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
。find the chepeat node to push to a
。cur = first of stack b
。cheapest node = result
。fist set the chepest with cur
。loop through the stack b
if there are cost of node cheaper than the cur, target will change to the node
*/
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
			if (total_cost(cheapest_node) > total_cost(current))
				cheapest_node = current;
		}
		else
			cheapest_node = current;
		current = current->next;
	}
	return (cheapest_node);
}

/*
。if both cost is smaller than 0 will reverse rotate both stack
。if both cost is bigger than 0 will rotate both stack
*/
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

/*
。find node that cheapest
。Rotate both stacks to align node_to_push optimally
。adjust node with rra or ra
。rotate b or reverse rotate b when cost smaller than 0
。if there are cost a and cost b will push to a
*/
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

/*pre sort
。mid = half of totol node
。len_to_push = total node need to push and remain 3 to sort 3
for the push to b part
。will first push the smaller numbers until half of the node
has been push to b
。for the rest will push to b with no contitions
*/
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