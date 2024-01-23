/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:14:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/23 07:02:20 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wipe(t_stack **a, t_stack **b)
{
	clear_stack(a);
	clear_stack(b);
	display_colored("Error\n", RED, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	stack_is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current && (*current).next)
	{
		if ((*current).value > (*(*current).next).value)
			return (0);
		current = (*current).next;
	}
	return (1);
}

void	setup_stack(t_stack **stack, char **argv, int argc)
{
	int	nbr;
	int	has_error;

	has_error = 0;
	while (1 < argc--)
	{
		validate_syntax(*(argv + argc), &has_error);
		nbr = ft_atoi(*(argv + argc), &has_error);
		search_for_duplicate(*stack, nbr, &has_error);
		push(stack, nbr);
		if (has_error || !*stack)
			wipe(stack, NULL);
	}
}
