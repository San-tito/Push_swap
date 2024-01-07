/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:13:33 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/07 19:59:51 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_stack *stack, t_stack *wanted)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = stack;
	while (current)
	{
		if (current == wanted)
			break ;
		current = (*current).next;
		index++;
	}
	return (index);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min;

	current = stack;
	min = current;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*current;

	max = stack;
	current = (*stack).next;
	while (current)
	{
		if ((*stack).value < (*max).value)
			max = current;
		current = (*current).next;
	}
	return (max);
}

void	insertion_sort(t_stack **a, t_stack **b)
{
	t_stack	*min;

	// int		chunk_size;
	// chunk_size = 20 + ((size(a) - 100) / 16);
	while (!stack_is_sorted(*a))
	{
		min = find_min(*a);
		while (*a != min)
		{
			if ((size(a) / 2) < get_index(*a, min))
				perform_and_log(a, b, RRA);
			else
				perform_and_log(a, b, RA);
		}
		perform_and_log(a, b, PB);
	}
	while (*b)
		perform_and_log(a, b, PA);
}
