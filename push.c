/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:46:57 by narrospi          #+#    #+#             */
/*   Updated: 2024/11/05 11:47:02 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_push;

	if (*src == NULL)
		return ;
	node_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node_push;
		node_push->next = NULL;
	}
	else
	{
		node_push->next = *dest;
		node_push->next->prev = node_push;
		*dest = node_push;
	}
}

void	push_end(t_stack **stack, int number)
{
	t_stack	*new_node;
	t_stack	*last;	

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = number;
	new_node->cheapest = false;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}	
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write (1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	write (1, "pb\n", 3);
}
