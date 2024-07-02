/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:01:54 by chtan             #+#    #+#             */
/*   Updated: 2024/07/01 17:11:54 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_node(t_stack **stack, int nb)
{
	t_stack	*node;
	t_stack	*cur;

	if (!*stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->val = nb;
	cur = *stack;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = node;
}

int	assign_stack_a(t_stack **a, t_stack **input, int ac)
{
	int	nb;
	int	i;

	i = 0;
	while (input[i])
	{
		nb = ft_atoi(input[i++]);
		assign_node(a, nb);
	}
	return (i);
}
