/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:14:41 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/23 07:24:11 by sguzman          ###   ########.fr       */
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

int	find_prev(t_stack **a, t_stack **b, int value)
{
	t_stack	*current;
	t_stack	*copy;
	int		prev;

	copy = copy_stack(*b);
	if (!copy)
		wipe(a, b);
	push(&copy, value);
	if (!copy)
		wipe(a, b);
	bubble_sort(copy);
	current = copy;
	while ((*current).next && (*(*current).next).value != value)
		current = (*current).next;
	prev = (*current).value;
	clear_stack(&copy);
	return (prev);
}

int	find_following(t_stack **a, t_stack **b, int value)
{
	t_stack	*current;
	t_stack	*copy;
	int		follow;

	copy = copy_stack(*a);
	if (!copy)
		wipe(a, b);
	push(&copy, value);
	if (!copy)
		wipe(a, b);
	bubble_sort(copy);
	current = copy;
	while ((*current).value != value)
		current = (*current).next;
	if ((*current).next)
		follow = (*(*current).next).value;
	else
		follow = (*minimum(*a)).value;
	clear_stack(&copy);
	return (follow);
}
