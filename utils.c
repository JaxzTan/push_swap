/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:51:27 by chtan             #+#    #+#             */
/*   Updated: 2024/07/09 11:36:57 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **a)
{
	int		count;
	t_stack	*temp;

	temp = *a;
	while (temp->next)
	{
		count = temp->val;
		temp = temp->next;
		if (count > temp->val)
			return (0);
	}
	return (1);
}
