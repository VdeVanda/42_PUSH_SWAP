/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:51:37 by vabatist          #+#    #+#             */
/*   Updated: 2025/05/17 12:19:11 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Finds the cheapest node in the stack.
 * It iterates through the stack
 * until it finds the node with the lowest push cost.
 * It sets the cheapest property of that node to true.
 * If the stack is empty, the function does nothing.
 * The function assumes that the push_cost property of each node
 * has already been set.
 */
t_node	*get_chepeast(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/**
 * determines the best way to move the cheapest node
 * to the top of the stack.
 * It rotates the stack in the direction that minimizes the number of moves.
 * If the cheapest node is above the median,
 * it rotates the stack in the forward direction.
 * If the cheapest node is below the median,
 * it rotates the stack in the reverse direction.
 * It also rotates the target node
 * to the top of the stack in the same way.
 */
void	prep_for_push(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

/**
 * Moves the cheapest node from stack_a to stack_b.
 * It first finds the cheapest node in stack_a
 * and its target node in stack_b.
 * It then determines the best way to move
 * the cheapest node to the top of stack_a
 * and the target node to the top of stack_b.
 * Finally, it pushes the cheapest node
 * from stack_a to stack_b.
 * It also updates the above_median property
 * of the nodes in stack_b.
 */
void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*chepeast_node;

	chepeast_node = get_chepeast(*stack_a);
	if (chepeast_node->above_median && chepeast_node->target_node->above_median)
		rotate_both(stack_a, stack_b, chepeast_node);
	else if (!(chepeast_node->above_median)
		&& !(chepeast_node->target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, chepeast_node);
	prep_for_push(stack_a, chepeast_node, 'a');
	prep_for_push(stack_b, chepeast_node->target_node, 'b');
	pb(stack_a, stack_b, true);
}

/**
 * Sets the target node for each node in stack_b.
 * It iterates through stack_b
 * and for each node,
 * it finds the node in stack_a
 * that is the closest to it
 * but greater than it.
 * If no such node is found,
 * it sets the target node to the minimum node in stack_a.
 * It also sets the target_node property of each node in stack_b.
 * The function assumes that the target_node property of each node in stack_a
 * has already been set.
 */
static void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_a;
	t_node	*target_node;
	int		best_match_index;

	while (stack_b)
	{
		best_match_index = INT_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->data > stack_b->data
				&& current_a->data < best_match_index)
			{
				best_match_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

/**
 * Initializes the nodes in stack_a and stack_b.
 * It sets the index and above_median properties
 * for each node in both stacks.
 * It also sets the target_node property
 * for each node in stack_b
 * to the node in stack_a
 * that is the closest to it
 * but greater than it.
 * It also sets the push_cost property
 * for each node in stack_a
 * to the number of moves required
 * to push the node to stack_b.
 * The function assumes that the stacks are not empty.
 */
void	init_nodes_b(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
