/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:15:37 by chtan             #+#    #+#             */
/*   Updated: 2024/07/09 14:00:18 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if ((*src) == NULL)
		return ;
	temp = (*src)->next;
	(*src)->next = (*dest);
	*dest = *src;
	*src = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	push (a, b);
	ft_putstr_fd("pa", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	push (b, a);
	ft_putstr_fd("pb", 1);
}
