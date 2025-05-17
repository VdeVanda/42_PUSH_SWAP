/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:56:34 by vabatist          #+#    #+#             */
/*   Updated: 2025/05/17 12:32:26 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/**
 * Prints a double array of strings.
 * It iterates through the array
 * and prints each string followed by a newline.
 * If the array is NULL, it does nothing.
 * The function does not return any value.
 */
void	print_double_array(char *array[])
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}

/**
 * Writes an error message to the standard error output.
 * It prints "Error\n" and exits the program with a status of 1.
 * The function does not return any value.
 */
void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * Returns the length of the stack.
 * It iterates through the stack
 * and counts the number of nodes.
 * If the stack is empty, it returns 0.
 * The function does not modify the stack.
 */
void	print_stack(t_node *stack)
{
	t_node	*temp;

	if (!stack)
	{
		ft_printf("stack is empty.\n");
		return ;
	}
	temp = stack;
	while (temp)
	{
		ft_printf(" Data: %d\n", temp->data);
		temp = temp->next;
	}
}

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
