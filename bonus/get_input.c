/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:10:20 by chtan             #+#    #+#             */
/*   Updated: 2024/07/25 11:22:10 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	**arg_to_str(char **av)
{
	int		i;
	char	**str_arr;
	char	*container;

	i = 1;
	container = NULL;
	while (av[i])
	{
		if (!av[i][0])
		{
			free(container);
			error_message();
		}
		container = ft_strjoin(container, av[i++]);
		container = ft_strjoin(container, " ");
	}
	str_arr = ft_split(container, ' ');
	free(container);
	return (str_arr);
}

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
		error_message();
	while (++i < count)
	{
		numb = ft_atol(array[i]);
		if (numb > INT_MAX || numb < INT_MIN)
			error_message();
		num[i] = (int) numb;
	}
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
				error_message();
				return (1);
			}
			j++;
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
			error_message();
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '-' || av[i][j] == '+')
				&& ft_isdigit(av[i][j + 1]))
				j++;
			while (ft_isdigit(av[i][j]))
				j++;
			if (av[i][j] != '\0')
				error_message();
		}
	}
	return (0);
}

char	**get_input(int ac, char **av)
{
	char	**numbers;

	numbers = arg_to_str(av);
	if (ac >= 2 && av[1][0] != '\0')
	{
		if (!check_dup(numbers) && !check_digit(numbers))
			return (numbers);
	}
	return (0);
}
