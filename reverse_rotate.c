/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:53:21 by vabatist          #+#    #+#             */
/*   Updated: 2025/05/17 12:26:43 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Reverses the order of the elements in the stack.
 * It moves the last element to the front of the stack.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If the stack is empty or has only one element,
 * the function does nothing.
 * The function does not return any value.
 * It modifies the head pointer of the stack.
 */
static void	reverse_rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !(*head) || !((*head)->next))
		return ;
	first = *head;
	while (first->next)
		first = first->next;
	last = first;
	first = *head;
	*head = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
}

/**
 * Reverses the order of the elements in stack A.
 * It moves the last element to the front of stack A.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If the stack is empty or has only one element,
 * the function does nothing.
 * The function prints "rra" if the print parameter is true.
 * It returns nothing.
 */
void	rra(t_node **head, bool print)
{
	reverse_rotate(head);
	if (print == true)
		ft_printf("rra\n");
}

/**
 * Reverses the order of the elements in stack B.
 * It moves the last element to the front of stack B.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If the stack is empty or has only one element,
 * the function does nothing.
 * The function prints "rrb" if the print parameter is true.
 * It returns nothing.
 */
void	rrb(t_node **head, bool print)
{
	reverse_rotate(head);
	if (print == true)
		ft_printf("rrb\n");
}

/**
 * Reverses the order of the elements in both stacks A and B.
 * It moves the last element of each stack to the front of the respective stack.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If either stack is empty or has only one element,
 * the function does nothing.
 * The function prints "rrr" if the print parameter is true.
 * It returns nothing.
 */
void	rrr(t_node **headA, t_node **headB, bool print)
{
	reverse_rotate(headA);
	reverse_rotate(headB);
	if (print == true)
		ft_printf("rrr\n");
}

/**
 * Reverses the order of the elements in both stacks A and B
 * until the cheapest node
 * is at the top of both stacks.
 * It moves the last element of each stack
 * to the front of the respective stack.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If either stack is empty or has only one element,
 * the function does nothing.
 * The function does not print anything.
 * It returns nothing.
 * The function modifies the head pointers of both stacks.
 */
void	reverse_rotate_both(t_node **stack_a, t_node **stack_b,
		t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rrr(stack_a, stack_b, true);
	current_index(*stack_a);
	current_index(*stack_b);
}
