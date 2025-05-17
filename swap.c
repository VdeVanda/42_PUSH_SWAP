/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:55:47 by vabatist          #+#    #+#             */
/*   Updated: 2025/05/17 12:28:59 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Swaps the first two elements of the stack.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If the stack is empty or has only one element,
 * the function does nothing.
 * The function does not return any value.
 * It modifies the head pointer of the stack.
 */
static void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!head || !(*head) || !((*head)->next))
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	*head = second;
}

/**
 * Swaps the first two elements of stack A.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If stack A is empty or has only one element,
 * the function does nothing.
 * The function prints "sa" if the print parameter is true.
 * It returns nothing.
 */
void	sa(t_node **head, bool print)
{
	swap(head);
	if (print == true)
		ft_printf("sa\n");
}

/**
 * Swaps the first two elements of stack B.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If stack B is empty or has only one element,
 * the function does nothing.
 * The function prints "sb" if the print parameter is true.
 * It returns nothing.
 */
void	sb(t_node **head, bool print)
{
	swap(head);
	if (print == true)
		ft_printf("sb\n");
}

/**
 * Swaps the first two elements of both stacks A and B.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If either stack A or stack B is empty or has only one element,
 * the function does nothing.
 * The function prints "ss" if the print parameter is true.
 * It returns nothing.
 */
void	ss(t_node **headA, t_node **headB, bool print)
{
	swap(headA);
	swap(headB);
	if (print == true)
		ft_printf("ss\n");
}
