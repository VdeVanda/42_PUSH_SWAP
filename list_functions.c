/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:50:47 by vabatist          #+#    #+#             */
/*   Updated: 2025/06/04 12:31:26 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Finds the last node in the stack.
 * It iterates through the stack
 * until it finds the last node (the one with next == NULL).
 * If the stack is empty, it returns NULL.
 * If the stack is not empty, it returns the last node.
 */
static t_node	*find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/**
 * Adds a new node to the end of the stack.
 * It creates a new node with the given value
 * and sets its next and prev pointers accordingly.
 * If the stack is empty,
 * it sets the new node as the head of the stack.
 * If the stack is not empty,
 * it finds the last node and sets its next pointer to the new node.
 * It also sets the new node's prev pointer to the last node.
 * Returns 0 on success, or -1 if memory allocation fails.
 */
int	add_to_list(t_node **head, int value)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (-1);
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->above_median = false;
	new_node->cheapest = false;
	new_node->target_node = NULL;
	if (!*head)
		*head = new_node;
	else
	{
		last_node = find_last(*head);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	return (0);
}

/**
 * Deletes the entire list.
 * It iterates through the list
 * and frees each node.
 */
void	deletlist(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * Counts the number of nodes in the stack.
 * It iterates through the stack
 * and increments a counter for each node.
 */
int	stacklen(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

/**
 * Frees a double array of strings.
 * It iterates through the array
 * and frees each string.
 * It then frees the array itself.
 * If the array is NULL, it does nothing.
 * The function does not return any value.
 */
void	free_double_array(char *array[])
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}
