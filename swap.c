/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:08:54 by chtan             #+#    #+#             */
/*   Updated: 2024/07/01 17:35:53 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **a)
{
	t_stack	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
}

void sb(t_stack **b)
{
	t_stack	*temp;

	if (!*b || !(*b)->next)
		return ;
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}