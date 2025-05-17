/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:49:07 by vabatist          #+#    #+#             */
/*   Updated: 2025/05/17 11:41:40 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Finds the minimum value in the stack.
 */
t_node	*find_min(t_node *stack)
{
	int		min;
	t_node	*min_node;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

/**
 * Finds the maximum value in the stack.
 */
t_node	*find_max(t_node *stack)
{
	int		max;
	t_node	*max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

/**
 * Checks if the string is empty after trimming.
 * If it is empty, it deletes the list and frees the strings.
 * It also checks for invalid characters.
 * If any invalid characters are found, it deletes the list and frees the strings.
 * If the string is valid, it continues to check for empty strings.
 * If any empty strings are found, it deletes the list and frees the strings.
 * Finally, it checks if the number is within the limits of an integer.
 * If it exceeds the limits, it deletes the list and frees the strings.
 * If the conversion fails, it deletes the list and frees the strings.
 * Returns the converted integer.
 */
static void	check_empty_str(t_node *head, char **all_str, char *str, int i)
{
	if (!str[i])
	{
		deletlist(head);
		free_double_array(all_str);
		write_error();
	}
}

/**
 * Checks if the number is within the limits of an integer.
 * If it exceeds the limits, it deletes the list and frees the strings.
 */
static void	check_num_limits(long num, int neg, t_node *head, char **all_str)
{
	if (num * neg > INT_MAX || num * neg < INT_MIN)
	{
		deletlist(head);
		free_double_array(all_str);
		write_error();
	}
}

/**
 * Converts a string to an integer safely.
 * It checks for empty strings and number limits.
 * If the conversion fails, it deletes the list and frees the strings.
 * Returns the converted integer.
 */
int	ft_safe_atoi(t_node *head, char **all_str, char *str)
{
	int		i;
	int		neg;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	check_empty_str(head, all_str, str, i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (str[i] - '0') + (num * 10);
		check_num_limits(num, neg, head, all_str);
		i++;
	}
	return (num * neg);
}
