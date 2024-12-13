/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:48:00 by narrospi          #+#    #+#             */
/*   Updated: 2024/11/05 11:48:02 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	int		len;
	t_stack	*first;
	t_stack	*second;

	len = ft_lstsize(stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
