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

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

//utils
int				ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
int				ft_lstsize(t_stack_node **stack);
t_stack_node	*find_last_node(t_stack_node *stack);
long			ft_atol(const char *str);
int				find_min_index(t_stack_node **a);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_cheapest(t_stack_node *stack);
void			push_min_to_b(t_stack_node **a, t_stack_node **b);

//validation
void			check_parameters(char **av);
void			get_numbers(int ac, char **av, t_stack_node **a);
int				is_sorted(t_stack_node **stack);
void			parse_numbers(t_stack_node **a, char **numbers, int index);
int				check_duplicates(t_stack_node **a);

//error
void			exit_error(void);
void			free_stack(t_stack_node **stack);
void			free_numbers(char **numbers);

//sort
void			sort_three(t_stack_node **a);
void			sort_four(t_stack_node **a, t_stack_node **b);
void			sort_five(t_stack_node **a, t_stack_node **b);
void			sort_big(t_stack_node **a, t_stack_node **b);
void			sort_stack(t_stack_node **a, t_stack_node **b);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			set_current_position(t_stack_node *stack);
void			set_target_node(t_stack_node *a, t_stack_node *b);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			moves_nodes(t_stack_node **a, t_stack_node **b);
void			finish_rotation(t_stack_node **stack,
					t_stack_node *top_node, char name);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);

//comands
void			push_end(t_stack_node **stack, int value);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif
