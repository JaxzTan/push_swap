/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:29:47 by chtan             #+#    #+#             */
/*   Updated: 2024/07/01 17:12:31 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**input;
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		input = get_input(ac, av);
		if (!input)
			return (write(2, "error\n", 6));
		size = assign_stack_a(&a, input, ac);
	}
}
