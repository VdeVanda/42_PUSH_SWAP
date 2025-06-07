/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:52:54 by vabatist          #+#    #+#             */
/*   Updated: 2025/06/04 16:46:33 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// Main functions
void				write_error(void);

// Find stuff
t_node				*find_min(t_node *stack);
t_node				*find_max(t_node *stack);
int					ft_safe_atoi(t_node *head, char **all_str, char *str);

// List functions
int					add_to_list(t_node **head, int value);
void				deletlist(t_node *head);
int					stacklen(t_node *head);
void				free_double_array(char *array[]);

// Sort
bool				is_sorted(t_node *stack);
void				sort_three(t_node **stack_a);
void				sort_stacks(t_node **stack_a, t_node **stack_b);

// Preparing for push
void				current_index(t_node *stack);
void				set_cheapest(t_node *stack);
void				init_nodes_a(t_node *stack_a, t_node *stack_b);

// Move nodes
void				rotate_both(t_node **stack_a, t_node **stack_b,
						t_node *cheapest_node);
void				reverse_rotate_both(t_node **stack_a, t_node **stack_b,
						t_node *cheapest_node);
void				move_a_to_b(t_node **stack_a, t_node **stack_b);
void				init_nodes_b(t_node *stack_a, t_node *stack_b);
void				prep_for_push(t_node **stack, t_node *top_node,
						char stack_name);
void				argv_convert_builder(int argc, char *argv[], t_node **head);

// Move Swap Functions
void				sa(t_node **head, bool print);
void				sb(t_node **head, bool print);
void				ss(t_node **headA, t_node **headB, bool print);

// Move Push Functions
void				pa(t_node **headA, t_node **headB, bool print);
void				pb(t_node **headA, t_node **headB, bool print);

// Move Rotate Functions
void				ra(t_node **head, bool print);
void				rb(t_node **head, bool print);
void				rr(t_node **headA, t_node **headB, bool print);

// Move Reverse Rotate Functions
void				rra(t_node **head, bool print);
void				rrb(t_node **head, bool print);
void				rrr(t_node **headA, t_node **headB, bool print);

#endif
