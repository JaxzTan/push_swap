/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:29:47 by chtan             #+#    #+#             */
/*   Updated: 2024/07/11 21:54:24 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*input;
	t_stack	*a;
	t_stack	*b;
	int		num;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		input = get_input(ac, av);
		if (!input)
			return (write(2, "error\n", 6));
		num = ac - 1;
		a = assign_stack_a(input, num); // error here because of a is pointer and return value of assiagn stack is duoble pointer
		b = NULL;
		assign_index(&a);
		if (!is_sorted(&a))
			return (0);
		sort(&a);
	}
}
