/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:03:46 by chtan             #+#    #+#             */
/*   Updated: 2024/07/24 17:45:13 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	label_index(t_stack **stack, int *array)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->val == array[i])
		{
			temp->index = i;
			temp = temp->next;
			i = 0;
		}
		else
			i++;
	}
}

int	get_lstsize(t_stack **stack)
{
	t_stack	*cur;
	int		count;

	count = 0;
	cur = *stack;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

void	bubble_sort(int *stack, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		if (stack[i] > stack[i + 1])
		{
			temp = stack[i];
			stack[i] = stack[i + 1];
			stack[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	assign_index(t_stack **stack)
{
	int		*array;
	int		size;
	int		i;
	t_stack	*temp;

	size = get_lstsize(stack);
	array = malloc(sizeof(int) * size);
	temp = *stack;
	i = -1;
	while (++i < size)
	{
		array[i] = temp->val;
		temp = temp->next;
	}
	bubble_sort(array, size);
	label_index(stack, array);
	free(array);
}
