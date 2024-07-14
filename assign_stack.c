/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:01:54 by chtan             #+#    #+#             */
/*   Updated: 2024/07/14 11:51:16 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf ("assign stack a success!\n");
}

int	*turn_array_to_int(char **array)
{
	int		*num;
	long	numb;
	int		count;
	int		i;

	i = -1;
	count = count_word(array);
	num = (int *)malloc(sizeof(int) * count);
	if (!num)
		error_message("empty num while turn into int") ;
	while (++i < count)
	{
		numb = ft_atol(array[i]);
		if (numb > INT_MAX || numb < INT_MIN)
			error_message("turnarraytoint");
		num[i] = (int) numb;
	}
	ft_printf ("turn int success!\n");
	return (num);
}
