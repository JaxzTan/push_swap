/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:57:46 by chtan             #+#    #+#             */
/*   Updated: 2024/07/25 18:19:41 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// if valid operations will do operations without priting steps
int	do_both(t_stack **a, t_stack **b, char *ins)
{
	if (ft_strcmp(ins, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(ins, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(ins, "ss\n") == 0)
		ss(a, b);
	else
		return (0);
	return (1);
}

static void	check_and_do_ins(t_stack **a, t_stack **b, char *ins)
{
	if (ft_strcmp(ins, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(ins, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(ins, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(ins, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(ins, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(ins, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(ins, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(ins, "rrb\n") == 0)
		rrb(b);
	else if (do_both(a, b, ins))
		return ;
	else
		error_message();
}

/*
。while there are steps(operations) will store steps with gnl(0)(as a std input)
and check those operations
。the main point is is sorted
*/
void	checker(t_stack **a, t_stack **b)
{
	char	*steps;

	steps = malloc(sizeof(char));
	while (steps)
	{
		free(steps);
		steps = get_next_line(0);
		if (steps)
			check_and_do_ins(a, b, steps);
	}
	if (is_sorted(a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		*input;
	char	**temp;
	t_stack	*a;
	t_stack	*b;
	int		int_num;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		temp = get_input(ac, av);
		int_num = count_word(temp);
		if (int_num == 1)
			exit (0);
		input = turn_array_to_int(temp);
		a = assign_stack_a(input, int_num);
		b = NULL;
		checker(&a, &b);
		free(input);
	}
	return (0);
}
