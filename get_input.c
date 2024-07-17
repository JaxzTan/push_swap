/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:19:33 by chtan             #+#    #+#             */
/*   Updated: 2024/07/17 10:29:07 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*turn_array_to_int(char **array)
{
	int		*num;
	long	numb;
	int		count;
	int		i;

	i = -1;
	count = count_word(array);
	num = (int *)malloc(sizeof(int) * count);
	if (!num)
		error_message("empty num while turn into int") ;
	while (++i < count)
	{
		numb = ft_atol(array[i]);
		if (numb > INT_MAX || numb < INT_MIN)
			error_message("not valid input");
		num[i] = (int) numb;
	}
	// ft_printf ("turn int success!\n");
	return (num);
}

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
				error_message("check dup");
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
		{
			error_message("not int");
			return (1);
		}
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '+' || av[i][j] == '-') &&
				(av[i][j] >= '0' && av[i][j] <= '9'))
				j++;
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
			{
				error_message("not int");
				return (1);
			}
		}
	}
	return (0);
}
int	check_digit(char **av)
{
	int	i;
	int	j;

	if (!av)
		return (1);
	i = -1;
	while (av[++i])
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (1);
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '-' || av[i][j] == '+')
				&& ft_isdigit(av[i][j + 1]))
				j++;
			while (ft_isdigit(av[i][j]))
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
		if (!check_dup(numbers) && !check_digit(numbers))
		{
			// ft_printf ("input1 settle\n");
			return (numbers);
		}
	}
	if (ac > 2 && av[1][0] != '\0')
	{
		if (!check_dup (av + 1) && !check_num (ac - 1, av + 1))
		{
			// ft_printf ("input2 settle\n");
			return (av + 1);
		}
	}
	return (0);
}
