/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:13:33 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/19 13:18:24 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of(t_stack *stack, int wanted)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = stack;
	while (current)
	{
		if ((*current).value == wanted)
			break ;
		current = (*current).next;
		index++;
	}
	return (index);
}

int	sorted_value_at(t_stack **a, t_stack **b, int index)
{
	t_stack	*current;
	t_stack	*copy;
	int		value;

	copy = copy_stack(*a);
	if (!copy)
		wipe(a, b);
	bubble_sort(copy);
	current = copy;
	while ((*current).next && index--)
		current = (*current).next;
	value = (*current).value;
	clear_stack(&copy);
	return (value);
}

void	cheaper_move_to_top(t_stack **a, t_stack **b, int chunk)
{
	t_stack	*max;
	int		min_distance;
	int		value;

	min_distance = size(a);
	while (chunk--)
	{
		value = sorted_value_at(a, b, chunk);
		if (index_of(*a, value) < min_distance)
			min_distance = index_of(*a, value);
	}
	max = maximum(*b);
	while (min_distance--)
		if (*b != max)
			perform_and_log(a, b, RR);
		else
			perform_and_log(a, b, RA);
	while (*b != max)
	{
		if ((size(b) / 2) < index_of(*b, (*max).value))
			perform_and_log(a, b, RRB);
		else
			perform_and_log(a, b, RB);
	}
}

void	smash_sort(t_stack **a, t_stack **b, int chunk)
{
	t_stack	*max;

	while (*a)
	{
		cheaper_move_to_top(a, b, chunk);
		perform_and_log(a, b, PB);
	}
	while (*b)
	{
		max = maximum(*b);
		while (*b != max)
		{
			if ((size(b) / 2) < index_of(*b, (*max).value))
				perform_and_log(a, b, RRB);
			else
				perform_and_log(a, b, RB);
		}
		perform_and_log(a, b, PA);
	}
}
