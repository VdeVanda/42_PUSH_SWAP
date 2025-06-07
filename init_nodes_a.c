/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:49:46 by vabatist          #+#    #+#             */
/*   Updated: 2025/06/04 16:57:08 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sets the index and above_median properties for each node in the stack.
 * The index is set to the position of the node in the stack.
 * The above_median property
 * is set to true if the node's index is less than or equal to the median
 * of the stack length,
 * and false otherwise.
 * The median is calculated as the length of the stack divided by 2.
 * The function iterates through the stack and updates each node's properties
 * accordingly.
 * If the stack is empty, the function does nothing.
 */
void	current_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stacklen(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

/**
* Sets the target node in stack_b for each node in stack_a.
 * For each element in stack_a, this function identifies the optimal
 * placement position in stack_b:
 * 1. It looks for the largest element in stack_b that is smaller than
 *    the current stack_a element (finds the correct sorted position)
 * 2. If no smaller element exists in stack_b (when best_match_index
 *    remains INT_MIN), it targets the maximum value in stack_b instead
 * This targeting strategy ensures elements are inserted in the most
 * efficient position to maintain sorting order in stack_b, minimizing
 * the number of operations needed.
*/
static void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_b;
	t_node	*target_node;
	long	best_match_index;

	while (stack_a)
	{
		best_match_index = INT_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->data < stack_a->data
				&& current_b->data > best_match_index)
			{
				best_match_index = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == INT_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

/**
 * Calculates the push cost for each node in stack_a.
 * The push cost is the number of moves required to push the node
 * to stack_b.
 * The push cost is calculated based on the index of the node in stack_a,
 * the index of the target node in stack_b,
 * and whether the node is above or below the median.
 * If the node is above the median, the push cost is equal to its index.
 * If the node is below the median,
 * the push cost is equal to the length of stack_a minus its index.
 * The push cost is then adjusted based on the target node's index
 * in stack_b.
 * If the target node is above the median, the push cost is added to its index.
 * If the target node is below the median,
 * the push cost is added to the length of stack_b minus its index.
 * The function iterates through stack_a and updates each node's push cost
 * accordingly.
 * If either stack_a or stack_b is empty, the function does nothing.
 * The function assumes that the target_node property of each node in stack_a
 * has already been set to the appropriate target node in stack_b.
 * The function does not return any value.
 * It modifies the push_cost property of each node in stack_a.
 */

static void	cost_analysis_a(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stacklen(stack_a);
	len_b = stacklen(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - stack_a->target_node->index;
		stack_a = stack_a->next;
	}
}

/**
 * Sets the cheapest node in the stack.
 * The cheapest node is the one with the lowest push cost.
 * The function iterates through the stack
 * and finds the node with the lowest push cost.
 * It sets the cheapest property of that node to true.
 * If the stack is empty, the function does nothing.
 * The function assumes that the push_cost property of each node
 * has already been set.
 * The function modifies the cheapest property of the node.
 */
void	set_cheapest(t_node *stack)
{
	int		cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

/**
 * Initializes the nodes in stack_a and stack_b.
 * It sets the index and above_median properties
 * for each node in both stacks.
 * It also sets the target_node property
 * for each node in stack_a
 * to the appropriate target node in stack_b.
 * It calculates the push cost for each node in stack_a
 * based on the target node.
 * It sets the cheapest node in stack_a
 * based on the push cost.
 * The function does not return any value.
 * It modifies the properties of the nodes in both stacks.
 */
void	init_nodes_a(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
