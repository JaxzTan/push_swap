/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:29:47 by chtan             #+#    #+#             */
/*   Updated: 2024/07/15 16:00:32 by chtan            ###   ########.fr       */
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
		if (num == 1)
			return (0);
		input = turn_array_to_int(temp);
		a = assign_stack_a(input, num);
		b = NULL;
		assign_index(&a);
		if (!is_sorted(&a))
			return (0);
			// ft_putstr_fd("is sorted\n", 1);
		else if (num == 2)
			sa(&a);
		else
			sort(&a, &b, num);
		printLinkedList(&a);
	}
	return (0);
}
