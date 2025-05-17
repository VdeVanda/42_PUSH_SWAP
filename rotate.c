/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:53:49 by vabatist          #+#    #+#             */
/*   Updated: 2025/05/17 12:28:00 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Rotates the stack in the forward direction.
 * It moves the first element to the end of the stack.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If the stack is empty or has only one element,
 * the function does nothing.
 * The function does not return any value.
 * It modifies the head pointer of the stack.
 */
static void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !(*head) || !((*head)->next))
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

/**
 * Rotates stack A in the forward direction.
 * It moves the first element to the end of stack A.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If the stack is empty or has only one element,
 * the function does nothing.
 * The function prints "ra" if the print parameter is true.
 * It returns nothing.
 */
void	ra(t_node **head, bool print)
{
	rotate(head);
	if (print == true)
		ft_printf("ra\n");
}

/**
 * Rotates stack B in the forward direction.
 * It moves the first element to the end of stack B.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If the stack is empty or has only one element,
 * the function does nothing.
 * The function prints "rb" if the print parameter is true.
 * It returns nothing.
 */
void	rb(t_node **head, bool print)
{
	rotate(head);
	if (print == true)
		ft_printf("rb\n");
}

/**
 * Rotates both stacks A and B in the forward direction.
 * It moves the first element of each stack to the end of the respective stack.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If either stack is empty or has only one element,
 * the function does nothing.
 * The function prints "rr" if the print parameter is true.
 * It returns nothing.
 */
void	rr(t_node **headA, t_node **headB, bool print)
{
	rotate(headA);
	rotate(headB);
	if (print == true)
		ft_printf("rr\n");
}

/**
 * Rotates both stacks A and B in the forward direction
 * until the cheapest node is at the top of stack B.
 * It updates the current index of both stacks.
 * The function does not return any value.
 * It modifies the head pointers of both stacks.
 */
void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rr(stack_a, stack_b, true);
	current_index(*stack_a);
	current_index(*stack_b);
}
