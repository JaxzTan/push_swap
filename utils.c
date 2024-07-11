/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:51:27 by chtan             #+#    #+#             */
/*   Updated: 2024/07/11 21:20:26 by chtan            ###   ########.fr       */
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

void	error_message(void)
{
	ft_putstr_fd("error\n", 2);
}

// int	count_word(char *str)
// {
// 	int	count;
// 	int	i;

// 	i = -1;
// 	count = 0;
// 	while (str[++i] != '\0')
// 	{
// 		if (str[i] == 32)
// 			count++;
// 	}
// 	return (count);
// }
