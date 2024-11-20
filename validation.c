/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:46:29 by narrospi          #+#    #+#             */
/*   Updated: 2024/11/05 11:46:31 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	check_parameters(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (av[i][ft_strlen(av[i] - 1)] == 32 || av[i][0] == 32)
			exit_error();
		j = 0;
		while (j < ft_strlen(av[i]))
		{
			if ((av[i][j] < 48 || av[i][j] > 57) && av[i][j] != 32)
			{
				if (av[i][j] != 45 && av[i][j] != 43)
					exit_error();
			}
			if (av[i][j] == 32 && av[i][j + 1] == 32)
				exit_error();
			j++;
		}
		i++;
	}
}

void	parse_numbers(t_stack **a, char **numbers, int index)
{
	long	value;

	while (numbers[index])
	{
		value = ft_atol(numbers[index]);
		if (value > 2147483647 || value < -2147483648)
			exit_error();
		push_end(a, (int)value);
		index++;
	}
}

void	get_numbers(int ac, char **av, t_stack **a)
{
	char	**numbers;

	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		parse_numbers(a, numbers, 0);
		free_numbers(numbers);
	}
	else
		parse_numbers(a, av, 1);
}

int	check_duplicates(t_stack **a)
{
	t_stack	*current;
	t_stack	*runner;

	current = *a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				exit_error();
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}
