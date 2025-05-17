/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:52:22 by vabatist          #+#    #+#             */
/*   Updated: 2025/05/17 12:22:04 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *	Pushes the top element of the source stack to the destination stack.
 *	The function updates the next and prev pointers of the nodes
 *	to maintain the doubly linked list structure.
 *	If the source stack is empty, the function does nothing.
 *	If the destination stack is empty, the function sets the new node
 *	as the head of the destination stack.
 *	If the destination stack is not empty, the function sets the new node
 *	as the new head of the destination stack and updates the prev pointer
 *	of the old head of the destination stack.
 */
static void	push(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (!src || !(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->next = *dest;
	if (*dest)
		(*dest)->prev = temp;
	*dest = temp;
}

/**
 * Pushes the top element of stack A to stack B.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If stack A is empty, the function does nothing.
 * If stack B is empty, the function sets the new node
 * as the head of stack B.
 * If stack B is not empty, the function sets the new node
 * as the new head of stack B
 * and updates the prev pointer
 * of the old head of stack B.
 * The function also prints "pa" if the print parameter is true.
 * It returns nothing.
 */
void	pa(t_node **headA, t_node **headB, bool print)
{
	push(headA, headB);
	if (print == true)
		ft_printf("pa\n");
}

/**
 * Pushes the top element of stack B to stack A.
 * It updates the next and prev pointers of the nodes
 * to maintain the doubly linked list structure.
 * If stack B is empty, the function does nothing.
 * If stack A is empty, the function sets the new node
 * as the head of stack A.
 * If stack A is not empty, the function sets the new node
 * as the new head of stack A
 * and updates the prev pointer
 * of the old head of stack A.
 * The function also prints "pb" if the print parameter is true.
 * It returns nothing.
 */
void	pb(t_node **headA, t_node **headB, bool print)
{
	push(headB, headA);
	if (print == true)
		ft_printf("pb\n");
}
