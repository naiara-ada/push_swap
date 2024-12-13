/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:48:38 by narrospi          #+#    #+#             */
/*   Updated: 2024/11/05 11:48:41 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_current_position(t_stack *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return ;
	center = ft_lstsize(&stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= center)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
		++i;
	}
}

void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	leng_b;

	len_a = ft_lstsize(&a);
	leng_b = ft_lstsize(&b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->median))
			b->push_price = leng_b - (b->current_position);
		if (b->target_node->median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

void	sort_big(t_stack **a, t_stack **b)
{
	t_stack	*smallest_node;
	int		len_a;

	len_a = ft_lstsize(a);
	while (len_a > 3)
	{
		pb(b, a);
		len_a--;
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		moves_nodes(a, b);
	}
	set_current_position(*a);
	smallest_node = find_smallest(*a);
	if (smallest_node->median)
		while (*a != smallest_node)
			ra(a);
	else
		while (*a != smallest_node)
			rra(a);
}
