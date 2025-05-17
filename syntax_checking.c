/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:56:10 by vabatist          #+#    #+#             */
/*   Updated: 2025/05/17 12:31:05 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the string is a valid integer.
 * It checks for leading '+' or '-'
 * and ensures that the rest of the string
 * contains only digits.
 * If the string is not a valid integer,
 * it returns -1.
 * Otherwise, it returns 0.
 * The function does not modify the string.
 * It assumes that the string is null-terminated.
 * The function does not check for overflow or underflow.
 * It only checks for valid characters.
 * If the string is empty,
 * it returns -1.
 * If the string contains only whitespace,
 * it returns -1.
 * If the string contains only '+' or '-',
 * it returns -1.
 * If the string contains only digits,
 * it returns 0.
 * If the string contains a mix of digits and other characters,
 * it returns -1.
 * If the string contains a mix of '+' or '-' and digits,
 * it returns -1.
 * If the string contains a mix of '+' or '-' and other characters,
 * it returns -1.
 * If the string contains a mix of digits and other characters,
 * it returns -1.
 * If the string contains a mix of digits and whitespace,
 * it returns -1.
 * If the string contains a mix of '+' or '-' and whitespace,
 * it returns -1.
 * If the string contains a mix of digits and '+' or '-',
 * it returns -1.
 * If the string contains a mix of digits and whitespace,
 * it returns -1.
 */
static int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (-1);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

/**
 * Checks if the number is already in the list.
 * It iterates through the list
 * and compares each node's data with the given number.
 * If a duplicate is found, it returns -1.
 * Otherwise, it returns 0.
 * The function does not modify the list.
 * It assumes that the list is not empty.
 * If the list is empty, it returns 0.
 * If the list contains only one node,
 * it returns 0 if the number is not equal to the node's data.
 * If the list contains multiple nodes,
 * it returns 0 if the number is not equal to any of the nodes' data.
 */
static int	check_duplicate(t_node *head, int num)
{
	t_node	*current;

	current = head;
	while (current)
	{
		if (current->data == num)
			return (-1);
		current = current->next;
	}
	return (0);
}

/**
 * Processes the number string.
 * It checks if the string is a valid integer
 * and converts it to an integer.
 * It checks for duplicates in the list.
 * If any of these checks fail,
 * it returns -1.
 * Otherwise, it adds the number to the list
 * and returns 0.
 * The function does not modify the string.
 * It assumes that the string is null-terminated.
 * The function does not check for overflow or underflow.
 * It only checks for valid characters.
 */
static int	process_number(char **all_str, char *str, t_node **head)
{
	int	num;

	if (is_digit_str(str) == -1)
	{
		return (-1);
	}
	num = ft_safe_atoi(*head, all_str, str);
	if (check_duplicate(*head, num) == -1)
		return (-1);
	if (add_to_list(head, num) == -1)
		return (-1);
	return (0);
}

/**
 * Processes the split array of strings.
 * It iterates through the array
 * and processes each string using process_number.
 * If any of the strings fail to process,
 * it returns -1.
 * Otherwise, it returns 0.
 * The function does not modify the array.
 * It assumes that the array is null-terminated.
 * The function does not check for overflow or underflow.
 * It only checks for valid characters.
 */
static int	process_split_array(char **split_argv, t_node **head)
{
	int	j;

	j = 0;
	while (split_argv[j])
	{
		if (process_number(split_argv, split_argv[j], head) == -1)
		{
			return (-1);
		}
		j++;
	}
	return (0);
}

/**
 * Converts the command line arguments to a linked list.
 * It iterates through the arguments
 * and splits each argument into separate strings.
 * It processes each string using process_split_array.
 * If any of the strings fail to process,
 * it deletes the list and writes an error message.
 * The function does not modify the arguments.
 * It assumes that the arguments are null-terminated.
 * The function does not check for overflow or underflow.
 * It only checks for valid characters.
 */
void	argv_convert_builder(int argc, char *argv[], t_node **head)
{
	int		i;
	char	**split_argv;

	i = 1;
	while (i < argc)
	{
		split_argv = ft_split(argv[i], ' ');
		if (!split_argv || !split_argv[0])
		{
			if (split_argv)
				free_double_array(split_argv);
			deletlist(*head);
			write_error();
		}
		if (process_split_array(split_argv, head) == -1)
		{
			deletlist(*head);
			free_double_array(split_argv);
			write_error();
		}
		free_double_array(split_argv);
		i++;
	}
}
