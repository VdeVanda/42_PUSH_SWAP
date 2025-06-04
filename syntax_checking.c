/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:56:10 by vabatist          #+#    #+#             */
/*   Updated: 2025/06/04 12:27:48 by vabatist         ###   ########.fr       */
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
