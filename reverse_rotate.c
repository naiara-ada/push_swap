/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:14:07 by narrospi          #+#    #+#             */
/*   Updated: 2024/11/06 12:14:10 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack *before_last;
	int		len;

	len = ft_lstsize(stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = find_last_node(*stack);
	before_last = last->prev;
	if (before_last)
		before_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	if (last->next)
		last->next->prev = last;	
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
	{
		rrr(a, b);
	}
	set_current_position(*a);
	set_current_position(*b);
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
