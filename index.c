/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:03:46 by chtan             #+#    #+#             */
/*   Updated: 2024/07/13 10:30:24 by chtan            ###   ########.fr       */
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
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (stack[j] > stack[j + 1])
			{
				temp = stack[j];
				stack[j] = stack[j + 1];
				stack[j + 1] = temp;
			}
			j++;
		}
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
	array = (int *) malloc (sizeof(int) * size);
	if (!array || !(*array))
		return ;
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
	ft_printf("index set successful!\n");
}
