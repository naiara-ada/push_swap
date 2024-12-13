/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:08:55 by narrospi          #+#    #+#             */
/*   Updated: 2024/11/05 12:08:57 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_lstsize(t_stack **stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	if (*stack == NULL)
		return (0);
	current = *stack;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

t_stack	*find_last_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min_index;
	int	len;

	len = ft_lstsize(a);
	min_index = find_min_index(a);
	while (min_index > 0)
	{
		if (min_index <= len / 2)
			ra(a);
		else
			rra(a);
		min_index = find_min_index(a);
	}
	pb(b, a);
}
