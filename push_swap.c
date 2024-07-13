/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:29:47 by chtan             #+#    #+#             */
/*   Updated: 2024/07/13 17:24:27 by chtan            ###   ########.fr       */
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
		num = ac - 1;
		input = turn_array_to_int(temp);
		a = assign_stack_a(input, num);
		b = NULL;
		assign_index(&a);
		if (!is_sorted(&a))
			return(write (1, "\n", 1));
		else
			sort(&a);
	}
	return (0);
}
