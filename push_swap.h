/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:45:39 by narrospi          #+#    #+#             */
/*   Updated: 2024/11/05 11:45:42 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

# define LONG_MAX 2147483647
# define LONG_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				current_position;
	int				push_price;
	bool			median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

//utils
int		ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int		ft_lstsize(t_stack **stack);
t_stack	*find_last_node(t_stack *stack);
long	ft_atol(const char *str);
int		find_min_index(t_stack **a);
t_stack	*find_smallest(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
void	push_min_to_b(t_stack **a, t_stack **b);

//validation
void	check_parameters(char **av);
void	get_numbers(int ac, char **av, t_stack **a);
int		is_sorted(t_stack **stack);
void	parse_numbers(t_stack **a, char **numbers, int index);
int		check_duplicates(t_stack **a);

//error
void	exit_error(void);
void	free_stack(t_stack **stack);
void	free_numbers(char **numbers);

//sort
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_big(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	set_current_position(t_stack *stack);
void	set_target_node(t_stack *a, t_stack *b);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);
void	moves_nodes(t_stack **a, t_stack **b);
void	finish_rotation(t_stack **stack, t_stack *top_node, char name);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

//comands
void	push_end(t_stack **stack, int value);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
