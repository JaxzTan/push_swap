/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:51:27 by chtan             #+#    #+#             */
/*   Updated: 2024/07/17 14:54:31 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->val > temp->next->val)
		{
			// ft_printf ("not sorted\n");
			return (1);
		}
		temp = temp->next;
	}
	// ft_printf("sorted!\n");
	return (0);
}

void	error_message(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("error\n", 2);
}

int	count_word(char **array)
{
	int	count;

	count = 0;
	while (array[count] != NULL)
		count++;
	// ft_printf("%d", count);
	return (count);
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void printLinkedList(t_stack **head)
{
    t_stack *current = *head; // Start from the head of the list

    // Traverse the list and print each element
    while (current != NULL) {
        ft_printf("Value: %d, Index: %d\n", current->val, current->index);
        current = current->next; // Move to the next node
    }
}
