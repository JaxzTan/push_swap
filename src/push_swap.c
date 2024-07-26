/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:29:47 by chtan             #+#    #+#             */
/*   Updated: 2024/07/26 10:37:29 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b, int num)
{
	if (is_sorted(a))
		exit(0);
	else if (num == 2)
		sa(a);
	else if (num == 3)
		sort_3(a);
	else if (num <= 5)
		sort_5(a, b);
	else
		sort_big(a, b);
}

/*
@brief find the smallest node in stack a and push it to the top using ra or rra
*/
void	order_stack_a(t_stack **stk_a)
{
	t_stack	*current;
	int		times_to_rotate;

	label_possition(stk_a);
	current = *stk_a;
	while (current)
	{
		if (current->index == 0)
			break ;
		current = current->next;
	}
	if (current->pos > (count_element(stk_a) / 2))
	{
		times_to_rotate = (count_element(stk_a) - current->pos);
		while (times_to_rotate--)
			rra(stk_a);
	}
	else
	{
		times_to_rotate = current->pos;
		while (times_to_rotate--)
			ra(stk_a);
	}
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
		assign_index(&a);
		sort(&a, &b, int_num);
		order_stack_a(&a);
		free(input);
	}
	return (0);
}

// void printLinkedList(t_stack **head)
// {
//     t_stack *current = *head; // Start from the head of the list

//     // Traverse the list and print each element
//     while (current) {
//         ft_printf("Value: %d, Index: %d\n", current->val, current->index);
//         current = current->next; // Move to the next node
//     }
// }
