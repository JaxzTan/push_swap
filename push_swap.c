/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:29:47 by chtan             #+#    #+#             */
/*   Updated: 2024/07/14 16:30:23 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*input;
	char	**temp;
	t_stack	*a;
	t_stack	*b;
	int		num;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		temp = get_input(ac, av);
		if (!temp)
			error_message("main");
		num = count_word(temp);
		if (num == 1){
			ft_putstr_fd("num only 1", 1);
			return (0);
		}
		input = turn_array_to_int(temp);
		a = assign_stack_a(input, num);
		b = NULL;
		assign_index(&a);
		if (is_sorted(&a))
			ft_putstr_fd("is sorted", 1);
		else
			sort(&a);
		printLinkedList(&a);
	}
	return (0);
}
