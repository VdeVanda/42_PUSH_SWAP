/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:15:40 by vabatist          #+#    #+#             */
/*   Updated: 2025/06/04 15:04:56 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Creates the stack_a from the command line arguments.
 * It converts the arguments to integers
 * and adds them to the stack.
 * If the conversion fails,
 * it deletes the list and frees the strings.
 * If the stack is empty,
 * it writes an error message and returns NULL.
 * Returns the head of the stack.
 * If the stack is empty, it returns NULL.
 */
t_node	*create_stacka(int argc, char *argv[])
{
	t_node	*head;

	head = NULL;
	argv_convert_builder(argc, argv, &head);
	if (!head)
		write_error();
	return (head);
}

/**
 * Creates an empty stack.
 * It initializes the stack pointer to NULL.
 * Returns the head of the stack.
 */
t_node	*create_empty_stack(void)
{
	t_node	*stackb;

	stackb = NULL;
	return (stackb);
}

/**
 * Writes an error message to the standard error output.
 * It prints "Error\n" and exits the program with a status of 1,
 * indicating that an error has occurred.
 * The function does not return any value.
 */
void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * It initializes the stacks and checks for errors.
 * It creates stack_a from the command line arguments
 * and creates an empty stack_b.
 * It checks if the stacks are sorted.
 * If stack_a is not sorted,
 * it sorts the stacks using the appropriate sorting algorithm.
 * If stack_a has 2 elements, it swaps them.
 * If stack_a has 3 elements, it sorts them using the sort_three function.
 * If stack_a has more than 3 elements, 
 * it sorts them using the sort_stacks function.
 * It deletes the stacks after sorting.
 * It returns 0 on success and 1 on failure.
 */
int	main(int argc, char *argv[])
{
	t_node	*stacka;
	t_node	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	stacka = create_stacka(argc, argv);
	stackb = create_empty_stack();
	if (!is_sorted(stacka))
	{
		if (stacklen(stacka) == 2)
		{
			sa(&stacka, true);
		}
		else if (stacklen(stacka) == 3)
		{
			sort_three(&stacka);
		}
		else
			sort_stacks(&stacka, &stackb);
	}
	deletlist(stacka);
	deletlist(stackb);
	return (0);
}
