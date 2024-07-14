/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:19:33 by chtan             #+#    #+#             */
/*   Updated: 2024/07/14 16:02:13 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(char **av)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				// error_message("check dup");
				return (1);
			}
			j++;
		}
	}
	return (0);
}

int	check_num(int ac, char **av)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			return (1);
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-' ||
				ft_isdigit(av[i][j + 1]))
				j++;
			while (ft_isdigit(av[1][j]))
				j++;
			if (av[i][j] != '\0')
				return (1);
		}
	}
	return (0);
}

char	**get_input(int ac, char **av)
{
	char	**numbers;

	if (ac == 2 && av[1][0] != '\0')
	{
		numbers = ft_split(av[1], ' ');
		ac = count_word(numbers);
		if (!check_dup(numbers) && check_num(ac - 1, av))
		{
			ft_printf ("input1 settle\n");
			return (numbers);
		}
	}
	if (ac > 2 && av[1][0] != '\0')
	{
		ac = count_word(numbers);
		if (!check_dup (av + 1) && !check_num (ac - 1, av + 1))
		{
			ft_printf ("input2 settle\n");
			return (av + 1);
		}
	}
	return (0);
}

// #include <stdio.h>
// #include <limits.h> // for INT_MAX and INT_MIN
// #include "push_swap.h" // Assuming this header includes necessary declarations

// int main(int ac, char **av) {
//     char **numbers = get_input(ac, av);

//     if (numbers) {
//         printf("Input numbers:\n");
//         for (int i = 0; numbers[i] != NULL; i++) {
//             printf("%s\n", numbers[i]);
//         }
//     } else {
//         printf("Invalid input or duplicates found.\n");
//     }

//     // Free allocated memory for numbers if necessary
//     // Example: Assuming ft_split allocates memory that needs to be freed
//     // for (int i = 0; numbers[i] != NULL; i++) {
//     //     free(numbers[i]);
//     // }
//     // free(numbers);

//     return 0;
// }