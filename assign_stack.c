/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:01:54 by chtan             #+#    #+#             */
/*   Updated: 2024/07/11 21:54:42 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack	**assign_node(t_stack **stack, int nb)
// {
// 	t_stack	**node;
// 	t_stack	*cur;

// 	if (!*stack)
// 		return (NULL);
// 	node = malloc(sizeof(t_stack));
// 	if (!node)
// 		return ;
// 	(*node)->next = NULL;
// 	(*node)->val = nb;
// 	cur = *stack;
// 	while (cur->next != NULL)
// 		cur = cur->next;
// 	cur->next = node;
// 	return (node);
// }

// t_stack	**assign_stack_a(t_stack **a, t_stack **input)
// {
// 	int		nb;
// 	int		i;
// 	t_stack	**stack;

// 	i = 0;
// 	while (input[i])
// 	{
// 		nb = ft_atoi(input[i]);
// 		stack = assign_node(a, nb);
// 		i++;
// 	}
// 	return (stack);
// }

// void assign_node(t_stack **stack, int nb)
// {
// 	t_stack *node = malloc(sizeof(t_stack));
// 	if (!node)
// 		return NULL;

// 	node->next = NULL;
// 	node->val = nb;

// 	if (!*stack)
// 		*stack = node;
// 	else
// 	{
// 		t_stack *cur = *stack;
// 		while (cur->next)
// 			cur = cur->next;
// 		cur->next = node;
// 	}
// 	// return node;
// }

// t_stack *assign_stack_a(t_stack **a, char **input, int ac)
// {
// 	int i = 0;
// 	t_stack *stack = NULL;

// 	while (input[i])
// 	{
// 		int nb = ft_atoi(input[i]);
// 		assign_node(&stack, nb);
// 		i++;
// 	}
// 	*a = stack;
// 	return stack;
// }

t_stack	*assign_stack_a(int *str, int num)
{
	t_stack	*a;
	t_stack	*temp;
	int		i;

	i = -1;
	a = malloc (sizeof(t_stack));
	if (!str)
		return (NULL);
	temp = a;
	while (++i < num)
	{
		temp->val = str[i];
		if (i + 1 < num)
		{
			temp->val = str[i];
			temp = temp->next;
		}
		else
			temp->next = NULL;
	}
	return (a);
}
