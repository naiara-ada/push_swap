/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:48:24 by narrospi          #+#    #+#             */
/*   Updated: 2024/11/05 11:48:27 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > third && third > second)
		ra(a);
	else if (second > first && first > third)
		rra(a);
	else if (second > third && third > first)
	{
		sa(a);
		ra(a);
	}
	else if (third > first && first > second)
		sa (a);
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	a_size;

	a_size = ft_lstsize(a);
	if (a_size == 2)
		sa(a);
	else if (a_size == 3)
		sort_three(a);
	else if (a_size == 4)
		sort_four(a, b);
	else if (a_size == 5)
		sort_five(a, b);
	else if (a_size > 5)
		sort_big(a, b);
}
