/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:51:27 by chtan             #+#    #+#             */
/*   Updated: 2024/07/12 14:23:30 by chtan            ###   ########.fr       */
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

void	error_message(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("error\n", 2);
}

int	count_word(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
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
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
