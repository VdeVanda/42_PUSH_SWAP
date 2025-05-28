/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:55:25 by vabatist          #+#    #+#             */
/*   Updated: 2025/05/24 16:00:25 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the stack is sorted.
 * It iterates through the stack
 * and compares each node's data with the next node's data.
 * If any node's data is greater than the next node's data,
 * it returns false.
 * If the stack is empty or has only one node,
 * it returns true.
 * The function does not modify the stack.
 * It assumes that the stack is not NULL.
 * If the stack is NULL,
 * it returns true.
 * The function does not return any value.
 */
bool	is_sorted(t_node *stack)
{
	if (!stack || !stack->next)
		return (true);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/**
 * Sorts three elements in stack A.
 * It finds the biggest number in the stack
 * and rotates the stack accordingly.
 * If the biggest number is already on top,
 * it rotates the stack to the right.
 * If the biggest number is in the middle,
 * it rotates the stack to the left.
 * Finally, it swaps the first two elements
 * if they are not in order.
 */
void	sort_three(t_node **stack_a)
{
	t_node	*biggest_number;

	biggest_number = find_max(*stack_a);
	if (biggest_number == *stack_a)
		ra(stack_a, true);
	else if (biggest_number == (*stack_a)->next)
		rra(stack_a, true);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, true);
}

/**
 * Moves the cheapest node from stack A to stack B.
 * It first finds the cheapest node in stack A
 * and its target node in stack B.
 * It then determines the best way to move
 * the cheapest node to the top of stack A
 * and the target node to the top of stack B.
 * Finally, it pushes the cheapest node
 * from stack A to stack B.
 */
static void	move_b_to_a(t_node **stack_a, t_node **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b, true);
}

/**
 * Moves the minimum node to the top of stack A.
 * It finds the minimum node in stack A
 * and rotates the stack accordingly.
 * If the minimum node is above the median,
 * it rotates the stack in the forward direction.
 * If the minimum node is below the median,
 * it rotates the stack in the reverse direction.
 */
static void	min_on_top(t_node **stack_a)
{
	t_node	*min_node;

	min_node = find_min(*stack_a);
	while ((*stack_a)->data != min_node->data)
	{
		if (min_node->above_median)
			ra(stack_a, true);
		else
			rra(stack_a, true);
		min_node = find_min(*stack_a);
	}
}

/**
 * Sorts the stacks using the push_swap algorithm.
 * It first checks if stack A is sorted.
 * If stack A has more than 3 elements,
 * it pushes the top element to stack B.
 * It then sorts the remaining elements in stack A.
 * Finally, it moves the elements from stack B back to stack A.
 */
void	sort_stacks(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = stacklen(*stack_a);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b, true);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b, true);
	while (len_a-- > 3 && !is_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}
